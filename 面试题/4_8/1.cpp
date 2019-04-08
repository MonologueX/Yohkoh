// write your code here cpp
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int num)
		:m_day(1)
		, m_month(1)
		, m_year(num)
	{}
	void Print()
	{
		PrintDay1();
		PrintDay2();
		PrintDay3();
		PrintDay4();
		PrintDay5();
		PrintDay6();
		PrintDay7();
		PrintDay8();
	}

private:
	// w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
	//2049年10月1日（100周年国庆）为例，用蔡勒（Zeller）公式进行计算，过程如下： 
	//w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1 
	//=49+[49/4]+[20/4]-2×20+[26× (10+1)/10]+1-1 
	//=49+[12.25]+5-40+[28.6] 
	//=49+12+5-40+28 
	//=54 (除以7余5) 
	//w：星期；c：世纪-1；y：年（两位数）；m：月 ；d：日；[ ]代表取整，即只要整数部分。
	// (C是世纪数减一，y是年份后两位，M是月份，d是日数。1月和2月要按上一年的13月和 14月来算，
	// 这时C和y均按上一年取值。)

	int CaculateWeekDay(int y, int m, int d)
	{
		if (m == 1 || m == 2) 
		{
			m += 12;
			y--;
		}
		int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
		return iWeek;
	}

	// CaculateWeekDay
	void PrintDay1()
	{
		std::cout << m_year << "-" << "01" << "-" << "01" << std::endl;
	}

	void PrintDay2()
	{
		int week = CaculateWeekDay(m_year, 1, 1);
		if (1 == week)
		{
			std::cout << m_year << "-" << "01" << "-" << "15" << std::endl;
			return;
		}
		int i = 1;
		for (i = 1; i <= 7; i++)
		{
			week++;
			if (week == 8)
				break;
		}
		std::cout << m_year << "-" << "01" << "-" << m_day + i + 14 << std::endl;
	}

	void PrintDay3()
	{
		int week = CaculateWeekDay(m_year, 2, 1);
		if (1 == week)
		{
			std::cout << m_year << "-" << "02" << "-" << "15" << std::endl;
			return;
		}
		int i = 1;
		for (i = 1; i <= 7; i++)
		{
			week++;
			if (week == 8)
				break;
		}
		std::cout << m_year << "-" << "02" << "-" << m_day + i + 14 << std::endl;
	}

	void PrintDay4()
	{
		int week = CaculateWeekDay(m_year, 5, 31);
		if (1 == week)
		{
			std::cout << m_year << "-" << "05" << "-" << "31" << std::endl;
			return;
		}
		int i = 1;
		for (i = 1; i <= 7; i++)
		{
			week--;
			if (week == 1)
				break;
		}
		std::cout << m_year << "-" << "05" << "-" << 31 - i << std::endl;
	}

	void PrintDay5()
	{
		std::cout << m_year << "-" << "07" << "-" << "04" << std::endl;
	}

	void PrintDay6()
	{
		int week = CaculateWeekDay(m_year, 9, 1);
		if (1 == week)
		{
			std::cout << m_year << "-" << "09" << "-" << "01" << std::endl;
			return;
		}
		int i = 1;
		for (i = 1; i <= 7; i++)
		{
			week++;
			if (week == 8)
				break;
		}
		if (m_day+i < 9)
			std::cout << m_year << "-" << "09" << "-0" << m_day + i << std::endl;
		else 
			std::cout << m_year << "-" << "09" << "-" << m_day + i << std::endl;
	}

	void PrintDay7()
	{
		int week = CaculateWeekDay(m_year, 11, 1);
		if (4 == week)
		{
			std::cout << m_year << "-" << "11" << "-" << "22" << std::endl;
			return;
		}
		int i = 1;
		for (i = 1; i <= 7; i++)
		{
			week++;
			if (week%7 == 4)
				break;
		}
		std::cout << m_year << "-" << "11" << "-" << m_day + i + 21 << std::endl;
	}

	void PrintDay8()
	{
		std::cout << m_year << "-" << "12" << "-" << "25" << std::endl;
	}
private:
	int m_day;
	int m_month;
	int m_year;
};

int main()
{
	int num;
	while (cin >> num)
	{
		Date d(num);
		d.Print();
		std::cout << std::endl;
	}
	return 0;
}

