#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void Encry(std::string strI, int numB, int model)
{
	if (model == 1)
	{
		for (size_t i = 0; i<strI.size(); i++)
		{
			if (strI[i] >= 'A' && strI[i] <= 'Z')
			{
				strI[i] = ((strI[i] - 'A') + numB) % 26 + 'A';
			}
			else if (strI[i] >= 'a' && strI[i] <= 'z')
			{
				strI[i] = ((strI[i] - 'a') + numB) % 26 + 'a';
			}
		}
		cout << "加密完成：" << strI << endl;
	}
	else
	{
		cout << "该模式不支持此项功能！" << endl;
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
			{
				strI[i] = ((strI[i] - 'A') + num) % 26 + 'A';
			}
			else if (strI[i] >= 'a' && strI[i] <= 'z')
			{
				strI[i] = ((strI[i] - 'a') + num) % 26 + 'a';
			}
		}
		cout << "解密完成：" << strI << endl;
	}
	else
	{
		cout << "该模式不支持此项功能！" << endl;
	}
}

void Menu()
{
	cout << "\t\t凯撒密码：请选择模式:\n";
	cout << "\t1.加密\n";
	cout << "\t2.解密\n";
	cout << "\t3.退出\n";
}

int main()
{
	int model;
	int numB;
	while (1)
	{
		Menu();
		cin >> model;
		switch (model)
		{
		case 1:
			{
				  cout << "请输入要加密的字符串:" << endl;
				  std::string str;
				  fflush(stdin);
				  getline(cin, str);
				  cout << "请输入该密码算法的偏移数量：";
				  cin >> numB;
				  Encry(str, numB, model);
				  cout << endl;
			}
			break;
		case 2:
			{
				  cout << "请输入要解密的字符串:";
				  std::string str2;
				  fflush(stdin);
				  getline(cin, str2);
				  cout << "请输入原密码算法的偏移数量：";
				  cin >> numB;
				  Decry(str2, numB, model);
				  cout << endl;
				  break;
			}
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}


