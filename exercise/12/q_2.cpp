#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void PrintNum(std::string str1, std::string str2)
    {
        int max = 0;
        auto size1 = str1.size();
        auto size2 = str2.size();
        std::vector<std::vector<int> > length(size1, vector<int>(size2, 0));
        for (auto i = 0; i < size1; i++)
        {
            for (auto j = 0; j < size2; j++)
            {
                if (str1[i] == str2[j])
                {
                    if (i < 1 || j < 1)
                        length[i][j] = 1;
                    else
                        length[i][j] = length[i-1][j-1] + 1;
                }
                
                if (max < length[i][j])
                    max = length[i][j];
            }
        }
        cout << max << endl;
    }
};

int main()
{
    std::string str1;
    std::string str2;
    cin >> str1 >> str2;
    Solution s;
    s.PrintNum(str1, str2);
    return 0;
}
