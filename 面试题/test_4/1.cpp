#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string GetNum(long long m, const long long n)
{
	long long a = 0;
	string result;
	char A;
	while (1)
	{
		if (m < n)
		{
			if (m > 9)
			{
				A = 'A' + (char)(m - 10);
			}
			else
				A = '0' + (char)m;
			result += A;
			break;
		}
		// 余数
		a = m % n;
		if (a > 9)
		{
			A = 'A' + (char)(a - 10);
		}
		else 
			A = '0' + (char)a;

		result += A;

		m /= n;

	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	long long num[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		cin >> num[i];
	}
	string result = GetNum(num[0], num[1]);
	cout << result << endl;
	return 0;
}
