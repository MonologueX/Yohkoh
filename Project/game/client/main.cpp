#include "game.hpp"
#include "console_game.hpp"

static void Usage(std::string proc)
{
    system("clear");
    std::cout << "Usage" << proc << "ip port" << std::endl;
    std::cout << "无法连接到服务器，将进行人机版五子棋" << std::endl;
    ConsoleGame g;
    g.Play();
}

static void LoginMenu()
{
    printf("==============欢迎进入五子棋小游戏==============\n");
    printf("\t=======请选择功能列表=======\n");
    printf("\t\t1.单机游戏\n");
    printf("\t\t2.登录\n");
    printf("\t\t3.注册\n");
    printf("\t\t0.退出\n");
    printf("请选择>");
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
    }
    std::string ip = argv[1];
    int port = atoi(argv[2]);

    std::string name;
    std::string password;
    uint32_t id = 0;
    int select = 0;
    while (1)
    {
        LoginMenu();
        std::cin >> select;
        switch (select)
        {
            case 1:
                {
                    ConsoleGame g;
                    g.Game();
                }
                break;
            case 2:
                {
                    system("clear");
                    uint32_t result = Login(ip, port);
                    if (result >= 10000)
                    {
                        id = result;
                        std::cout << "登陆成功！开始游戏吧！" <<std::endl;
                        Game(ip, port, id);
                    }
                    else 
                    {
                        std::cout << "登录失败，退出码:" << result << std::endl;
                    }
                }
                break;
            case 3:
                Register(ip, port, name, password, id);
                system("clear");
                std::cout << "注册成功,请记住你的注册id:["<< id << "]" <<std::endl;
                std::cout << "请直接进行登录！" << std::endl;
                break;
            case 0:
                std::cout << "client Quit!" << std::endl;
                exit(2);
            default:
                system("clear");
                std::cout << "Enter Error! Try Again" << std::endl;
                break; 
        }
    }
    return 0;
}
