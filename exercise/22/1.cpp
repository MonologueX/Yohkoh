#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void PrintResult(int abilit, int num, std::vector<int> array)
    {
        for (auto i = 0; i < num; i++)
        {
            if (abilit >= array[i])
                abilit += array[i];
            else 
                abilit += (Gcd(abilit, array[i]));
        }
        cout << abilit << endl;
    }
private:
    int Gcd(int x, int y)
    {
        if (x < y)
            return Gcd(y, x);
        if (y == 0)
            return x;
        else 
        {
            if (x & 1)
            {
                if (y & 1)
                    return Gcd(y, x-y);
                else 
                    return Gcd(x, y >> 1);
            }
            else
            {
                if (y & 1)
                    return Gcd(x >> 1, y);
                else 
                    return (Gcd(x >> 1, y >> 1) << 1);
            }
        }
    }
};

int main()
{
    int num = 0;
    int abilit = 0;
    std::vector<int> array;
    while (cin >> num >> abilit)
    {
        array.resize(num);
        for (auto i = 0; i < num; i++)
        {
            cin >> array[i];
        }
        Solution s;
        s.PrintResult(abilit, num, array);
    }
    return 0;
}
