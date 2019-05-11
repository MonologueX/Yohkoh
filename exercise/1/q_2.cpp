#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution()
    {
        array.resize(256, 0);
        result.clear();
    }
    void DeleteString(string& str1, string& str2)
    {
        for (auto i = 0; i < str2.size(); i++)
            array[str2[i]]++;
        for (auto i = 0; i < str1.size(); i++)
        {
            if (0 == array[str1[i]])
                result += str1[i];
        }
        cout << result;
    }
private:
    std::vector<int> array;
    string result;
};

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    Solution s;
    s.DeleteString(str1, str2);
    return 0;
}
