#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;
	vector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		cin >> v[i];
	}
	int result = v[0];
	int sun = 0;
	for (int i = 0; i < size; i++)
	{
		sun += v[i];
		if (sun > result)
			result = sun;
		if (sun < 0)
			sun = 0;
	}
	cout << sun << endl;
	return 0;
}
