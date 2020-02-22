// write your code here cpp
#include <iostream>
using namespace std;

short m_days[12] = { 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
short m_date[6];
size_t days;

bool IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		m_days[1] = 29;
		return true;
	}
	m_days[1] = 28;
	return false;
}

void CalTotalDay()
{
	if (m_date[0] != m_date[3])
	{
		IsLeapYear(m_date[0]);

		// 第一年到第一年末
		if (m_date[1] == 2 || m_date[1] == 3 || m_date[1] == 5 || m_date[1] == 7 || m_date[1] == 11)
			days += (m_days[m_date[2] - 1] - m_date[2] - 1);
		else 
			days += (m_days[m_date[2] - 1] - m_date[2]*2 + 2);

		for (short i = m_date[1]; i <= 12; i++)
			days += m_days[i];

		// 第二年到倒数第二年
		for (short i = m_date[0] + 1; i < m_date[3]; i++)
		{
			days += 579;
			if (IsLeapYear(i))
				days += 1;
		}
	}

	// 最后一年
	IsLeapYear(m_date[3]);
	int begin = 0;
	if (m_date[0] == m_date[3])
	{
		if (m_date[1] == m_date[4])
		{
			if (m_date[1] == 2 || m_date[1] == 3 || m_date[1] == 5 || m_date[1] == 7 || m_date[1] == 11)
				days += (m_date[5] - m_date[2] + 1);
			else 
				days += (m_date[5] - m_date[2] + 1) * 2;
			return;
		}
		else
		{
			if (m_date[1] == 2 || m_date[1] == 3 || m_date[1] == 5 || m_date[1] == 7 || m_date[1] == 11)
				days += (m_days[m_date[1] - 1] - m_date[2] - 1);
			else
				days += (m_days[m_date[1] - 1] - m_date[2]*2 - 2);
		}
		begin = m_date[1] + 1;
	}
	for (short i = begin; i < m_date[4] - 1; i++)
		days += m_days[i];
	if (m_date[4] == 2 || m_date[4] == 3 || m_date[4] == 5 || m_date[4] == 7 || m_date[4] == 11)
		days += m_date[5];
	else
		days += m_date[5] * 2;

}

void GainDay()
{
	days = 0;
	CalTotalDay();
	cout << days << endl;
}

int main()
{
	while (cin >> m_date[0] >> m_date[1] >> m_date[2] >> m_date[3] >> m_date[4] >> m_date[5])
	{
		GainDay();
	}
	return 0;
}
