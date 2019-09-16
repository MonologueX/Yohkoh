#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	long long maxLen(std::vector<long long>& array, long long num)
	{
		sort(array.begin(), array.end());
		long long large = 0;
		if (array[0] == array[num - 1])
			return num;
		for (long long i = 0; i < num; i++)
		{
			for (long long j = i + 1; j < num; j++)
			{
				long long now = j;
				long long ans = 2;
				long long gc = array[j] - array[i];
				for (long long k = j + 1; k < num; k++)
				{
					if (array[k] - array[now] == gc)
					{
						ans = ans + 1;
						now = k;
					}
					if (array[k] - gc > array[now])
						break;
				}
				if (large < ans)
					large = ans;
			}
		}
		return large;
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
		cout << s.maxLen(array, num) << endl;
	}
	return 0;
}
