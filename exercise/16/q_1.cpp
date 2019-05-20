#include <iostream>
using namespace std;

class Solution 
{
public:
    void PrintNum(int num)
    {
        if (num > 500000 || num <= 0)
        {
            cout << "-1" << endl;
            return;
        }
        int count = 0;
        int array[6] = {6, 28, 496, 8128, 130816, 2096128};
        for (int i = 0; i < 6; i++)
        {
            if (array[i] < num)
                count++;
            else 
                break;
        }
        cout << count << endl;
    }
};

int main()
{
    int num = 0;
    while(cin >> num)
    {
        Solution s;
        s.PrintNum(num);
    }
    return 0;
}
