#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int result = 0;
	int index_result = 0;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		if (s[i] < '9' && s[i] > '0')
		{
			int count = 1;
			int index = i;
			while (i < (size - 1))
			{
				i++;
				if (s[i] <= '9' && s[i] >= '0')
					count++;
				else
				{
					break;
				}
			}
			if (count > result)
			{
				result = count;
				index_result = index;
			}
		}
	}
	for (int i = 0; i < result; i++)
	{
		cout << s[index_result + i];
	}
	cout << endl;
	return 0;
}
