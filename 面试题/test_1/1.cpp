#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.clear();
	int n = 0;
	long long num = 0;
	cin >> n;
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); 
	long long result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += v[3*n - 2*i];
	}
	cout << result << endl;
	return 0;
}
