#include <iostream>
using namespace std;

class Solution
{
public:
	void Result(int n, int m)
	{
		int i = 1;
		if (m > n)
			i = m - n;
		for (; 2*i <= m; i++)
		{
			cout << i << " " << m - i << endl;
		}
		if (m <= n)
			cout << m << endl;
	}
};

void Result(int n, int m)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= j)
				break;
			if (m == i + j)
				cout << j << " " << i << endl;
		}
	}
	cout << m << endl;
}

int main()
{
	Solution s;
	int m = 0;
	int n = 0;
	cin >> n >> m;
	//s.Result(n, m);
	Result(n, m);
	return 0;
}
