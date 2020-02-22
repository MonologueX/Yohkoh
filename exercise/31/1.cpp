// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void PrintDate(int year)
	{
		NewYearsDay(year);
		MartinLutherKingDay(year);
		PresidentsDay(year);
		MemorialDayForTheDead(year);
		NationalDay(year);
		LaborDay(year);
		Thanksgiving(year);
		Christmas(year);
	}
private:
	void CaculateWeekDay(int y, int m, int d)
	{
		if (m == 1 || m == 2)
		{
			m += 12;
			y--;
		}
		int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
		m_week = Week + 1;
	}

	// 1月1日：元旦
	void NewYearsDay(int year)
	{
		cout << year << "-01-01" << endl;
	}

	// 1月的第三个星期一：马丁·路德·金纪念日
	void MartinLutherKingDay(int year)
	{
		m_day = 15;
		CaculateWeekDay(year, 1, 1);
		if (m_week != 1)
			m_day = 23 - m_week;
		cout << year << "-01-" << m_day << endl;
	}
	// 2月的第三个星期一：总统节
	void PresidentsDay(int year)
	{
		m_day = 15;
		CaculateWeekDay(year, 2, 1);
		if (m_week != 1)
			m_day = 23 - m_week;
		cout << year << "-02-" << m_day << endl;
	}
	// 5月的最后一个星期一：阵亡将士纪念日
	void MemorialDayForTheDead(int year)
	{
		CaculateWeekDay(year, 5, 31);
		m_day = 32 - m_week;
		cout << year << "-05-" << m_day << endl;
	}
	// 7月4日：美国国庆
	void NationalDay(int year)
	{
		cout << year << "-07-04" << endl;
	}
	// 9月的第一个星期一：劳动节
	void LaborDay(int year)
	{
		m_day = 1;
		CaculateWeekDay(year, 9, 1);
		if (m_week != 1)
			m_day = 9 - m_week;
		cout << year << "-09-0" << m_day << endl;
	}
	// 11月的第四个星期四：感恩节
	void Thanksgiving(int year)
	{
		CaculateWeekDay(year, 11, 1);
		if (m_week <= 4)
			m_day = 26 - m_week;
		else
			m_day = 33 - m_week;
		cout << year << "-11-" << m_day << endl;
	}
	// 12月25日：圣诞节
	void Christmas(int year)
	{
		cout << year << "-12-25" << endl;
	}
private:
	int m_week;
	int m_day;
};

int main()
{
	int year;
	Solution s;
	while (cin >> year)
	{
		s.PrintDate(year);
		cout << endl;
	}
	return 0;
}
