#ifndef __PROTOCOL_UTIL_HPP__
#define __PROTOCOL_UTIL_HPP__

#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <sstream>
#include <unordered_map>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/sendfile.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include "Log.hpp"

#define NOT_FOUND 404
#define OK 200
#define WEB_ROOT "wwwroot"
#define HOME_PARG "index.html"

#define HTTP_VERSION "http/1.0"

std::unordered_map<std::string, std::string> g_suffix_map
{
    {".html", "text/html"},
    {".htm", "text/html"},
    {".css", "text/css"},
    {".js", "application/x-javascript"},
};

class ProtocolUtil
{
public:
    static void MakeKV(std::unordered_map<std::string, std::string>& kv, std::string& str)
    {
        std::size_t pos = str.find(": ");
        if (std::string::npos == pos)
        {
            return;
        }
        std::string k = str.substr(0, pos);
        std::string v = str.substr(pos+2);

        kv.insert(make_pair(k, v));
    }

    static std::string IntToString(int& code)
    {
        std::stringstream ss;
        ss << code;
        return ss.str();
    }

    static std::string CodeToDesc(int code)
    {
        switch (code)
        {
            case 200:
                return "OK";
            case 404:
                return "NOT_FOUND";
            default:
                return "UNKNOW";
        }
    }

    static std::string SuffixToType(const std::string& suffix)
    {
        return g_suffix_map[suffix];
    }
};


class Request
{
public:
    Request()
        : m_response_blank("\n")
        , m_cgi(false)
        , m_path(WEB_ROOT)
        , m_resource_size(0)
        , m_content_length(-1)
        , m_resource_suffix(".html")
    {}

    int GetResourceSize()
    {
        return m_resource_size;
    }

    std::string& GetParam()
    {
        return m_param;
    }

    std::string& GetSuffix()
    {
        return m_resource_suffix;
    }

    std::string& GetPath()
    {
        return m_path;
    }
    void RequestLineParse()
    {
        std::stringstream ss(m_request_line);
        ss >> m_method >> m_uri >> m_version;
    }

    void UriParse()
    {
        if (strcasecmp(m_method.c_str(), "GET"))
        {
            std::size_t pos = m_uri.find('?');
            if (std::string::npos != pos)
            {
                m_cgi = true;
                m_path += m_uri.substr(0, pos);
                m_param = m_uri.substr(pos+1);
            }
            else 
            {
                m_path += m_uri;
            }
        }
        else 
        {
            m_path += m_uri;
        }
        if (m_path[m_path.size()-1] == '/')
        {
            m_path += HOME_PARG;
        }
    }

    int GetContentLength()
    {
        std::string cl = m_head_kv["content-length"];
        if (!cl.empty())
        {
            std::stringstream ss(cl);
            ss >> m_content_length;
        }
        return m_content_length;
    }

    bool IsMethodLegal()
    {
        if (strcasecmp(m_method.c_str(), "GET") == 0 ||\
           (m_cgi = (strcasecmp(m_method.c_str(), "POST")) == 0))
        {
            return true;
        }
        return false;
    }

    bool RequestHeadParse()
    {
        int start = 0;
        while (start < m_request_head.size())
        {
            std::size_t pos = m_request_head.find('\n', start);
            if (std::string::npos == pos)
            {
                break;
            }
            std::string sub_string = m_request_head.substr(start, pos-start);
            if (!sub_string.empty())
            {
                LOG(INFO, "Substr is not empty!");
                ProtocolUtil::MakeKV(m_head_kv, sub_string);
            }
            else 
            {
                LOG(INFO, "Substr is empty!");
                break;
            }
            start = pos + 1;
        }
        return true;
    }

    bool IsPathLegal()
    {
        struct stat st;
        if (stat(m_path.c_str(), &st) < 0)
        {
            LOG(WARING, "Path not Found!");
            return false;
        }
        if (S_ISDIR(st.st_mode))
        {
            m_path += '/';
            m_path += HOME_PARG;
        }
        else 
        {
            if ((st.st_mode & S_IXUSR) || \
                (st.st_mode & S_IXGRP) || \
                (st.st_mode & S_IXOTH))
            {
                m_cgi = true;
            }
        }
        m_resource_size = st.st_size;
        std::size_t pos = m_path.rfind(".");
        if (std::string::npos != pos)
        {
            m_resource_suffix = m_path.substr(pos);
        }
        return true;
    }

    bool IsNeedRecvText()
    {
        if (strcasecmp(m_method.c_str(), "POST") == 0)
        {
            return true;
        }
        return false;
    }

    bool IsCgi()
    {
        return m_cgi;
    }

    ~Request()
    {}
public:
    std::string m_request_line;
    std::string m_request_head;
    std::string m_response_blank;
    std::string m_request_text;
private:
    std::string m_method;
    std::string m_uri;
    std::string m_version;
    bool m_cgi;

    std::string m_path;
    std::string m_param;

    int m_resource_size; 
    int m_content_length;
    std::string m_resource_suffix;
    std::unordered_map<std::string, std::string> m_head_kv;
};

