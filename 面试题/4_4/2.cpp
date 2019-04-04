#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
	void GetAAndB(std::vector<int> array)
	{
		for (size_t i = 0; i < array.size(); i++)
		{
			unsigned long a = (unsigned long)pow(5, (double)array[i]) - 4;
			unsigned long b = (unsigned long)pow(4, (double)array[i]) + array[i] - 4;
			std::cout << a << " " << b << std::endl;
		}
	}
};

int main()
{
	Solution s;
	int num = 0;
	std::vector<int> array;
	while (1)
	{
		std::cin >> num;
		if (0 == num)
			break;
		array.push_back(num);
	}
	s.GetAAndB(array);
	return 0;
}

