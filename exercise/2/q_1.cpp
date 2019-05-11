#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int GetResult(std::vector<int> array)
	{
		int result = 1;
		for (auto i = 1; i < array.size() - 1; i++)
		{
			if ((array[i] > array[i - 1] && array[i] > array[i + 1]) || \
				(array[i] < array[i - 1] && array[i] < array[i + 1]))
			{
				result++;
				i++;
			}

		}
		return result;
	}
};

int main()
{
	std::vector<int> array;
	int num;
	cin >> num;
	array.resize(num);
	int temp = 0;
	for (auto i = 0; i < num; i++)
	{
		cin >> temp;
		array[i] = temp;
	}
	Solution s;
	cout << s.GetResult(array) << endl;
	return 0;
}
