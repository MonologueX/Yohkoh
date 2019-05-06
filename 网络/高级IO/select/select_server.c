/***********************************
 * 文件名称: select_server.c
 * 文件描述: select 实现高并发 tcp 服务器
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>

int main(int argc, char* argv[])
{
    ///////////////////////////////////////////////
    //  TCP 
    ///////////////////////////////////////////////
    
    int server_sock;
    int client_sock;
    int ret;
    struct sockaddr_in listen_addr;
    struct sockaddr_in client_addr;
    socklen_t len;


    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock < 0)
    {
        perror("sock error!!!");
        return -1;
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    len = sizeof(struct sockaddr_in);
    ret = bind(server_sock, (struct sockaddr*)&listen_addr, len);
    if (ret < 0)
    {
        perror("bind error");
        return -1;
    }

    if (listen (server_sock, 5) < 0)
    {
        perror("listen error");
        return -1;
    }

    ///////////////////////////////////////////////
    //  select
    ///////////////////////////////////////////////
    // 清空集合
    // 添加描述符

    int max_fd;
    fd_set rfds;
    struct timeval tv;
    
    tv.tv_sec = 3;
    tv.tv_usec = 0;

    FD_ZERO(&rfds);
    FD_SET(server_sock, &rfds);
    max_fd = server_sock + 1;
    
    while (1)
    {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &len);
        if (client_sock < 0)
        {
            perror("accept error");
            continue;
        }
    }
    return 0;
}
