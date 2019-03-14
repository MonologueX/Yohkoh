#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.clear();
	int num = 0;
	while (cin >> num)
	{
		v.push_back(num);
		if (getchar() == '\n')
			break;
	}
	int size = v.size();
	sort(v.begin(), v.end());
	if (1 == (size % 2))
		cout << v[size / 2] << endl;
	else
	{
		if (v[0] == v[size / 2 - 1])
			cout << v[size / 2 - 1];
		else
			cout << v[size / 2 - 1];
	}
	return 0;
}
