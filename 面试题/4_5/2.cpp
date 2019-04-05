#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    static int calStringDistance(std::string a, std::string b)
    {
        int n = (int)a.size();
        int m = (int)b.size();
        std::vector<std::vector<int>>dp(n+1, std::vector<int>(m+1,0));
        dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符    
        for (int i=1; i<=m; ++i)
            dp[0][i] = i;
        for (int i=1; i<=n; ++i)
            dp[i][0] = i;
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=m; ++j)
            {
                int one = dp[i-1][j] +1;
                int two = dp[i][j-1]+1;
                int three = dp[i-1][j-1];
                if(a[i-1] != b[j-1])
                    three += 1;
                dp[i][j] = min(min(one,two), three);
            }
        }
        return dp[n][m];
    }
};

int main()
{
    std::string A;
    std::string B;
    std::cin >> A;
    std::cin >> B;
    Solution s;
    std::cout << s.calStringDistance(A, B) << std::endl;
    return 0;
}
