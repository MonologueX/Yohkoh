#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	void Result(std::string str)
	{
		for (size_t i = 0; i <str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				cout << str[i];
			else if (str[i] >= 'A' && str[i] <= 'O')
			{
				int temp = (int)str[i] - 59;
				temp /= 3;
				cout << temp;
			}
			else if (str[i] >= 'P' && str[i] <= 'S')
			{
				cout << "7";
			}
			else if (str[i] >= 'T' && str[i] <= 'V')
			{
				cout << "8";
			}
			else if (str[i] >= 'W' && str[i] <= 'Z')
			{
				cout << "9";
			}
			else;
		}
		cout << endl;
	}
};


int main()
{
	int num = 0;
	cin >> num;
	std::string str;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		Solution s;
		s.Result(str);
	}
	return 0;
}
