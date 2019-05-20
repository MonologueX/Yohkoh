#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void Printfmax(std::string str)
	{
		std::string a;
		std::string b;
		a = str.substr(0, str.find_first_of('-'));
		b = str.substr(str.find_first_of('-') + 1);
		Judge(a, a_size, a_val);
		Judge(b, b_size, b_val);
		_Printfmax(a, b);
	}
private:
	void _Printfmax(std::string a, std::string b)
	{
		if (a_size == 100)
		{
			cout << a << endl;
			return;
		}
		if (b_size == 100)
		{
			cout << b << endl;
			return;
		}
		if (a_size == 4 && b_size == 4)
		{
			if (a_val > b_val)
				cout << a << endl;
			else
				cout << b << endl;
		}
		else if (a_size == 4 || b_size == 4)
		{
			if (a_size == 4)
				cout << a << endl;
			else
				cout << b << endl;
		}
		else
		{
			if (a_size != b_size)
				cout << "ERROR" << endl;
			else
			{
				if (a_val > b_val)
					cout << a << endl;
				else
					cout << b << endl;
			}
		}
	}
	void Judge(std::string str, int& size, int& val)
	{
		if (str[0] == 'j')
		{
			if (str.size() > 8)
			{
				size = 100;
				return;
			}
			size = 1;
			val = 16;
		}

		if (str[0] == 'J')
		{
			if (str[1] == 'O')
			{
				size = 1;
				val = 17;
			}
		}
		
		int temp = atoi(str.c_str());
		if (temp == 10)
		{
			if (str.size() == 10)
			{
				size = 5;
				val = 10;
				return;
			}
			size = str.size() + 1;
			size /= 3;
			val = 10;
		}
		else
		{
			size = str.size() + 1;
			size /= 2;
			if (str[0] == '2')
				val = 15;
			else if (str[0] == 'A')
				val = 14;
			else if (str[0] == 'J')
				val = 11;
			else if (str[0] == 'Q')
				val = 12;
			else if (str[0] == 'K')
				val = 13;
			else
				val = temp;
		}
	}
private:
	int a_size = 0;
	int b_size = 0;
	int a_val = 0;
	int b_val = 0;
};

int main()
{
	std::string str;
	
	while (getline(cin ,str))
	{
		Solution s;
		s.Printfmax(str);
	}
	return 0;
}
