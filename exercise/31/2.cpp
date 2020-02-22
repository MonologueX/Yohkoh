// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	void Factorization(int num)
	{
		result = "";
		result += std::to_string(num);
		result += " = ";
		while (num > 1)
		{
			while ((num & 1) == 0)
			{
				num >>= 1;
				result += '2';
				if (num < 2)
					break;
				result += " * ";
			}
			while (num % 3 == 0)
			{
				num /= 3;
				result += '3';
				if (num < 2)
					break;
				result += " * ";
			}
			int count = 5;
			while (num >= 5)
			{
				if (num % count == 0)
				{
					num /= count;
					result += std::to_string(count);
					if (num < 2)
						break;
					result += " * ";
					continue;
				}
				count += 2;
			}
		}
		cout << result << endl;
	}
private:
	std::string result;
};

int main()
{
	int num;
	Solution s;
	while (cin >> num)
	{
		s.Factorization(num);
	}
	return 0;
}  
