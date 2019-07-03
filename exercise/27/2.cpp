#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
	std::string Result(std::string str1, std::string str2, std::string str3)
	{
		if (Cmp(Sum(str1, str2), str3) && Cmp(Sum(str2, str3), str1) && Cmp(Sum(str1, str3), str2)) 
		{
			return "Yes";
		}
		else 
		{
			return "No";
		}
	}

private:
	bool Cmp(std::string str1, std::string str2)
	{
		if (str1.size() > str2.size())
			return true;
		else if (str1.size() < str2.size())
			return false;
		else
		{
			int temp = strcmp(str1.c_str(), str2.c_str());
			if (temp > 0)
				return true;
			return false;
		}
	}

	std::string Sum(std::string str1, std::string str2)
	{
		if (str1.size() < str2.size())
		{
			return Sum(str2, str1);
		}
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		int carry = 0;
		std::string result;
		for (auto i = 0; i < str2.size(); i++)
		{
			int temp = str1[i] + str2[i] - '0' - '0' + carry;
			carry = temp / 10;
			temp = temp % 10;
			result += std::to_string(temp);
		}
		for (auto i = str2.size(); i < str1.size(); i++)
		{
			int temp = str1[i] - '0' + carry;
			carry = temp / 10;
			temp = temp % 10;
			result += std::to_string(temp);
		}
		if (carry)
			result += std::to_string(carry);
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	std::string str1, str2, str3;
	while (cin >> str1 >> str2 >> str3)
	{
		Solution s;
		cout << s.Result(str1, str2, str3) << endl;
	}
	return 0;
}
