class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int A = 1;
		int B = 1;
		int a_min = 100;
		int b_min = 100;
		int a_sum = 1;
		int b_sum = 1;
		for (auto i = 0; i < n; i++)
		{
			if (left[i] == 0)
			{
				B += right[i];
				continue;
			}
			if (right[i] == 0)
			{
				A += left[i];
				continue;
			}
			a_sum += left[i];
			b_sum += right[i];
			if (left[i] < a_min)
				a_min = left[i];
			if (right[i] < b_min)
				b_min = right[i];
		}
		if (a_sum > b_sum)
			return A + B + b_sum - b_min - 1;
		else
			return A + B + a_sum - a_min - 1;
	}
};
