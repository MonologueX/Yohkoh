#include <iostream>
#include <stack>
#include <string>
using namespace std;

char Judge(std::string s1, std::string s2)
{
	if (s1.size() != s2.size())
		return 'N';
	std::stack<char> s;
	int count = 0;
	for (size_t i = 0; i < s1.size(); i++)
	{
		s.push(s1[i]);
		while (s.size() != 0 && s.top() == s2[count])
		{
			s.pop();
			count++;
		}
	}
	if (count == s1.size())
		return 'Y';
	return 'N';
}

int main()
{
	int T = 0;
	cin >> T;
	std::string s1;
	std::string s2;
	for (int i = 0; i < T; i++)
	{
		cin >> s1 >> s2;
		cout << Judge(s1, s2) << endl;
	}
	return 0;
}
