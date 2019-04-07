// write your code here cpp
#include <iostream>
using namespace std;

class Solution
{
public:
	void GetMiMa()
	{
		int c;
		while ((c = getchar()) != EOF)
		{
			if ('A' <= c)
			{
				c = 'E' < c ? (c - 5) : (c + 21);
			}
			putchar(c);
		}
	}
};

int main()
{
	Solution s;
	s.GetMiMa();
	return 0;
} 
