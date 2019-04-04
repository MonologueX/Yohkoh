// write your code here cpp
#include <iostream>
#include <vector>

class Solution
{
public:
	void GetNum(std::vector<int> array)
	{
		for (size_t i = 0; i < array.size(); i++)
		{
			std::cout << _GetNum(array[i]) << std::endl;
		}
	}
private:
	int _GetNum(int num)
	{
		int result = 0;
		while (num > 1)
		{
			result++;
			num = num / 3 + 1 - (num % 3 ^ 3) / 3;
		}
		return result;
	}
};

int main()
{
	Solution s;
	std::vector<int> array;
	int num = 0;
	while (std::cin >> num)
	{
		if (num == 0)
			break;
		array.push_back(num);
	}
	s.GetNum(array);
	return 0;
}
