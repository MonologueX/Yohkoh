#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	vector<int> tangos(N);
	for (int i = 0; i < N; i++)
		cin >> tangos[i];

	// 统计三个数的数目
	int num1 = 0, num2 = 0, num3 = 0;
	int tango1 = -1, tango2 = -1, tango3 = -1;

	for (int i = 0; i < tangos.size(); i++) 
	{
		if (num1 == 0 && tangos[i] != tango1) 
		{
			tango1 = tangos[i];
			num1++;
		}
		else if (num2 == 0 && tangos[i] != tango2) 
		{
			tango2 = tangos[i];
			num2++;
		}
		else if (num3 == 0 && tangos[i] != tango3) 
		{
			tango3 = tangos[i];
			num3++;
		}
		else if (tangos[i] == tango1)
			num1++;
		else if (tangos[i] == tango2)
			num2++;
		else if (tangos[i] == tango3)
			num3++;
		else 
		{
			num1--;
			num2--;
			num3--;
		}
	}
	cout << tango1 << " " << tango2 << " " << tango3 << endl;
	return 0;
}
