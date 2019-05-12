#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void PrintMaxNumStr(string str)
	{
		int begin = 0;
		int num = 0;
		int num_index = 0;
		int begin_index = 0;
		for (auto i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				num_index++;
				if (i != str.size() - 1)
					continue;
			}
			if (num_index > num)
			{
				num = num_index;
				begin = begin_index;
			}
			begin_index = i + 1;
			num_index = 0;
		}
		for (auto i = 0; i < num; i++)
		{
			cout << str[begin + i];
		}
		cout << endl;
	}
};

int main()
{
	string str;
	getline(cin, str);
	Solution s;
	s.PrintMaxNumStr(str);
	return 0;
}
