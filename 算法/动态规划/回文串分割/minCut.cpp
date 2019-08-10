/*
定义动态规划数组dp，dp[i]的含义是子串str[0…i]至少需要切割几次，才能把str[0…i]全部切成回文子串。那么dp[len-1]就是最后的结果。
从左往右依次计算dp[i]的值，i 初始为0，具体计算过程如下：
1、假设 j 处在 0 到 i 之间，如果str[j…i]是回文串，那么dp[i]的值可能是dp[j-1] + 1，其含义是在str[0…i]上，既然str[j…i]是回文串，那么它可以自己作为一个分割的部分，剩下的部分str[0…j-1]继续做最经济的分割，也就是dp[j-1]的值。
2、根据步骤1的方式，让 j 在 i 到 0 的位置上枚举，那么所有可能中最小值就是dp[i]的值，即dp[i] = min{dp[j-1]+1 (0<= j <= i，且str[j…i]必须是回文串)}。
3、如何快速方便的判断str[j…i]是否为回文串？
　1）定义一个二维数组p，如果p[j][i]为True，表示str[j…i]是回文串，否则不是。在计算dp过程中，希望能够同步、快速的计算出矩阵p。
　2）p[j][i]如果为True，一定来自以下三种情况：
　　<1>　str[j][i]由一个字符组成
　　<2>　str[j][i]由两个字符组成且两个字符相等
　　<3>　str[j][i]由多个字符组成，str[j] == str[i]且p[j+1][i-1] == True。
　3）在计算dp数组的过程中，位置i是从左向右依次计算的。而对于每一个i来说，又依次从 i 位置向左遍历所有的位置，以此来决策dp[i]。所以对于p[j][i]来说，p[j+1][i-1]一定已经计算过。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		vector<int> vec(len, 0);
		vector<vector<bool> > bvec(len, vector<bool>(len, false));
		for (int i = 0; i<len; i++)
		{
			vec[i] = i;
			for (int j = i; j >= 0; j--)
			{
				if ((s[i] == s[j]) && (i - j<2 || bvec[i - 1][j + 1]))
				{
					bvec[i][j] = true;
					if (j == 0) 
						vec[i] = min(vec[i], 0);
					else
						vec[i] = min(vec[i], vec[j - 1] + 1);
				}
			}
		}
		return vec[len - 1];
	}
};

void Test()
{
	std::string str;
	Solution s;
	while (cin >> str)
	{
		cout << s.minCut(str) << endl;
	}
}
