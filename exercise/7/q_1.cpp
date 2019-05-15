#include <iostream>
using namespace std;

class Solution
{
public:
	void PrintNum(int num)
	{
		int temp = 0;
		int min = 0;
		int max = 1;
		while (1)
		{
			if (max >= num)
				break;
			temp = max;
			max = max + min;
			min = temp;
		}
		max = max - num;
		min = num - min;
		if (max > min)
			cout << min << endl;
		else
			cout << max << endl;
	}
};

int main()
{
	int num = 0;
	cin >> num;
	Solution s;
	s.PrintNum(num);
	return 0;
}
