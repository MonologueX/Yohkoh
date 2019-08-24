#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void GetResult(std::vector<int> array)
	{
		std::vector<int> cur;
		sort(array.begin(), array.end());
		for (int i = 1; i < array.size(); i++)
		{
			int size = cur.size();
			if (array[i] == array[i - 1])
				cur.push_back(array[i]);
			while (array[i] == array[i - 1])
			{
				i++;
			}
			if (cur.size() != size)
				i--;
		}
		cout << cur.size() << endl;
		for (auto i = 0; i < cur.size(); i++)
			cout << cur[i] << " ";
		cout << endl;
	}
};

int  main()
{
	std::vector<int> array;
	int n, m;
	Solution s;
	while (cin >> n >> m)
	{
		array.resize(m*2);
		fflush(stdout);
		for (int i = 0; i < 2*m; i++)
		{
			cin >> array[i];
		}
		s.GetResult(array);
	}
	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//	long long  GetResult(std::vector<long long > array, long long  num)
//	{
//		if (num <= 2)
//			return 1;
//		long long  result = 1;
//		for (long long  i = 1; i < num; i++)
//		{
//			if (array[i] >= array[i - 1])
//			{
//				result++;
//			}
//		}
//		return result;
//	}
//};
//
//
//int  main()
//{
//	std::vector<long long > array;
//	long long  num;
//	Solution s;
//	while (cin >> num)
//	{
//		array.resize(num);
//		for (long long  i = 0; i < num; i++)
//		{
//			cin >> array[i];
//		}
//		cout << s.GetResult(array, num);
//	}
//	return 0;
//}
