/***********************************
 * 文件名称: lowestOne.cpp
 * 文件描述: 阶乘的最低位 1 的位置
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
using namespace std;

int lowestOne(int num)
{
    int ret = 1;
    while (num)
    {
        num >>= 1;
        ret += num;
    }
    return ret;
}

int main()
{
    int num = 0;
    while (cin >> num)
    {
        cout << lowestOne(num) << endl;
    }
    return 0;
}
