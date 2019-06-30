// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	void Result(std::string num)
	{
		while (num.size() > 1)
		{
			int temp = 0;
			for (auto i = 0; i < num.size(); i++)
			{
				temp += num[i] - '0';
			}
			num = std::to_string(temp);
		}
		cout << num << endl;
	}
};

int main()
{
	std::string num;
	while (cin >> num)
	{
		Solution s;
		s.Result(num);
	}
	return 0;
}
