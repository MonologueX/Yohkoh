// write your code here cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution
{
public:
	Solution()
	{
		fib[0] = 1;
		fib[1] = 1;
		for (auto i = 2; i<10001; i++)
			fib[i] = (fib[i - 1] % 10000 + fib[i - 2] % 10000) % 10000;
	}
	void PrintResult(int num)
	{
		int temp = 0;
		for (auto i = 0; i < num; i++)
		{
			cin >> temp;
			cout << setw(4) << setfill('0') << fib[temp];
		}
		cout << endl;
	}
private:
	int fib[10001];
};

int main()
{
	int num = 0;
	while (cin >> num)
	{
		Solution s;
		s.PrintResult(num);
	}
	return 0;
}
