#pragma once 

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

class Server
{
public:
    Server(const int& port)
        : m_port(port)
    {}

    void ServerInit()
    {
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
        while (1)
        {
            fd_set rfds;
            FD_ZERO(&rfds);

            FD_SET(m_listen_sock, &rfds);

            int max_fd = m_listen_sock;
            struct timeval timeout = {1, 0};

            switch (select(max_fd+1, &rfds, nullptr, nullptr, &timeout))
            {
                case -1:
                    cerr << "select error" << endl;
                    break;
                case 0:
                    cout << "tmeout" << endl;
                    break;
                default:
                    {
                    }
                    break;
            }
        }
    }

    ~Server()
    {}
private:
    int m_listen_sock;
    int m_port;
};
