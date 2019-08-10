/***********************************
 * 文件名称: napsackProblem.cpp
 * 文件描述: 0-1 背包
 * 题目连接: https://www.lintcode.com/problem/backpack-ii/description
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/


/***********************************
m = 10;num = 4;A = [2,3,5,7];v=[1,5,2,4]
F(i, j) 表示j的总钱数，前i个物品中最大多少价值
		0 0 0 0 0 0 0 0 0 0 0 
		0 0 1 1 1 1 1 1 1 1 1 
		0 0 1 5 5 6 6 6 6 6 6 
		0 0 1 5 5 6 6 6 7 7 8 
		0 0 1 5 5 6 6 6 7 7 9 
***********************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution 
{
public:
	int backPackII(int m, vector<int> A, vector<int> V) 
	{
		if (A.empty() || V.empty() || m < 1) 
		{
			return 0;
		}
		const int N = A.size() + 1;
		const int M = m + 1;
		vector<vector<int> > result;
		result.resize(N);
		for (int i = 0; i != N; ++i) 
		{
			result[i].resize(M, 0);
		}

		for (int i = 1; i < N; ++i) 
		{
			for (int j = 1; j != M; ++j) 
			{
				if (A[i - 1] > j) 
					result[i][j] = result[i - 1][j];
				else 
				{
					int newValue = result[i-1][j-A[i-1]] + V[i - 1];
					result[i][j] = max(newValue, result[i - 1][j]);
				}
			}
		}
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
		return result[N - 1][m];
	}
};

int main()
{
	int m = 0;
	int num = 0;
	while (cin >> m >> num)
	{
		std::vector<int> A;
		std::vector<int> V;
		A.resize(m);
		V = A;
		for (auto i = 0; i < num; i++)
			cin >> A[i] >> V[i];
		Solution s;
		s.backPackII(m, A, V);
	}
	return 0;
}
