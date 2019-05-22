#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool JudgeStr(std::string str1, std::string str2)
	{
		return _JudgeStr(str1, str2, 0, 0);
	}
private:
	bool _JudgeStr(std::string str1, std::string str2, size_t begin1, size_t begin2)
	{
		if (begin1 >= str1.size() && begin2 >= str2.size())
			return true;
		else if (begin1 >= str1.size() || begin2 >= str2.size())
			return false;

		if (str1[begin1] == '?' || str1[begin1] == str2[begin2])
			return _JudgeStr(str1, str2, ++begin1, ++begin2);
		else if (str1[begin1] == '*')
			return _JudgeStr(str1, str2, begin1, begin2 + 1) ||
			_JudgeStr(str1, str2, begin1 + 1, begin2 + 1) ||
			_JudgeStr(str1, str2, begin1 + 1, begin2);
		else
			return false;
	}
};

int main()
{
	std::string str1, str2;
	while (cin >> str1 >> str2)
	{
		Solution s;
		if (s.JudgeStr(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
