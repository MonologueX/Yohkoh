#pragma once 

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <fstream>
#include <rpc_client.hpp>

#include "console_game.hpp"
#include "codec.h"
using namespace std::chrono_literals;
using namespace rest_rpc;
using namespace rest_rpc::rpc_service;

#define SIZE 15

///////////////////////////////////////////////
//  RPC 
///////////////////////////////////////////////
// 注册
uint32_t Register(const std::string& ip, const int& port, std::string& name, std::string& password, uint32_t& id)
{
    std::cout << "请输入昵称:";
    std::cin >> name;
    std::cout << "请设置密码:";
    std::cin >> password;
    std::string m_password;
    std::cout << "确认密码:";
    std::cin >> m_password;
    if (password != m_password)
    {
        std::cout << "Password Is Not Same" <<std::endl;
        return 1;
    }
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 2;
        }
        id = client.call<uint32_t>("RpcRegister", name, password);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return id;
}

// 登录
int Login(const std::string& ip, const int& port)
{
    uint32_t id;
    std::string password;
    std::cout << "请输入你的登录ID:";
    std::cin >> id;
    std::cout << "请输入你的登录密码:";
    std::cin >> password;
    uint32_t result = 0;
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        result = client.call<uint32_t>("RpcLogin", id, password);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}

// 入匹配池
bool PushMatchPool(std::string& ip, int& port, uint32_t& id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        std::cout << "Match id" << id << std::endl;
        return client.call<bool>("RpcMatchAndWait", id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 检查
int CheckReady(std::string& ip, int& port, uint32_t& id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<int>("RpcPlayerReady", id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 获得棋盘
int GetBoard(std::string& ip, int& port, uint32_t& room_id, std::string& board)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        board = client.call<std::string>("RpcBoard", room_id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 获得房间Id
uint32_t GetMyRoomId(std::string& ip, int& port, uint32_t& id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<uint32_t>("RpcPlayerRoomId", id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 获得棋子
char GetMyPiece(std::string& ip, int& port, uint32_t& room_id, uint32_t& id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<char>("RpcPlayerPiece", room_id, id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 该谁落子
bool IsMyTurn(std::string& ip, int& port, uint32_t& room_id, uint32_t& id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<bool>("RpcIsMyTurn", room_id, id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 能否落子
int Step(std::string& ip, int& port, uint32_t& room_id, uint32_t& id, int& x, int& y)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<bool>("RpcStep", room_id, id, x - 1, y - 1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// 判断
char Judge(std::string& ip, int& port, uint32_t& room_id)
{
    try 
    {
        rpc_client client(ip, port);
        bool r = client.connect();
        if (!r)
        {
            std::cout << "connect timeout" << std::endl;
            return 3;
        }
        return client.call<char>("RpcJudge", room_id);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

///////////////////////////////////////////////
//  本地
///////////////////////////////////////////////
// 匹配
bool Match(std::string& ip, int& port, uint32_t& id)
{
    PushMatchPool(ip, port, id);
    int i = 0;
    char bar[101];
    const char *lable = "|/-\\";

    for (i = 0; i <= 100; i++)
    {
        int result = CheckReady(ip, port, id);
        if (result == 3)
        {
            return true;
        }
        else if (result == 1)
        {
            return false;
        }
        else 
        {
            bar[i] = '\0';
            if (i < 40)
                printf("\033[1;31;44m%s\033[0m [%d%%][%c]\r", bar, i, lable[i % 4]);
            else if (i < 80)
                printf("\033[1;31;43m%s\033[0m [%d%%][%c]\r", bar, i, lable[i % 4]);
            else
                printf("\033[1;31;41m%s\033[0m [%d%%][%c]\r", bar, i, lable[i % 4]);
            fflush(stdout);
            bar[i] = ' ';
            usleep(100000);
        }
    }
    std::cout << std::endl;
    return false;
}

// 打印棋盘
void ShowBoard(std::string& board)
{
	int i = 0, j = 0, k = 0;
	printf("    Y--------------------------->\n");
	printf("    ");
	for (k = 0; k < SIZE; k++)
	{
		if (k >= 0 && k <= 8)
			printf("%d ", k + 1);
		else
			printf("%d", k + 1);
	}
	putchar('\n');
	for (i = 0; i < 15; i++)
	{
		printf("X");
		if (i >= 0 && i <= 8)
			printf("0%d ", i + 1);
		else
			printf("%d ", i + 1);
		for (j = 0; j < 15; j++)
		{
            putchar(board[i*15+j]);
			if (j<(15 - 1))
				putchar('-');
		}
		putchar('\n');
	}
}

// 落子是否正确
bool PostIsRight(std::string& board, int x, int y)
{
    int pos = (x-1)*15+(y-1);
    return board[pos] == '+' ? true : false;
}

// 玩游戏
void PlayGame(std::string& ip, int& port, uint32_t& id)
{
    int x, y;
    char result = 'N';
    std::string board;
    uint32_t room_id = GetMyRoomId(ip, port, id);
    std::cout << "room_id:" << room_id << std::endl;
    char piece = GetMyPiece(ip, port, room_id, id);
    std::cout << "piece:" << piece << std::endl;
    for ( ; ; )
    {
        system("clear");
        GetBoard(ip, port, room_id, board);
        ShowBoard(board);
        if (result = Judge(ip, port ,room_id) != 'N')
        {
            break;
        }
        if (!IsMyTurn(ip, port, room_id, id))
        {
            std::cout << "对方正在思考，请稍等!";
            sleep(1);
            continue;
        }
        std::cout << "请输入你落子位置:";
        std::cin >> x >> y;
        system("clear");
        if (x >= 1 && x <= 15 && y >= 1 && y <= 15)
        {
            if (!PostIsRight(board, x, y))
            {
                std::cout << "该位置已经被占用，请重新输入>" <<std::endl;
            }
            else 
            {
                Step(ip, port, room_id, id, x, y);
                result = Judge(ip, port, room_id);
                if (result != 'N')
                {
                    break;
                }
            }
        }
        else 
        {
            std::cout << "你输入的位置有误，请重新输入>" << std::endl;
        }
    }
    system("clear");
    GetBoard(ip, port, room_id, board);
    ShowBoard(board);
    if (result == 'E')
    {
        std::cout << "平局" << std::endl;
    }
    else if (result == piece)
    {
        std::cout << "恭喜你，你赢了！" << std::endl;
    }
    else 
    {
        std::cout << "很遗憾，你输了！" << std::endl;
    }
}

void Game(std::string& ip, int& port, uint32_t& id)
{
    int select = 0;
    volatile bool quit = false;
    while (!quit)
    {
        printf("==============欢迎进入五子棋小游戏==============\n");
        printf("\t=======请选择功能列表=======\n");
        printf("\t\t1.开始匹配\n");
        printf("\t\t2.单机游戏\n");
        printf("\t\t0.退出游戏\n");
        printf("请选择>");
        std::cin >> select;
        system("clear");
        switch (select)
        {
            case 1:
                {
                    if (Match(ip, port, id))
                    {
                        PlayGame(ip, port, id);
                    }
                    else 
                    {
                        //std::cout << "匹配失败！" << std::endl;
                        ConsoleGame g;
                        g.Game();
                    }
                }
                break;
            case 2:
                {
                    ConsoleGame g;
                    g.Play();
                }
                break;
            case 0:
                quit = true;
                break;
            default:
                std::cout << "选择错误，请重新选择！" << std::endl;
                break;
        }
    }
}
