#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintResult(std::vector<string> array, int num)
	{
		if (Judge1(array, num) && Judge2(array, num))
		{
			cout << "both" << endl;
		}
		else if (!Judge1(array, num) && Judge2(array, num))
		{
			cout << "lengths" << endl;
		}
		else if (Judge1(array, num) && !Judge2(array, num))
		{
			cout << "lexicographically" << endl;
		}
		else
		{
			cout << "none" << endl;
		}
	}
private:
	bool Judge1(std::vector<string> array, int num)
	{
		int i;
		for (i = 1; i < num; i++)
		{
			std::string str1 = array[i - 1];
			std::string str2 = array[i];
			if (strcmp(str1.c_str(), str2.c_str()) > 0)
			{
				return false;
			}
		}
		return true;
	}
	bool Judge2(std::vector<string> array, int num)
	{
		for (auto i = 0; i < num-1; i++)
		{
			if (array[i].size() > array[i+1].size())
				return false;
		}
		return true;
	}
};

int main()
{
	std::vector<string> array;
	int num;
	cin >> num;
	array.resize(num);
	for (auto i = 0; i < num; i++)
	{
		cin >> array[i];
	}
	Solution s;
	s.PrintResult(array, num);
	return 0;
}
