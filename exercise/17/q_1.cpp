#include <iostream>
using namespace std;

class Solution
{
public:
    void PrintNum(int num)
    {
        if (num < 3)
            cout << "-1" << endl;
        else if (num % 2 != 0)
            cout << "2" << endl;
        else
        {
            num %= 4;
            num = (num/2)+3;
            cout << num << endl;
        }
    }
};

int main()
{
    int num = 0;
    while (cin >> num)
    {
        Solution s;
        s.PrintNum(num);
    }
    return 0;
}
