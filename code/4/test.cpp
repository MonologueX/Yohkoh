#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	while (b ^= a ^= b ^= a %= b);
	return a;
}

float cal(int num)
{
	float count = 1;
	if (num == 1)
		return count;
	else
	{
		for (int i = 2; i < num; i++)
		{
			int temp = gcd(i, num);
			if (temp == 1)
				count++;
		}
		return count / num;
	}
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		float result = cal(1);
		for (int i = 2; i <= num; i++)
		{
			float temp = cal(i);
			if (temp < result)
				result = temp;
		}
		printf("%.6f\n", result);
	}
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	std::vector<std::vector<double> > array;
	while (cin >> num)
	{
		array.resize(num);
		for (auto & e : array)
			e.resize(4, 0);
		for (auto i = 0; i < num; i++)
		{
			cin >> array[i][2] >> array[i][3];
			array[i][0] = array[i][2] * array[i][3];
			array[i][1] = 1/(min(array[i][2] / array[i][3], array[i][3] / array[i][2]));
		}
		sort(array.begin(), array.end());


		for (auto i = 0; i < array.size(); i++)
		{
			cout << array[i][2] << " " << array[i][3] << " ";
		}
		cout << endl;
	}
	return 0;
}
