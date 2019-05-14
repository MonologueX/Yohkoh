#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void PrintMaxNum(int w, int h)
	{
		int result = 0;
		array.resize(w);
		for (auto& e : array)
			e.resize(h, 1);
		for (auto i = 0; i < w; i++)
		{
			for (auto j = 0; j < h; j++)
			{
				if (1 == array[i][j])
				{
					result++;
					if (i + 2 < w)
						array[i + 2][j] = 0;
					if (j + 2 < h)
						array[i][j + 2] = 0;
				}
			}
		}
		cout << result << endl;
	}
private:
	std::vector<std::vector<int> > array;
};

int main()
{
	int w = 0;
	int h = 0;
	cin >> w >> h;
	Solution s;
	s.PrintMaxNum(w, h);
	return 0;
}
