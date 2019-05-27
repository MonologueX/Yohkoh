#include <iostream>
#include <stack>
#include <string>
using namespace std;


int _24To10(std::string str)
{
	int StrNum[256];
	StrNum['0'] = 0;
	StrNum['1'] = 1;
	StrNum['2'] = 2;
	StrNum['3'] = 3;
	StrNum['4'] = 4;
	StrNum['5'] = 5;
	StrNum['6'] = 6;
	StrNum['7'] = 7;
	StrNum['8'] = 8;
	StrNum['9'] = 9;
	StrNum['a'] = 10;
	StrNum['b'] = 11;
	StrNum['c'] = 12;
	StrNum['d'] = 13;
	StrNum['e'] = 14;
	StrNum['f'] = 15;
	StrNum['g'] = 16;
	StrNum['h'] = 17;
	StrNum['i'] = 18;
	StrNum['j'] = 19;
	StrNum['k'] = 20;
	StrNum['l'] = 21;
	StrNum['m'] = 22;
	StrNum['n'] = 23;
	int result = 0;
	int count = 1;
	int temp = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp = str[i] - 48;
		else
			temp = str[i] - 87;
		result += (temp*count);
		count *= 24;
	}
	return result;
}

int main()
{
	int StrNum[256];
	StrNum['a'] = 10;
	int num = 0;
	cin >> num;
	std::string str;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		cout << _24To10(str) << endl;
	}
	return 0;
}
