// write your code here cpp
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	void GetNum(int num)
	{
		std::cout << num << " " << "=" << " ";
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0)
			{
				while (num%i == 0)
				{
					if (num == i)
						break;
					std::cout << i << " " << "*";
					num = num / i;
				}
			}
		}
		std::cout << " " << num << endl;
	}
};

int main()
{
	int num;
	while (cin >> num)
	{
		Solution s;
		s.GetNum(num);
	}
	return 0;
}
