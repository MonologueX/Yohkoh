#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    Solution()
    {
        array.resize(256, 0);
    }
    void PrintFirstStr(std::string str)
    {
        for (auto i = 0; i < str.size(); i++)
            ++array[str[i]];
        for (auto i = 0; i < str.size(); i++)
        {
            if (array[str[i]] == 1)
            {
                cout << str[i] << endl;
                return;
            }
        }
        cout << "-1" << endl;
    }
private:
    std::vector<int> array;
};

int main()
{
    std::string str;
    while (cin >> str)
    {
        Solution s;
        s.PrintFirstStr(str);
    }
    return 0;
}
