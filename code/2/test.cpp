#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintStr(std::string str)
	{
		std::vector<string> num;
		std::vector<string> cal;
		std::string result = "";
		std::string cur = "";
		cur += str[0];
		for (size_t i = 1; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				std::string temp = "";

				while (str[i] < '0' || str[i] > '9')
				{
					temp += str[i];
					i++;
				}
				num.push_back(cur);
				cur = "";
				cal.push_back(temp);
				if ((i) < str.size())
					cur += str[i];
			}
			else
			{
				cur += str[i];
			}
		}
		
		num.push_back(cur);

		int one = 0, two = 0;
		int count = 0;
		for (int i = 0; i < cal.size(); i++)
		{
			if (cal[i][0] == '-' || cal[i][0] == '/')
			{
				two = i;
				sort(num.begin() + one, num.begin() + two);
				one = i;
				count++;
			}
		}
		if (count == 0)
			sort(num.begin()+one, num.end());
		cout << num[0];
		for (int i = 1; i < num.size(); i++)
		{
			cout << cal[i - 1] << num[i];
		}
		cout << endl;
	}
};

int main()
{
	std::string str;
	Solution s;
	while (cin >> str)
	{
		s.PrintStr(str);
	}
	return 0;
}
