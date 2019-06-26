#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void Shuffling(std::vector<int>& array, int size, int times)
	{
		for (int i = 0; i < times; i++)
			_Shuffling(array, size);
		Print(array);
	}
private:
	void _Shuffling(std::vector<int>& array, int size)
	{
		std::vector<int> temp;
		temp.resize(size * 2);
		int count = 0;
		// 123456
		// 142536
		for (int i = 0; i < size; i++)
		{
			temp[count++] = array[i];
			temp[count++] = array[size+i];
		}
		array = temp;
	}
	void Print(std::vector<int> array)
	{
		cout << array[0];
		for (size_t i = 1; i < array.size(); i++)
		{
			cout << " " << array[i];
		}
		cout << endl;
	}
};

int main()
{
	int num = 0;
	int times = 0, size = 0;
	cin >> num;
	for (auto i = 0; i < num; i++)
	{
		cin >> size >> times;
		std::vector<int> array;
		array.resize(2 * size);
		for (auto i = 0; i < 2 * size; i++)
			cin >> array[i];
		Solution s;
		s.Shuffling(array, size, times);
	}
	return 0;
}
