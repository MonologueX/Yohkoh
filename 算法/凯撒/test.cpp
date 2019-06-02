#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Caesar
{
public:
	void caesar()
	{
		while (1)
		{
			Menu();
			cout << "请选择：";
			cin >> model;
			if (model == 3)
				return;
			cout << "请输入字符串:";
			fflush(stdin);
			getline(cin, str);
			cout << "请输入该密码算法的偏移数量：";
			cin >> numB;
			if (model == 1)
				Encry(str, numB, model);
			else if (model == 2)
				Decry(str, numB, model);
		}
	}
private:
	void Encry(std::string strI, int numB, int model)
	{
		if (model == 1)
		{
			for (size_t i = 0; i<strI.size(); i++)
			{
				if (strI[i] >= 'A' && strI[i] <= 'Z')
					strI[i] = ((strI[i] - 'A') + numB) % 26 + 'A';
				else if (strI[i] >= 'a' && strI[i] <= 'z')
					strI[i] = ((strI[i] - 'a') + numB) % 26 + 'a';
			}
			cout << "加密完成：" << strI << endl;
		}
	}

	void Decry(std::string strI, int numB, int model)
	{
		if (model == 2)
		{
			int num;
			num = 26 - numB;
			for (size_t i = 0; i<strI.size(); i++)
			{
				if (strI[i] >= 'A' && strI[i] <= 'Z')
					strI[i] = ((strI[i] - 'A') + num) % 26 + 'A';
				else if (strI[i] >= 'a' && strI[i] <= 'z')
					strI[i] = ((strI[i] - 'a') + num) % 26 + 'a';
			}
			cout << "解密完成：" << strI << endl;
		}
	}

	void Menu()
	{
		cout << "\t\t凯撒密码：请选择模式:\n";
		cout << "\t1.加密\n";
		cout << "\t2.解密\n";
		cout << "\t3.退出\n";
	}
private:
	std::string str;
	int model;
	int numB;
};

int main()
{
	Caesar s;
	s.caesar();
	return 0;
}
