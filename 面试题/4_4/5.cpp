#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		
		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = 0;
		for (size_t i = 0; i < arr.size(); i++)
		{
			max += arr[i];
		}
		int result = max;
		std::vector<int> array;
		for (int i = 0; i < arr.size(); i++)
		{
			int temp = i;
			while (temp + min != arr[i])
			{
				if (arr[i] > temp)
				{
					while (arr[i] > temp)
					{
						array.push_back(temp++);
					}
				}
			}
			i = array[i];
			i--;
		}
	}
};
