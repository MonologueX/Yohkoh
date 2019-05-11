#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void GetResult(std::string& str)
	{
		reverse(str.begin(), str.end());
		auto start = 0;
		auto end = 0;
		for (auto i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				reverse(str.begin() + start, str.begin() + i);
				start = i + 1;
			}
		}
		reverse(str.begin() + start, str.end());
	}
};

int main()
{
	string str;
	getline(cin, str);
	Solution s;
	s.GetResult(str);
	cout << str << endl;
	return 0;
}
