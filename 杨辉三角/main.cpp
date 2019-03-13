#include "YangHui.h"

void menu()
{
	std::cout << "#####################################################" << std::endl;
	std::cout << "######              杨 辉 三 角                ######" << std::endl;
	std::cout << "#####################################################" << std::endl;
	std::cout << "######               1. 计 算                  ######" << std::endl;
	std::cout << "######               0. 退 出                  ######" << std::endl;
	std::cout << "#####################################################" << std::endl;
	std::cout << "请选择>";
}

YangHui::YangHui(int n, int m)
{
	m_n.resize(m);
	for (int i = 0; i < m; i++)
	{
		m_n[i] = n - i;
	}
	m_m.resize(m);
	for (int i = 0; i < m; i++)
	{
		m_m[i] = m - i;
	}
}

void YangHui::Adjust()
{
	Adjust1(m_n, m_m);
	Adjust2(m_m);
	Adjust1(m_n, m_m);
}

void YangHui::Adjust1(std::vector<int>& n, std::vector<int>& m)
{
	int count = 0;
	if (0 == m.size() || 0 == n.size())
		return;
	for (size_t i = 0; i < n.size(); i++)
	{
		for (size_t j = 0; j < m.size(); j++)
		{
			if (0 == n[i] % m[j])
			{
				n[i] = n[i] / m[j];
				m.erase(m.begin() + j);
				j--;
				count++;
			}
			if (1 == n[i])
			{
				n.erase(n.begin() + i);
				count++;
				i--;
				break;
			}
		}
	}
	if (count == 0)
		return;
	Adjust1(m, n);
}

void YangHui::Adjust2(std::vector<int>& m)
{
	if (0 == m.size())
		return;
	int size = m.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 2; j <= m[i]; j++)
		{
			if (0 == m[i] % j)
			{
				m[i] /= j;
				m.push_back(j);
				j--;
			}
		}
	}
}

void YangHui::GetResult()
{
	Cal(m_n);
}

void YangHui::Cal(std::vector<int>& n)
{
	Adjust();
	std::vector<int> v;
	v.push_back(1);
	for (size_t i = 0; i < n.size(); ++i)
	{
		int len = v.size();
		for (int j = 0; j < len; ++j)
		{
			v[j] *= n[i];
		}
		int jinwei = 0;
		for (int j = len - 1; j >= 0; --j)
		{
			int temp = jinwei + v[j];
			jinwei = temp / 10;
			v[j] = temp % 10;
		}
		while (jinwei)
		{
			v.insert(v.begin(), jinwei % 10);
			jinwei /= 10;
		}
	}
	std::cout << "结果：";
	int len = v.size();
	for (int i = 0; i < len; ++i)
	{
		std::cout << v[i];
	}
	std::cout << std::endl;
	v.clear();
}

void Result()
{
	int num[2];
	std::cout << "请输入坐标（n m）：";
	for (int i = 0; i < 2; i++)
	{
		std::cin >> num[i];
	}

	if (num[0] < num[1])
	{
		std::cout << "n > m" << std::endl;
		return;
	}
	num[1]--;
	num[0]--;
	if (num[0] < 2 * num[1])
		num[1] = num[0] - num[1];
	YangHui h(num[0], num[1]);
	h.GetResult();
}

int main()
{
	int choise = 0;
	while (1)
	{
		menu();
		std::cin >> choise;
		if (1 == choise)
			Result();
		else if (0 == choise)
			break;
		else
			continue;
	}
	return 0;
}
