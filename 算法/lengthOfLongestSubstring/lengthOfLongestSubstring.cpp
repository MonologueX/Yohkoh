#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		std::vector<int> array;
		array.resize(256, 0);
		int max = 0;
		int cur = 0;
		for (auto i = 0; i < s.size(); i++)
		{
			array[s[i]]++;
			// 如果 array[s[i]] 不为 1,说明已经遍历过
			if (array[s[i]] != 1)
			{
				if (s[i] != s[i - cur])
				{
					// 更新 array, cur
					// 将下标为 i-cur 到 index 之间的 array 值置为0
					// index 为 i-cur 到 index 之间的和 s[i] 相等的下标， 即 s[i] == s[index]
					while (s[i] != s[i - cur])
					{
						array[s[i - cur]] = 0;
						cur--;
					}
				}
			}
			else
				cur++;
			if (cur > max)
				max = cur;
		}
		return max;
	}
};
int main()
{
	std::string A;
	while (cin >> A)
	{
		Solution s;
		cout << s.lengthOfLongestSubstring(A) << endl;
	}
	return 0;
}
