// write your code here cpp
#include <iostream>
#include<math.h>
using namespace std;
    
class Solution
{
public:
    void PrintResult(int n)
    {
        if (n < 1 || n > 20)
        {
            return;
        }
        a = (unsigned long)pow(5, (double)n);
        b = (unsigned long)pow(4, (double)n);
        cout << a-4 << " " << b-4+n;
    }
private:
    unsigned long a;
    unsigned long b;
};

int main()
{
    int n = 0;
    Solution s;
    while (cin >> n)
    {
        s.PrintResult(n);
    }
    return 0;
}
