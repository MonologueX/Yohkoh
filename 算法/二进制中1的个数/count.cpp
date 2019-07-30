#include <iostream>
using namespace std;

///////////////////////////////////////////////
//  解法一
///////////////////////////////////////////////
int count1(int num)
{
    int count = 0;
    while (num)
    {
        if (num % 2 == 1)
        {
            count++;
        }
        num /= 2;
    }
    return count;
}

///////////////////////////////////////////////
//  解法二
///////////////////////////////////////////////
int count2(int num)
{
    int count = 0;
    while (num)
    {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}

///////////////////////////////////////////////
//  解法三
///////////////////////////////////////////////
int count3(int num)
{
    int count = 0;
    while (num)
    {
        num &= (num-1);
        count++;
    }
    return count;
}

int main()
{
    int num = 0;
    while ( cin >> num )
    {
        cout << count1(num) << endl;
        cout << count2(num) << endl;
        cout << count3(num) << endl;
    }
    return 0;
}
