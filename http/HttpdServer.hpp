#ifndef __HTTPD_SERVER_HPP__
#define __HTTPD_SERVER_HPP__

#include <pthread.h>
#include "ProtocolUtil.hpp"

class HttpdServer
{
public:
    HttpdServer(int port)
        : m_port(port)
        , m_listen_sock(-1)
    {}

    void InitServer()
    {
        m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (m_listen_sock < 0)
        {
            LOG(ERROR, "create socket error!");
            exit(2);
        }
        int opt = 1;
        setsockopt(m_listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        struct sockaddr_in local;
        local.sin_family = AF_INET;
        local.sin_port = htons(m_port);
        local.sin_addr.s_addr = INADDR_ANY;

        if (bind(m_listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            LOG(ERROR, "bind socket error!");
            exit(3);
        }

        if (listen(m_listen_sock, 5) < 0)
        {
            LOG(ERROR, "listen socket error!");
            exit(4);
        }
        LOG(INFO, "InitServer success!");
    }

    void Start()
    {
        LOG(INFO, "Start Server begin!");
        for (; ; )
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sock = accept(m_listen_sock, (struct sockaddr*)&peer, &len);
            if (sock < 0)
            {
                LOG(WARING, "accept error!");
                continue;
            }

            LOG(INFO, "Get new client, create thread handle request ...");

            pthread_t tid;
            int* sockp = new int;
            *sockp = sock;
            pthread_create(&tid, nullptr, Entry::HanderRequest, (void*)sockp);
        }
    }

    ~HttpdServer()
    {
        if (m_listen_sock != -1)
        {
            close(m_listen_sock);
        }
        m_port = -1;
    }
private:
    int m_port;
    int m_listen_sock;
};
#endif
