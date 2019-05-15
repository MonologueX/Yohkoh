#include <iostream>
using namespace std;

class Solution
{
public:
	void PrintNum(long long A, long long B)
	{
		long long temp = 2;
		while (temp <= A && temp <= B)
		{
			if (A%temp == 0 && B%temp == 0)
			{
				A /= temp;
			}
			temp++;
		}
		cout << A*B << endl;
	}
};

int main()
{
	long long A, B;
	cin >> A >> B;
	Solution s;
	s.PrintNum(A, B);
	return 0;
}
