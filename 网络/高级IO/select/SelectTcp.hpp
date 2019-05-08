#pragma once 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define DEFAULT_FD -1

using namespace std;

class Server
{
public:
    Server(const int& port)
        : m_port(port)
    {}

    void ServerInit()
    {
        m_cap = sizeof(fd_set)*8;
        m_fd_array.resize(m_cap, DEFAULT_FD);
        m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (m_listen_sock < 0)
        {
            cerr << "socket error" << endl;
            exit(2);
        }

        int opt = 1;
        setsockopt(m_listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        struct sockaddr_in local;
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = htonl(INADDR_ANY);
        local.sin_port = htons(m_port);
        if (bind(m_listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            cerr << "bind error" << endl;
            exit(3);
        }
        if (listen(m_listen_sock, 5) < 0)
        {
            cerr << "listen error" << endl;
            exit(4);
        }
    }

    void Start()
    {
        m_fd_array[0] = m_listen_sock;
        m_size = 1;
        while (1)
        {
            fd_set rfds;
            FD_ZERO(&rfds);
            int max_fd = AddAllFd(m_fd_array, rfds);
            struct timeval timeout = {20, 0};
            switch (select(max_fd+1, &rfds, nullptr, nullptr, &timeout))
            {
                case -1:
                    cerr << "select error" << endl;
                    break;
                case 0:
                    cout << "time out" << endl;
                    break;
                default:
                    {
                        for (auto i = 0; i < m_size; i++)
                        {
                            if ((i == 0) && FD_ISSET(m_fd_array[i], &rfds))
                            {
                                cout << "Get a new connect" << endl;
                                struct sockaddr_in peer;
                                socklen_t len = sizeof(peer);
                                int sock = accept(m_listen_sock, (struct sockaddr*)&peer, &len);
                                if (sock < 0)
                                {
                                    cerr << "accept error" << endl;
                                    continue;
                                    // TODO 
                                }

                                cout << "get a new client, fd is: " << sock << endl;

                                if (!AddFd(sock, m_fd_array))
                                {
                                    cout << "socket full" << endl;
                                    close(sock);
                                }
                            }
                            else if (FD_ISSET(m_fd_array[i], &rfds))
                            {
                                char buf[10240];
                                ssize_t s = recv(m_fd_array[i], buf, sizeof(buf)-1, 0);
                                if (s > 0)
                                {
                                    buf[s] = 0;
                                    cout << buf << endl;
                                }
                                else if (0 == s)
                                {
                                    cout << "client quit" << endl;
                                    close(m_fd_array[i]);
                                    DelFd(i, m_fd_array);
                                }
                                else 
                                {
                                    cerr << "recv error" << endl;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }

    ~Server()
    {}

private:
    int AddAllFd(std::vector<int>fd_array, fd_set& rfds)
    {
        int max = fd_array[0];
        for (auto i = 0; i < m_size; i++)
        {
            if (DEFAULT_FD == fd_array[i])
            {
                continue;
            }
            FD_SET(fd_array[i], &rfds);
            if (max < fd_array[i])
            {
                max = fd_array[i];
            }
        }
        return max;
    }

    bool AddFd(int fd, std::vector<int> fd_array)
    {
        cout << "add fd: " << fd << endl;
        if (m_size < m_cap)
        {
            fd_array[m_size++] = fd;
            cout << "size: " << m_size << "cap: " << m_cap << endl;
            return true;
        }
        return false;
    }

    void DelFd(int index, std::vector<int> fd_array)
    {
        cout << "delete fd : " << fd_array[index] << endl;
        fd_array[index] = fd_array[--m_size];
        fd_array[m_size] = DEFAULT_FD;
        cout << "size: " << m_size << "cap: " << m_cap << endl;
    }

private:
    int m_listen_sock;
    int m_port;
    std::vector<int> m_fd_array;
    int m_cap;
    int m_size;
};
