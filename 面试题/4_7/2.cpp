// write your code here cpp
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	int GetNum(int num)
	{
		int result = 0;
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0)
			{
				while (num%i == 0)
					num = num / i;
				result++;
			}
		}
		if (num != 1)
			result++;
		return result;
	}
};

int main()
{
	int num;
	while (cin >> num)
	{
		Solution s;
		std::cout << s.GetNum(num) << std::endl;
	}
	return 0;
}
