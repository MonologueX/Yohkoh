#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void PrintNum(string str_a, string str_b)
    {
        int num = 0;
        for (auto i = 0; i <= str_a.size(); i++)
        {
            string str = str_a;
            str.insert(i, str_b);
            if (IsCircleText(str))
            {
                num++;
            }
        }
        cout << num << endl;
    }
private:
    bool IsCircleText(std::string str)
    {
        int begin = 0;
        int end = str.size() - 1;
        while (begin < end)
        {
            if (str[begin++] != str[end--])
                return false;
        }
        return true;
    }
};

int main()
{
    string str_a, str_b;
    getline(cin, str_a);
    getline(cin, str_b);
    
    Solution s;
    s.PrintNum(str_a, str_b);
    return 0;
}
