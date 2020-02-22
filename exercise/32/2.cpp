// write your code here cpp
#include <iostream>
using namespace std;

int fib[100001];

class Solution
{
public:
	Solution()
	{
		InitFib();
	}
	void PrintNumFib(int num)
	{
		if (num < 29) 
		{
			printf("%d\n", fib[num]);
		}
		else 
		{
			printf("%06d\n", fib[num]);
		}
	}
private:
	void InitFib()
	{
		fib[0] = 1;
		fib[1] = 1;
		for (auto i = 2; i < 100001; i++)
		{
			fib[i] = fib[i - 1] + fib[i - 2];
			fib[i] = fib[i]%1000000;
		}
	}
};

int main()
{
	Solution s;
	int num = 0;
	while (cin >> num)
		s.PrintNumFib(num);
	return 0;
}
