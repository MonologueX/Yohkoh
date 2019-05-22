#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	void PrintNum(int num)
	{
		int min = 0;
		int max = 0;
		num /= 2;
		for (int i = 0; i < num; i++)
		{
			if (Judge(num - i) && Judge(num + i))
			{
				cout << num - i << endl << num + i << endl;
				break;
			}
		}
	}
private:
	bool Judge(int num)
	{
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
};

int main()
{
	int num = 0;
	while (cin >> num)
	{
		Solution s;
		s.PrintNum(num);
	}
	return 0;
}
