#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string Sum(std::string s1, std::string s2)
	{
		std::string result;
		int carry = 0;
		int sum;
		for (size_t i = 0; i < s1.size(); i++)
		{
			if (i < s2.size())
				sum = s1[i] + s2[i] - 2*48 + carry;
			else
				sum = s1[i] - 48 + carry;
			carry = sum/10;
			sum %= 10;
			result += std::to_string(sum);
		}
		if (carry != 0)
			result += std::to_string(carry);
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	std::string s1, s2;
	while (cin >> s1 >> s2)
	{
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		Solution s;
		if (s1.size() >= s2.size())
			cout << s.Sum(s1, s2) << endl;
		else
			cout << s.Sum(s2, s1) << endl;
	}
	return 0;
}
