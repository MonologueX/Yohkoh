#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintNumStr(std::string str)
	{
		std::string temp;
		std::vector<std::string> array;
		for (auto i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				if (temp.size() != 0)
					array.push_back(temp);
				temp.clear();
			}
			else if (str[i] == '"')
			{
				i++;
				for (; i < str.size(); i++)
				{
					if (str[i] != '"')
						temp += str[i];
					else
					{
						array.push_back(temp);
						i++;
						temp.clear();
						break;
					}
				}
			}
			else 
				temp += str[i];
		}
		if (temp.size() != 0)
			array.push_back(temp);
		cout << array.size() << endl;
		for (auto i = 0; i < array.size(); i++)
			cout << array[i] << endl;
	}
};

int main()
{
	std::string str;
	std::vector<std::string> array;
	while (getline(cin, str))
	{
		Solution s;
		s.PrintNumStr(str);
	}
	return 0;
}
