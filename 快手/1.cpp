#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	std::string Judge(std::string str)
	{
		std::string temp = "";
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
			{
				if ((temp.size() > 1 && temp[0] == '0') || temp.size() > 3 || temp > "255")
					return "Neither";
				count++;
				if (count == 4)
					return "IPv4";
				temp = "";
			}
			else if (str[i] == ':')
			{
				if ((temp.size() > 1 && temp[0] == '0') || temp.size() > 4 || temp > "FFFF")
					return "Neither";
				count++;
				if (count == 8)
					return "IPv6";
				temp = "";
			}
		}
		return "Neither";
	}
};

int main()
{
	Solution s;
	std::string str;
	while (cin >> str)
	{
		cout << s.Judge(str) << endl;
	}
	return 0;
}
