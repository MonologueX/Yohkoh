#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Solution
{
public:
	T GetNum(T num, T max)
	{
		std::vector<T> array;
		array.resize(num);
		T result = 0;
		T index = 0;
		for (T i = 0; i < num; i++)
		{
			cin >> array[i];
			while (i >= 2 && index <= i && array[i] - array[index]  > max)
				index++;
			if (i - index >= 2)
				result += Cal(i - index - 1);
		}
		return result % 99997867;
	}
private:
	T Cal(T num)
	{
		if (num <= 0)
			return 0;
		return ((num + 1) * num) >> 1;
	}
};

int main()
{
	long long num, max;
	Solution<long long> s;
	while (cin >> num >> max)
	{
		cout << s.GetNum(num, max) << endl;
	}
	return 0;
}
