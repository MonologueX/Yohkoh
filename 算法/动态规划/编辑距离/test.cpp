#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.empty() || word2.empty())
			return max(word1.size(), word2.size());
		int row = word1.size() + 1;
		int col = word2.size() + 1;
		array.resize(row);
		for (auto & e : array)
			e.resize(col, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (0 == i)
					array[i][j] = j;
				else if (0 == j)
					array[i][j] = i;
				else
				{
					array[i][j] = 1 + min(array[i - 1][j], array[i][j - 1]);
					if (word1[i - 1] == word2[j - 1])
						array[i][j] = min(array[i - 1][j - 1], array[i][j]);
					else
						array[i][j] = min(array[i - 1][j - 1] + 1, array[i][j]);
				}
			}
		}
		return array[row-1][col-1];
	}
private:
	std::vector<std::vector<int> > array;
};
