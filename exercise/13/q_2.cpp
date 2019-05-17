/*

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INT_MAX 100001
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> dp(m + 1, INT_MAX);
		dp[n] = 0;
		for (int i = n; i <= m; i++)
		{
			for (int j = 2; j*j <= i; j++)
			{
				if (i%j == 0)
				{
					if (i + j <= m)
						dp[i + j] = min(dp[i + j], dp[i] + 1);
					if (i + i / j <= m)
						dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
				}
			}
		}
		if (dp[m] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << dp[m] << endl;
	}
}

 */ 

#include <iostream>
#include <math.h>
using namespace std;
 
class Solution
{
public:
    void PrintMinNum(int n, int m)
    {
        int count = 0;
        while (n < m)
        {
            int divisor = GainMaxDivisor(n);
            if (-1 == divisor)
            {
                cout << divisor << endl;
                return;
            }
            n += divisor;
            count++;
        }
        cout << count << endl;
    }
private:
    int GainMaxDivisor(int num)
    {
        for (auto i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
                return (num / i);
        }
        return -1;
    }
};
 
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Solution s;
        s.PrintMinNum(n, m);
    }
    return 0;
}

