#include <iostream>
#include <vector>

using namespace std;

int GetResult(vector<vector<int>> array, int w, int h)
{
	if (w <= 2 && h <= 2)
		return w*h;
	int result = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (0 == array[i][j])
			{
				result++;
				if ((i + 2) < w)
				{
					array[i + 2][j] = 1;
				}
				if ((j + 2) < h)
				{
					array[i][j + 2] = 1;
				}
			}
		}
	}
	return result;
}

int main()
{
	int num[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		cin >> num[i];
	}

	vector<vector<int>> array;
	array.resize(num[0]);

	for (auto & e : array)
		e.resize(num[1], 0);

	int result = GetResult(array, num[0], num[1]);
	cout << result << endl;
	return 0;
}
