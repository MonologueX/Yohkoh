#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int dfs(int pos, int size, std::vector<int> array, long long sum, long long pi)
	{
		int i, result;
		for (i = pos, result = 0; i<size; ++i)
		{
			sum += array[i];
			pi *= array[i];
			if (sum > pi) 
				result += 1 + dfs(i + 1, size, array, sum, pi);
			else if (array[i] == 1) 
				result += dfs(i + 1, size, array, sum, pi);
			else 
				break;
			sum -= array[i];
			pi /= array[i];
			for (; i<size - 1 && array[i] == array[i + 1]; ++i);
		}
		return result;
	}
};

int main()
{
	std::vector<int> array;
	int size;

	while (cin >> size)
	{
		array.resize(size);
		for (size_t i = 0; i < size; i++)
			cin >> array[i];
		sort(array.begin(), array.end());
		Solution s;
		cout << s.dfs(0, size, array, 0, 1) << endl;
	}
	return 0;
}
