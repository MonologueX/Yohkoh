class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7)
			return index;
		std::vector<int> arr(index);
		arr[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < index; i++)
		{
			arr[i] = min(arr[t2] * 2, min(arr[t3] * 3, arr[t5] * 5));
			while (arr[t2] * 2 <= arr[i])
				t2++;
			while (arr[t3] * 3 <= arr[i])
				t3++;
			while (arr[t5] * 5 <= arr[i])
				t5++;
		}
		return arr[index - 1];
	}
};