class Response
{
public:
    Response()
        : m_response_blank("\n")
        , m_code(OK)
        , m_fd(-1)
    {}

    void MakeStatusLine()
    {
        m_response_line = HTTP_VERSION;
        m_response_line += " ";
        m_response_line += ProtocolUtil::IntToString(m_code);
        m_response_line += " ";
        m_response_line += ProtocolUtil::CodeToDesc(m_code);
        m_response_line += "\n";
    }


    void MakeResponseHead(Request*& req)
    {
        m_response_head = "Content-Length: ";
        int temp = req->GetResourceSize();
        m_response_head += (ProtocolUtil::IntToString(temp));
        m_response_head += "\n";
        m_response_head += "Content-Type: ";
        std::string suffix = req->GetSuffix();
        m_response_head += ProtocolUtil::SuffixToType(suffix);
        m_response_head += "\n";
    }

    void OpenResource(Request*& req)
    {
        std::string path = req->GetPath();
        m_fd = open(path.c_str(), O_RDONLY);
    }

    ~Response()
    {
        if (m_fd >= 0)
        {
            close(m_fd);
        }
    }

public:
    int m_code;
    int m_fd;
    std::string m_response_line;
    std::string m_response_head;
    std::string m_response_blank;
    std::string m_response_text;
};

class Connect
{
public:
    Connect(int sock)
        : m_sock(sock)
    {}

    int RecvOneLine(std::string& line)
    {
        char c = 'X';
        while (c != '\n')
        {
            ssize_t s = recv(m_sock, &c, 1, 0);
            if (s > 0)
            {
                if (c == '\r')
                {
                    recv(m_sock, &c, 1, MSG_PEEK);
                    if (c == '\n')
                    {
                        recv(m_sock, &c, 1, 0);
                    }
                    else 
                    {
                        c = '\n';
                    }
                }
                line.push_back(c);
            }
            else 
            {
                break;
            }
        }
        return line.size();
    }

    void RecvRequestHead(std::string& head)
    {
        head = "";
        std::string line;
        while (line != "\n")
        {
            line = "";
            RecvOneLine(line);
            head += line;
        }
    }

    void RecvRequestText(std::string text, int len, std::string& param)
    {
        char c;
        int i = 0;
        while (i < len)
        {
            recv(m_sock, &c, 1, 0);
            text.push_back(c);
        }
        param = text;
    }

    void SendResponse(Response*& rsp, Request*& req, bool cgi)
    {
        if (cgi)
        {
        }
        else 
        {
            std::string& rsp_line = rsp->m_response_line;
            std::string& rsp_head = rsp->m_response_head;
            std::string& rsp_blank = rsp->m_response_blank;
            int& fd = rsp->m_fd;
            send(m_sock, rsp_line.c_str(), rsp_line.size(), 0);
            send(m_sock, rsp_head.c_str(), rsp_head.size(), 0);
            send(m_sock, rsp_blank.c_str(), rsp_blank.size(), 0);
            sendfile(m_sock, fd, NULL, req->GetResourceSize());
        }
    }

    ~Connect()
    {
        if (m_sock >= 0)
        {
            close(m_sock);
        }
    }
private:
    int m_sock;
};


class Entry
{
public:
    static int ProcessNonCgi(Connect*& conn, Request*& req, Response*& rsp)
    {
        int &code = rsp->m_code;
        rsp->MakeStatusLine();
        rsp->MakeResponseHead(req);
        rsp->OpenResource(req);
        conn->SendResponse(rsp, req, false);
    }
    static int ProcessRespomse(Connect*& conn, Request*& req, Response*& rsp)
    {
        if (req->IsCgi())
        {
            //TODO
            //ProcessCgi();
        }
        else 
        {
            ProcessNonCgi(conn, req, rsp);
        }
    }
    static void* HanderRequest(void* arg)
    {
        int sock = *(int*)arg;
        delete (int*)arg;
        Connect* conn = new Connect(sock);
        Request* req = new Request();
        Response* rsp = new Response();

        int& code = rsp->m_code;

        conn->RecvOneLine(req->m_request_line);
        std::cout << req->m_request_line << std::endl;
        req->RequestLineParse();
        if (!req->IsMethodLegal())
        {
            code = NOT_FOUND;
            goto end;
        }

        req->UriParse();
        if (!req->IsPathLegal())
        {
            code = NOT_FOUND;
            goto end;
        }
        LOG(INFO, "request path is ok!");

        conn->RecvRequestHead(req->m_request_head);
        if (req->RequestHeadParse())
        {
            LOG(INFO, "Parse head done!");
        }
        else 
        {
            code = NOT_FOUND;
            goto end;
        }

        if (req->IsNeedRecvText())
        {
            conn->RecvRequestText(req->m_request_text, req->GetContentLength(), req->GetParam());
        }

        ProcessRespomse(conn, req, rsp);

end:
        if (code != OK)
        {
            //TODO
            //HandlerError(sock);
        }


        delete conn;
        delete req;
        delete rsp;
    }

private:
};
#endif
