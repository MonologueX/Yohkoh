#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void GetNum(std::vector<int> array, int num)
	{
		int years = 0;
		int days = 0;
		for (int i = 0; i < num*2; i++)
		{
			years = array[i++];
			days = array[i];
			cout << _GetNum(years, days) <<endl;
		}
	}
private:
	int _GetNum(int years, int days)
	{
		if (days == 30)
			return 7;
		else if (days > 30)
			return 0;
		else
		{
			if (((0 == years % 4) || (0 == years % 100)) && (0 != years % 400))
			{
				if (days >= 28)
					return 11;
				else
					return 12;
			}
			else
			{
				return 12;
			}
		}
	}
};

int main()
{
	int num = 0;
	cin >> num;
	std::vector<int> array;
	array.resize(2 * num);
	int temp = 0;
	for (int i = 0; i < 2 * num; i++)
	{
		cin >> temp;
		array[i] = temp;
	}
	Solution s;
	s.GetNum(array, num);
	return 0;
}
