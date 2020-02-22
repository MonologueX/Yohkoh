#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution 
{
public:
    int GetNum(int num)
    {
        for (int i = 0; ; i++)
        {
        }
    }
private:
    std::string numToBS(int num)
    {
        std::string cur;
        while (num)
        {
            if ((num & 0x01) == 0)
                cur += '0';
            else 
                cur += '1';
            num >>= 1;
        }
        return cur;
    }
};

int main()
{
    return 0;
}
