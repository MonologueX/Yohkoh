#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
	void PrintResultOfCal(std::string s1, std::string s2)
	{
		// 求 a 的分子分母
		size_t pos = s1.find('/');
		a_numerator = atol(s1.substr(0, pos).c_str());
		a_denominator = atol(s1.substr(pos + 1, s1.size()).c_str());
		
		// 求 b 的分子分母
		pos = s2.find('/');
		b_numerator = atol(s2.substr(0, pos).c_str());
		b_denominator = atol(s2.substr(pos + 1, s2.size()).c_str());
		
		// 通分分子分母
		Molecul(a_numerator, a_denominator);
		Molecul(b_numerator, b_denominator);
		
		// 四种运算
		PrintAdd();
		PrintSub();
		PrintMul();
		PrintDiv();
	}
private:
	// 把运算结果连接起来
	void CalToString(std::string op)
	{
		result += NumToStr(a_numerator, a_denominator);
		result += op;
		result += NumToStr(b_numerator, b_denominator);
		result += " = ";
		// 除法分母为 0
		if (op == " / " && res_denominator == 0)
		{
			result += "Inf";
			return;
		}
		result += NumToStr(res_numerator, res_denominator);
	}

	// 通分
	void Molecul(long& numerator, long& denominator)
	{
		long temp = abs(numerator) > abs(denominator) ? abs(denominator) : abs(numerator);
		for (long i = 2; i <= temp; i++)
		{
			if (numerator%i == 0 && denominator%i == 0)
			{
				numerator /= i;
				denominator /= i;
				temp /= i;
				--i;
			}
		}
	}

	// 将分数转换为字符串
	std::string NumToStr(long numerator, long denominator)
	{
		bool flag = true;
		std::string str = "";

		// 小于 0
		if (numerator < 0)
		{
			str += "(-";
			numerator = abs(numerator);
			flag = false;
		}

		if (numerator == 0)
			str += "0";
		else
		{
			// 分子 > 分母
			if (numerator > denominator)
			{
				str += std::to_string(numerator / denominator);
				numerator = numerator%denominator;
				if (numerator != 0)
					str += " ";
			}

			if (numerator != 0)
				str += std::to_string(numerator);
			
			if (denominator > 1)
			{
				str += '/';
				str += std::to_string(denominator);
			}
		}
		if (!flag)
			str += ')';
		return str;
	}

	// 加法
	void PrintAdd()
	{
		result = "";
		res_numerator = a_numerator*b_denominator + b_numerator*a_denominator;
		res_denominator = a_denominator*b_denominator;
		Molecul(res_numerator, res_denominator);
		CalToString(" + ");
		cout << result << endl;
	}

	// 减法
	void PrintSub()
	{
		result = "";
		res_numerator = a_numerator*b_denominator - b_numerator*a_denominator;
		res_denominator = a_denominator*b_denominator;
		Molecul(res_numerator, res_denominator);
		CalToString(" - ");
		cout << result << endl;
	}

	// 乘法
	void PrintMul()
	{
		result = "";
		res_numerator = a_numerator*b_numerator;
		res_denominator = a_denominator*b_denominator;
		Molecul(res_numerator, res_denominator);
		CalToString(" * ");
		cout << result << endl;
	}

	// 除法
	void PrintDiv()
	{
		result = "";
		res_numerator = a_numerator*b_denominator;
		res_denominator = a_denominator*b_numerator;

		// 如果分母小于 0，将分母变为正的
		if (res_denominator < 0)
		{
			res_denominator = 0 - res_denominator;
			res_numerator = 0 - res_numerator;
		}
		Molecul(res_numerator, res_denominator);
		CalToString(" / ");
		cout << result << endl;
	}
private:
	long a_numerator;
	long b_numerator;
	long a_denominator;
	long b_denominator;
	long res_numerator;
	long res_denominator;
	std::string result;
};

int main()
{
	std::string s1, s2;
	while (cin >> s1 >> s2)
	{
		Solution s;
		s.PrintResultOfCal(s1, s2);
	}
	return 0;
}
