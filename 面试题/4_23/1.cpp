#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int GetResult(std::vector<int> array, int n, int m)
	{
		std::vector<int> num1;
		std::vector<int> num2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (0 == i % 2)
				{
					num1.push_back(array[i*n + j]);
					j++;
					if (j >= m)
						break;
					num2.push_back(array[i*n + j]);
				}
				else
				{
					num2.push_back(array[i*n + j]);
					j++;
					if (j >= m)
						break;
					num1.push_back(array[i*n + j]);
				}
			}
		}
		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		int result1 = 0;
		int result2 = 0;
		if (num1[0] == num1[num1.size()-1])
			result1 = num1.size();
		else
		{
			int index = 1;
			for (int i = 0; i < num1.size()-1; i++)
			{
				if (index < 1)
					index = 1;
				if (num1[i] == num1[i + 1])
					index++;
				else
					index = 1;
				if (index > result1)
					result1 = index;
			}
		}
		if (num2[0] == num2[num2.size()-1])
			result2 = num2.size();
		else
		{
			int index = 1;
			for (int i = 0; i < num2.size()-1; i++)
			{
				if (index < 1)
					index = 1;
				if (num2[i] == num2[i + 1])
					index++;
				else
					index = 1;
				if (index > result1)
					result2 = index;
			}
		}

		if (result1 > result2)
			return result2;
		else
			return result1;
	}
};

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	std::vector<int> array;
	array.resize(n*m);
	int temp = 0;
	for (int i = 0; i < n*m; i++)
	{
		cin >> temp;
		array[i] = temp;
	}
	Solution s;
	cout << s.GetResult(array, n, m) << endl;
	return 0;
}
