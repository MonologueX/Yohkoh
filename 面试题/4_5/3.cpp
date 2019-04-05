#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int GetNum(vector<int> array1, vector<int> array2)
	{
		int index = array1[0];
		int result = array2[0];
		for (int i = 1; i < array1.size(); i++)
		{
			if (array1[i] > index)
			{
				index += array1[i];
				result += array2[i];
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> array1;
	vector<int> array2;
	int num = 0;
	cin >> num;
	array1.resize(num);
	array2.resize(num);
	int temp = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		array1[i] = temp;
	}
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		array2[i] = temp;
	}
	cout << s.GetNum(array1, array2) << endl;
	return 0;
}
