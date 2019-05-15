/*
#include <iostream>
using namespace std;

class Solution
{
public:
    int PrintNum(int n, int m)
    {
        if(n > 1 && m > 1)
            return PrintNum(n-1,m) + PrintNum(n,m-1);
        else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1)))
            return n + m;
        else
            return 0;
    }
};

int main()
{
    int n, m;
    Solution s;
    while (cin >> n >> m)
    {
        cout << s.PrintNum(n, m) << endl;
    }
    return 0;
}
*/ 
#include <iostream>
using namespace std;

class Solution
{
public:
	int PrintNum(int n, int m)
	{
		if (n < m)
			swap(n, m);
		if (m == 0 || n == 0)
			return 1;
		int temp = n - m;
		for (int i = n-1; i > 1; i--)
			n *= i;
		for (int i = m-1; i > 1; i--)
			m *= i;
		for (int i = temp; i > 1; i--)
			m *= i;
		return n/m;
	}
};

int main()
{
	int n, m;
	Solution s;
	while (cin >> n >> m)
	{
		cout << s.PrintNum(m+n, m) << endl;
	}
	return 0;
}
