#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		m_result = _restoreIpAddresses(s);
		return m_result;
	}
private:
	vector<string> _restoreIpAddresses(string s)
	{
		int flag = 0;
		string temp;
		for (int i = 1; i < 4; i++)
		{
			// 处理第一个数字为 0
			if (flag == 1)
				break;
			if (s[0] == '0')
			{
				m_a = 0;
				flag = 1;
			}
			else
			{
				// 第一个数字不为0
				temp = s.substr(0, i);
				if (!Judge(temp, m_a))
					break;
			}

			for (int j = 1; j < 4; j++)
			{
				// 无法构成 IP
				if (s.size() - i > 9 || s.size()-i < 3)
					break;

				// b 符合更新，不符合跳出循环
				temp = s.substr(i, j);
				if (!Judge(temp, m_b))
					break;

				for (int k = 1; k < 4; k++)
				{
					if (s.size() - i - j > 6 || s.size()-i-j < 2)
						break;

					// c 符合更新，不符合跳出循环
					temp = s.substr(i + j, k);
					if (!Judge(temp, m_c))
						break;

					if (s.size() - i - j - k > 3 || s.size()-i-j-k == 0)
						continue;

					// d 符合更新，不符合结束当前循环，注意不可跳出循环
					// c 和 d 在同一循环当中
					temp = s.substr(i + j + k);					
					if (!Judge(temp, m_d))
						continue;
					else
					{
						string temp = Print(s, i, i + j, i + j + k);
						m_result.push_back(temp);
					}
				}
			}		
		}
		return m_result;
	}

	// 加入 .
	string Print(string str, int a, int b, int c)
	{
		string s;
        int size = str.size();
		for (int i = 0; i < size; i++)
		{
			if (i == a || i == b || i == c)
				s += '.';
			s += str[i];
		}
		return s;
	}

	// 判断是否符合，并更新，需传引用
	bool Judge(string s, int& num)
	{
		if (s.size() > 1)
		{
			if (s[0] == '0')
				return false;
		}
		int _num = atoi(s.c_str());
		if (_num > 255 || _num < 0)
			return false;
		// 更新 num
		num = _num;
		return true;
	}
	
private:
	int m_a;
	int m_b;
	int m_c;
	int m_d;
	vector<string> m_result;
};

int main()
{
	std::string str;
	while (cin >> str)
	{
		Solution s;
		s.restoreIpAddresses(str);
	}
	return 0;
}
