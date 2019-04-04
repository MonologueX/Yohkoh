#include <iostream>
using namespace std;

int GetResult(long long a, long long b, long long c)
{
	if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
		return 1;
	return 0;
}

int main()
{
	long long a, b, c;
	while (cin >> a >> b >> c)
	{
		int result = GetResult(a, b, c);
		if (0 == result)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
