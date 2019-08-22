#include <iostream>
#include <vector>
using namespace std;

void DFS(int index, int n, vector<int>& box, vector<int>& used)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			box[index] = i;
			DFS(index + 1, n, box, used);
			used[i] = 0;
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		std::vector<int> box(n + 1, 0);
		std::vector<int> used(n + 1, 0);
		DFS(1, n, box, used);
	}
	return 0;
}
