nclude<iostream>
#include <vector>

void menu()
{
	std::cout << "#####################################################" << std::endl;
	std::cout << "######              杨 辉 三 角                ######" << std::endl;
	std::cout << "#####################################################" << std::endl;
	std::cout << "######               1. 计 算                  ######" << std::endl;
	std::cout << "######               0. 退 出                  ######" << std::endl;
	std::cout << "#####################################################" << std::endl;
}

int main()
{
	int num[2];
	std::vector<int> v;
	for (;;)
	{
		int choise = 0;
		while (1)
		{
			menu();
			std::cin >> choise;
			if (1 == choise)
				break;
			else if (0 == choise)
				return 0;
			else
				continue;
		}
		std::cout << "请输入坐标（n m）：";
		for (int i = 0; i < 2; i++)
		{
			std::cin >> num[i];
		}
		int m = num[1];
		num[1]--;
		std::vector<int> v2(m, 0);
		if (num[0] == 1)
			std::cout << '1' << std::endl;
		else
		{
			if (num[0] < 2 * num[1])
				num[1] = num[0] - num[1];
			v.push_back(1);
			for (int i = num[0]; i >= num[1]; --i)
			{
				int len = v.size();
				for (int j = 0; j < len; ++j)
				{
					v[j] *= i;
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
			std::cout << "Yang Hui's Triangle(" << num[0] << "," << m << ") = ";
			int len = v.size();
			for (int i = 0; i < len; ++i)
			{
				std::cout << v[i];
			}
			std::cout << std::endl;
		}
		v.clear();
	}
	return 0;
}
