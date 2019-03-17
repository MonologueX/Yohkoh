#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int GetNum(string str1, int size1, string str2, int size2)
{
	int result = 0;
	string s;
	s.resize(size1 + size2);
	for (int i = 0; i < size1; i++)
	{
		for (int k = 0; k <= i; k++)
			s[k] = str1[k];
		for (int j = 1; j <= size2; j++)
		{
			s[i + j] = str2[j - 1];
		}
		for (int m = 0; m < size1 - i; m++)
			s[i + size2 + 1 + m] = str1[m + i + size2];
		string s1(s);
		reverse(s1.begin(), s1.end());
		if (s1 == s)
			result++;
	}
	return result;
}

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int size1 = str1.size();
	int size2 = str2.size();
	cout << GetNum(str1, size1, str2, size2) << endl;
	return 0;
}
