#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	void PrintResult(std::string str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (i + 2 < str.size())
			{
				if (str[i] == str[i + 1] && str[i] == str[i + 2])
				{
					str.erase(str.begin() + i);
					i--;
				}
			}
			if (i + 3 < str.size())
			{
				if (str[i] == str[i + 1] && str[i + 2] == str[i + 3])
				{
					str.erase(str.begin() + i + 2);
					i--;
				}
			}
		}
		cout << str << endl;
	}
};

int main()
{
	std::string str;
	Solution s;
	int num = 0;
	while (cin >> num)
	{
		while (num--)
		{
			cin >> str;
			s.PrintResult(str);
		}
	}
	return 0;
}
