#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int size1 = str1.size();
	int size2 = str2.size();
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (str1[i] == str2[j])
			{
				int k = i;
				for (k = i; k < size1; k++)
				{
					str1[k] = str1[k + 1];
				}
				size1--;
				str1.resize(size1);
			}
		}
	}
	cout << str1 << endl;
	return 0;
}
