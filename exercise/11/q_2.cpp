#include <iostream>
using namespace std;

class Solution 
{
public:
    void PrintfBitNumMax(int byte)
    {
        int k = 0;
        for(; byte != 0; k++)
        {
            byte = byte&(byte << 1);
        }
        cout << k << endl;
    }
};

int main()
{
    int byte;
    while (cin >> byte)
    {
        Solution s;
        s.PrintfBitNumMax(byte);
    }
    return 0;
}
