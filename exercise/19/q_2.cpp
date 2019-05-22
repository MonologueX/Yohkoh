#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	std::string MaxStr(std::string str1, std::string str2)
	{
		int size = 0;
		int end = 0;
		std::vector<std::vector<int> > array;
		array.resize(str1.size());
		for (auto & e : array)
			e.resize(str2.size(), 0);
		for (auto i = 0; i < str1.size(); i++)
		{
			for (auto j = 0; j < str2.size(); j++)
			{
				if (str1[i] == str2[j])
				{
					if (i == 0 || j == 0)
						array[i][j] = 1;
					else
						array[i][j] = 1 + array[i - 1][j - 1];
					if (array[i][j] > size)
					{
						size = array[i][j];
						end = j;
					}
				}
			}
		}
		std::string str = str2.substr(end - size + 1, size);
		return str;
	}
};

int main()
{
	std::string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
			swap(str1, str2);
		Solution s;
		cout << s.MaxStr(str1, str2) << endl;
	}
	return 0;
}
