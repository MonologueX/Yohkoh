#include "game.hpp"
#include "console_game.hpp"

static void Usage(std::string proc)
{
    std::cout << "Usage" << proc << "ip port" << std::endl;
    std::cout << "无法连接到服务器，将进行人机版五子棋" << std::endl;
    ConsoleGame g;
    g.Play();
}

static void LoginMenu()
{
    std::cout << "=============== 五子棋 ===============" << std::endl;
    std::cout << "=== 1. 登录" << std::endl;
    std::cout << "=== 2. 注册" << std::endl;
    std::cout << "=== 3. 退出" << std::endl;
    std::cout << "请选择>";
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
            case 2:
                Register(ip, port, name, password, id);
                std::cout << "注册成功,请记住你的注册id:["<< id << "]" <<std::endl;
                std::cout << "请直接进行登录！" << std::endl;
                break;
            case 3:
                std::cout << "client Quit!" << std::endl;
                exit(2);
            default:
                std::cout << "Enter Error! Try Again" << std::endl;
                break; 
        }
    }
    return 0;
}
