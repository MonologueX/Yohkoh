// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int GetNum(long long num)
{
	if (num < 10)
		return num;
	int result = 0;
	int temp = 0;
	while (num > 0)
	{
		temp = num % 10;
		result += temp;
		num /= 10;
	}

	if (result > 9)
		result = GetNum(result);
	return result;
}

int main()
{
	vector<long long> array;
	long long num = 0;
	while (cin >> num)
	{
		array.push_back(num);
		if (getchar() != '\n')
			break;
	}
	for (size_t i = 0; i < array.size(); i++)
	{
		int result = GetNum(array[i]);
		cout << result << endl;
	}
	return 0;
}
