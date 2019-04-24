i#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int string2int(string str) {
	std::vector<int> num;
	size_t i = 0;
	int choice = 0;
	if (str[0] == '-')
	{
		choice = 1;
		i++;
	}
	if (str[0] == '+')
	{
		i++;
	}
	while (str[i] == '0')
	{
		i++;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int temp = (int)str[i] - 48;
			num.push_back(temp);
		}
		else if (str[i] == '.')
			break;
		else if (str[i] == ' ')
			;
		else
			return 0;
	}
	int result = 0;
	int index = num.size() - 1;
	int j = 1;
	for (size_t i = 0; i < num.size(); i++)
	{
		result += num[index--] * j;
		j *= 10;
	}
	if (choice == 1)
	{
		result = 0 - result;
	}
	return result;
}
/******************************结束写代码******************************/


int main() {
	int res;

	string _str;
	getline(cin, _str);

	res = string2int(_str);
	cout << res << endl;
	return 0;
}
