#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintNum(int num, int hex)
	{
		string str;
		int index = 0;
		if (num < 0)
		{
			index = -1;
			num = 0 - num;
		}
		while (num != 0)
		{
			int temp = num%hex;
			num /= hex;
			if (temp > 9)
				str += 'A' + temp - 10;
			else
				str += '0' + temp;
		}
		if (index == -1)
			str += '-';
		reverse(str.begin(), str.end());
		cout << str;
	}
};

int main()
{
	int num, hex;
	Solution s;
	cin >> num >> hex;
	s.PrintNum(num, hex);
	return 0;
}
