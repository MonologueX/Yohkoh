#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	str.clear();
	getline(cin, str);
	int size = str.size();
	for (int i = size - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			for (int j = i + 1; j < size; j++)
			{
				cout << str[j];
			}
			cout << " ";
			size = i;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << str[i];
	}
	cout << endl;
	return 0;
}
