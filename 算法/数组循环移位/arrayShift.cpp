#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void Result(std::string str, int num)
    {
        // 无法输入空，不需要判定
        //if (str.empty())
        //    return;
        num %= str.size();
        reverse(str.begin(), str.end()-num);
        reverse(str.end()-num, str.end());
        reverse(str.begin(), str.end());
        cout << str << endl;;
    }
private:
};


int main()
{
    int num = 0;
    std::string str;
    Solution s;
    while (cin >> str >> num)
    {
        s.Result(str, num);
    }
    return 0;
}
