#include <iostream>
using namespace std;

class Solution 
{
public:
    void PrintNum(int year, int month, int day)
    {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            months[1]++;
        int sum = 0;
        for (auto i = 0; i < month-1; i++)
            sum += months[i];
        sum += day;
        cout << sum << endl;
    }
};

int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        Solution s;
        s.PrintNum(year , month, day);
    }
    return 0;
}
