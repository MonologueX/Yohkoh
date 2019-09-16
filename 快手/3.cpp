#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	// 背包问题
	long long Diff(std::vector<long long>& array, long long num)
	{
		long long size = array.size();
		long long sum = 0;
		for (long long i = 0; i < size; i++)
			sum += array[i];
		std::vector<std::vector<long long> > dp;
		for (long long i = 0; i <= size; i++)
		{
			std::vector<long long> temp;
			for (long long j = 0; j <= (sum >> 1); j++)
				temp.push_back(0);
			dp.push_back(temp);
		}
		for (long long i = 1; i <= size; i++)
		{
			for (long long j = 1; j <= (sum >> 1); j++)
			{
				if (j >= array[i - 1])
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - array[i - 1]] + array[i - 1]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return sum - 2 * dp[size][sum >> 1];
	}
};

int main()
{
	long long num;
	Solution s;
	std::vector<long long> array;
	while (cin >> num)
	{
		array.resize(num);
		for (long long i = 0; i < num; i++)
			cin >> array[i];
		cout << s.Diff(array, num) << endl;
	}
	return 0;
}
