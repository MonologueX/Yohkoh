/***********************************
 * 文件名称: 0ofNum.cpp
 * 文件描述: Num 的阶乘中 0 的个数
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////
//  解法一
///////////////////////////////////////////////
int Num1(int num)
{
    int ret = 0;
    for (int i = 1; i <= num; i++)
    {
        int j = i;
        while (j % 5 == 0)
        {
            ret++;
            j /= 5;
        }
    }
    return ret;
}

///////////////////////////////////////////////
//  解法二
///////////////////////////////////////////////
int Num2(int num)
{
    int ret = 0;
    while (num)
    {
        ret += (num / 5);
        num /= 5;
    }
    return ret;
}

int main()
{
    int num = 0;
    while (cin >> num)
    {
        cout << Num1(num) << endl;
        cout << Num2(num) << endl;
    }
    return 0;
}
