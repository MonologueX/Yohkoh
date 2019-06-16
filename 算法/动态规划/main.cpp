#include <iostream>
#include <vector>
using namespace std;

class AscentSequence {
public:
	int findLongest(vector<int> A, int n) 
	{
		// write code here
		std::vector<int> dp;
		std::vector<int> help;
		dp.resize(n, 0);
		help.resize(n, 0);
		int max_length = 0, count = 0;
		dp[0] = 1; help[0] = A[0];
		for (int i = 1; i < n; i++)
		{
			int right = count, left = 0, middle;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (A[i] >= help[middle])
				{
					left = middle + 1;
				}
				else
				{
					right = middle - 1;
				}
			}
			help[left] = A[i]; 
			if (left > count)
				count = left;
			dp[i] = left + 1;                     //更新dp[]的值
			if (dp[i] > max_length)       //更新最长递增子序列的长度
				max_length = dp[i];
		}
		return max_length;
	}
};

int main()
{
	AscentSequence s;
	std::vector<int> array;
	while (1)
	{
		array.resize(7);
		for (auto i = 0; i < 7; i++)
		{
			cin >> array[i];
		}
		cout << s.findLongest(array, 7) << endl;
	}
	return 0;
}
