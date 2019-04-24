#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自���的想法来 ^-^
******************************开始写代码******************************/
int GetNum() {
	int num = 0;
	std::vector<int> array;
	cin >> num;
	int temp = 0;
	array.resize(num);
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		array[i] = temp;
	}
	sort(array.begin(), array.end());
	std::vector<int> Result;
	int index = 1;
	for (int i = 0; i < num - 1; i++)
	{
		if (array[i] == array[i + 1])
			index++;
		else
		{
			Result.push_back(index);
			index = 1;
		}
	}
	Result.push_back(index);
	sort(Result.begin(), Result.end());
	if (Result[0] == Result[Result.size() - 1])
		return Result.size();
	else if (Result[0] < 2)
		return 0;
	int choice = 0;
	int max = 0;
	for (int i = 2; i <= Result[0]; i++)
	{
		for (int j = 0; j < Result.size(); j++)
		{
			if (Result[i] % j != 0)
				continue;
		}
		if (i > max)
			max = i;
		choice = 1;
	}
	if (choice == 0)
		return 0;
	int sum = 0;
	for (int j = 0; j < Result.size(); j++)
	{
		sum += Result[j];
	}
	sum = sum / max;
	return sum;
}
/******************************结束写代码******************************/


int main() {
	int res;


	res = GetNum();
	cout << res << endl;

	return 0;

}

