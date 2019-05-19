#include <iostream>
using namespace std;

class Solution 
{
public:
    int findNumberOf1(int num)
    {
        int count = 0;
        while (num)
        {
            count++;
            num = (num-1) & num;
        }
        return count;
    }
};

int main()
{
    int num = 0;
    while (cin >> num)
    {
        Solution s;
        cout << s.findNumberOf1(num) << endl;
    }
    return 0;
}
