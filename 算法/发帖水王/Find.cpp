#include <iostream>
#include <vector>
using namespace std;

int Find(std::vector<int> array, int num)
{
	int times = 0;
	int result = 0;
	for (int i = 0; i < num; i++)
	{
		if (times == 0)
		{
			result = array[i];
			times = 1;
		}
		else
		{
			if (result == array[i])
				times++;
			else
				times--;
		}
	}
	if (times == 0)
		return -1;
	return result;
}

int main()
{
	std::vector<int> array;
	int num = 0;
	while (cin >> num)
	{
		array.resize(num);
		for (int i = 0; i < num; i++)
		{
			cin >> array[i];
		}
		cout << Find(array, num) << endl;
	}
	return 0;
}
