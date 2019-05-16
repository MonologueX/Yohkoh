#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	Solution()
		: m_sum(0)
		, m_str(0)
		, m_STR(0)
		, m_num(0)
		, m_symbal(0)
	{}
	void Print(std::string str)
	{
		CalSum(str);
		if (m_sum >= 90)
			cout << "VERY_SECURE" << endl;
		else if (m_sum >= 80)
			cout << "SECURE" << endl;
		else if (m_sum >= 70)
			cout << "VERY_STRONG" << endl;
		else if (m_sum >= 60)
			cout << "STRONG" << endl;
		else if (m_sum >= 50)
			cout << "AVERAGE" << endl;
		else if (m_sum >= 25)
			cout << "WEAKE" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
private:
	void CalSum(std::string str)
	{
		Length(str);
		StrChar(str);
		Num(str);
		Symbal(str);
		int temp = m_str + m_STR;
		if (m_num > 0 && temp > 0)
		{
			if (temp == 2 && m_symbal > 0)
				m_sum += 5;
			else if (temp == 1 && m_symbal > 0)
				m_sum += 3;
			else
				m_sum += 2;
		}
	}

	void Length(std::string str)
	{
		if (str.size() >= 8)
			m_sum += 25;
		else if (str.size() >= 5)
			m_sum += 10;
		else
			m_sum += 5;
	}

	void StrChar(std::string str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				m_STR = 1;
			if (str[i] >= 'a' && str[i] <= 'z')
				m_str = 1;
		}
		m_sum += (10 * (m_str + m_STR));
	}

	void Num(std::string str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				m_num++;
		}
		if (m_num == 1)
			m_sum += 10;
		if (m_num > 1)
			m_sum += 35;
	}

	void Symbal(std::string str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (!(str[i] >= 65 && str[i] <= 90)
				&& !(str[i] >= 97 && str[i] <= 122)
				&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
				m_symbal++;
		}
		if (m_symbal == 1)
			m_sum += 10;
		if (m_symbal > 1)
			m_sum += 25;
	}

private:
	int m_sum;
	int m_str;
	int m_STR;
	int m_num;
	int m_symbal;
};

int main()
{
	std::string str;
	while (getline(cin, str))
	{
		Solution s;
		s.Print(str);
		str.clear();
	}
	return 0;
}
