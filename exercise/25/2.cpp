#if 0
#include<iostream>
using namespace std;
int main()
{
    long double n;
    long double r;
    while(cin >> n >> r)
    {
        if(n <= 2*3.14*r)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
#endif 

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintResult(std::string str1, std::string str2)
	{
		std::string mul = CalMul(str2, "628");
		str1 += "00";
		if (Cmp(str1, mul))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
private:
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

	std::string CalMul(std::string str1, std::string str2)
	{
		if (str1.size() < str2.size())
			return CalMul(str2, str1);
		int carry = 0;
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		std::string result;
		int count = 0;
		for (auto i = 0; i < str2.size(); i++)
		{
			carry = 0;
			std::string cur;
			for (auto k = 0; k < count; k++)
				cur += '0';
			for (auto j = 0; j < str1.size(); j++)
			{
				int temp = carry + (str2[i] - '0')*(str1[j] - '0');
				carry = temp / 10;
				temp = temp % 10;
				cur += (std::to_string(temp));
			}
			if (carry)
				cur += std::to_string(carry);
			reverse(cur.begin(), cur.end());
			result = Sum(result, cur);
			count++;
		}
		
		
		return result;
	}

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
};

int main()
{
	std::string str1, str2;

	while (cin >> str1 >> str2)
	{
		Solution s;
		s.PrintResult(str1, str2);
	}

	return 0;
}
