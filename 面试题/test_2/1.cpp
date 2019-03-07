#include <iostream>
#include <vector>
using namespace std;

int GetNum(vector<int> v, int n)
{
	if (n <= 2)
		return 1;
	int count = 1;
	int i = 0;
	while (i < (n - 1))
	{
		if ((v[i] > v[i + 1]) && (i < n - 1))
		{
			for (; i < n - 1; i++)
			{
				if (v[i] < v[i + 1])
				{
					count += 1;
					i++;
					break;
				}
			}
		}
		else if ((v[i] < v[i + 1]) && (i < n - 1))
		{
			for (; i < n - 1; i++)
			{
				if (v[i] > v[i + 1])
				{
					count += 1;
					i++;
					break;
				}
			}
		}
		else
			i++;
	}
	return count;
}

int main()
{
	int n = 0;
	int num = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	int result = GetNum(v, n);
	cout << result << endl;
	return 0;
}
