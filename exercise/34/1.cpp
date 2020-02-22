// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	void PrintName(std::vector<string> array, int num)
	{
		// 一次遍历 array 每个元素，发现在首尾加 ""
		std::string str;
		for (int i = 0; i < num; i++)
		{
			if (array[i].find(',') != std::string::npos || \
				array[i].find(' ') != std::string::npos)
			{
				str += '"';
				str += array[i];
				str += '"';
			}
			else
				str += array[i];
			if (i != num - 1)
				str += ", ";
		}
		cout << str << endl;
	}
};

int main()
{
	std::vector<string> array;
	int num = 0;
	Solution s;
	while (cin >> num)
	{
        cin.get();
		array.resize(num);
		for (int i = 0; i < num; i++)
		{
			getline(cin, array[i]);
		}
		s.PrintName(array, num);
	}
	return 0;
}
