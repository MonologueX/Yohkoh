#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int LIS(std::vector<int> array)
	{
		MaxV.resize(array.size() + 1);
		int min = array[0];
		for (size_t i = 1; i < array.size(); i++)
		{
			if (array[i] < min)
				min = array[i];
		}
		MaxV[0] = min - 1;
		MaxV[1] = array[0];

		Lis.resize(array.size(), 1);

		nMaxLis = 1;

		for (size_t i = 1; i < array.size(); i++)
		{
			int j;
			for (j = nMaxLis; j >= 0; j--)
			{
				if (array[i] > MaxV[j])
				{
					Lis[i] = j + 1;
					break;
				}
			}

			if (Lis[i] > nMaxLis)
			{
				nMaxLis = Lis[i];
				MaxV[Lis[i]] = array[i];
			}
			else if (MaxV[j] < array[i] && array[i] < MaxV[j + 1])
			{
				MaxV[j + 1] = array[i];
			}
		}
		return nMaxLis;
	}
private:
	std::vector<int> MaxV;
	std::vector<int> Lis;
	int nMaxLis;
};

void Test()
{
	std::vector<int> array{ 1, -1, 2, -3, 4, -5, 6, -7 };
	Solution s;
	cout << s.LIS(array) << endl;
}
