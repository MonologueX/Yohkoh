// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		size_t size = str2.size();
		size_t pos = str1.find(str2);
		if ((str1[pos - 1] == '"' && str1[pos + size] == '\"') ||
			str1[pos + size] == '\'')
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}
