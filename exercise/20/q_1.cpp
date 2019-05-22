#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class String
{
public:
	void Reverse(std::string& str)
	{
		if (str.size() <= 0)
			return;
		int begin = 0;
		int end = str.size()-1;

		while (begin < end)
		{
			swap(str[begin++], str[end--]);
		}
	}
};

int main()
{
	std::string str;
	cin >> str;
	String s;
	s.Reverse(str);
	cout << str << endl;
	return 0;
}
