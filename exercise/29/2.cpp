// write your code here cpp
#include <iostream>
#include <math.h>
using namespace std;

class Solution 
{
public:
    void PrintResult(unsigned n)
    {
        if (n <= 0) 
            return;
        int result = (int)ceil(log(n) / log(3));
        cout << result << endl;
    }
};

int main()
{
    unsigned n;
    Solution s;
    while (cin >> n) 
    {
        s.PrintResult(n);
    }
    return 0;
}
