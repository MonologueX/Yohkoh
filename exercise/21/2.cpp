#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	Solution()
		: index(1)
		, begin(1)
		, size(4)
	{}

	void Print(int num, std::string str)
	{
		if (num < 4)
			size = num;
		CalResult(num, str);
		for (auto i = 0; i < size; i++)
			cout << begin + i << " ";
		cout << endl;
		cout << index << endl;
	}
private:
	void CalResult(int num, std::string str)
	{
		for (auto i = 0; i < str.size(); i++)
		{
			if (str[i] == 'U')
				index--;
			else
				index++;
			GetIndexBegin(num);
		}
	}
	void GetIndexBegin(int num)
	{
		if (index <= 0)
		{
			index = num;
			begin = num-size+1;
		}
		else if (index > num)
		{
			index = 1;
			begin = 1;
		}
		else
		{
			if (index < begin)
				begin--;
			if (index - begin >= size)
				begin++;
		}
	}
private:
	int index;
	int begin;
	int size;
};

int main()
{
	int num = 0;
	std::string str;
	while (cin >> num >> str)
	{
		Solution s;
		s.Print(num, str);
	}
	return 0;
}
