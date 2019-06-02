#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct GCD
{
	int x;
	int y;
	int d;
};

class Hill_Cipher
{
public:
	Hill_Cipher(int num)
	{
		K.resize(num);
		for (auto & e : K)
			e.resize(num, 0);
		D = K;
		P.resize(num);
		C = P;
		F = P;
		srand((unsigned)time(0));
		random_Matrix(num, num);
		while (Inverse(K, num))
		{
			random_Matrix(num, num);
		}
		cout << "随机产生矩阵:" << endl;
		for (auto i = 0; i < num; i++)
		{
			for (auto j = 0; j < num; j++)
			{
				printf("%2d  ", K[i][j]);
			}
			cout << endl;
		}
		cout << "该矩阵模26可逆,因此可以作为密钥!" << endl;
		cout << endl;
	}
	
	void random_Matrix(int row, int col);
	bool Inverse(std::vector<std::vector<int> >& matrix, int num);
	int Det(std::vector<std::vector<int> >& matrix, int row);
	int gcd(int a, int b);
	void multiphy(std::vector<std::vector<int> >& matrix, int num);
	void adjoint_matrix(int num);
	string encryption(string plaintext, int num);
	string deciphering(string ciphertext, int num);
	GCD extended_Euclid(int a, int b);
	int inverse(int a, int m);
	int Mod(int a);
private:
	std::vector<std::vector<int> > K;
	std::vector<std::vector<int> > D;
	std::vector<int> P;
	std::vector<int> C;
	std::vector<int> F;
};

void Hill_Cipher::random_Matrix(int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			K[i][j] = rand() % 26;  //产生一个5*5模26的矩阵
		}
	}

}

int Hill_Cipher::Det(std::vector<std::vector<int> >& matrix, int row)
{
	int i, j;
	std::vector<std::vector<int> >cofa = matrix;
	int l; 
	int p = 0, q = 0;
	int sum = 0;
	if (row == 1)
		return matrix[0][0];
	for (i = 0; i < row; i++)
	{
		for (l = 0; l < row - 1; l++)
		{
			if (l < i)
				p = 0;
			else
				p = 1;
			for (j = 0; j< row - 1; j++)
			{
				cofa[l][j] = matrix[l + p][j + 1];
			}
		}
		if (i % 2 == 0)
			q = 1;
		else
			q = (-1);
		sum = sum + matrix[i][0] * q * Det(cofa, row - 1);
	}
	return sum;
}

int Hill_Cipher::gcd(int a, int b)
{
	int temp;
	if (a < b)
		swap(a, b);
	while (a % b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return b;
}

bool Hill_Cipher::Inverse(std::vector<std::vector<int> >& matrix, int num)
{
	if (gcd(Det(matrix, num), 26) == 1)
		return true;
	else
		return false;
}

void Hill_Cipher::multiphy(std::vector<std::vector<int> >& matrix, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			C[i] += P[j] * K[j][i];
		}
	}
}

string Hill_Cipher::encryption(string plaintext, int num)
{
	int i;
	string ciphertext;
	for (i = 0; i < num; i++)
	{
		P[i] = plaintext[i] - 'a';
	}
	multiphy(K, num);
	for (i = 0; i < num; i++)
	{
		C[i] = Mod(C[i]);
		ciphertext += C[i] + 'A';
	}
	return ciphertext;
}

void Hill_Cipher::adjoint_matrix(int num)
{
	int i, j, k, l;
	int p, q;
	p = q = 0;
	std::vector<std::vector<int> > temp;
	temp.resize(num);
	for (auto & e : temp)
		e.resize(num, 0);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			for (k = 0; k < num - 1; k++)
			{
				if (k < i)
					p = 0;
				else
					p = 1;
				for (l = 0; l < num - 1; l++)
				{
					if (l < j)
						q = 0;
					else
						q = 1;
					temp[k][l] = K[k + p][l + q];
				}
			}
			D[j][i] = (int)pow(-1, (double)i + j)*Det(temp, num - 1);
			D[j][i] = Mod(D[j][i]);
		}
	}
}

string Hill_Cipher::deciphering(string ciphertext, int num)
{
	string text;
	int determinant = Det(K, num);
	int inver = inverse(determinant, 26);
	adjoint_matrix(num);
	//cout << "行列式的值: " << determinant << endl;
	int i, j;
	F.resize(num, 0);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			F[i] += C[j] * D[j][i];
		}
		F[i] *= inver;
		F[i] = Mod(F[i]);
	}
	for (i = 0; i < num; i++)
		text += F[i] + 'a';
	return text;
}

GCD Hill_Cipher::extended_Euclid(int a, int b)
{
	GCD aa, bb;
	if (b == 0)
	{
		aa.x = 1;
		aa.y = 0;
		aa.d = a;
		return aa;
	}
	else
	{
		bb = extended_Euclid(b, a%b);
		aa.x = bb.y;
		aa.y = bb.x - (a / b) * bb.y;
		aa.d = bb.d;
	}
	return aa;
}

int Hill_Cipher::inverse(int a, int m)
{
	GCD aa;
	aa = extended_Euclid(a, m);
	return aa.x;
}

int Hill_Cipher::Mod(int a)
{
	return a >= 0 ? a % 26 : (26 + a % 26);
}

void Menu()
{
	cout << "\t\tHill密码" << endl;
	cout << "\t0.退出" << endl;
	cout << "\t1.加密" << endl;
	cout << "\t2.解密" << endl;
	cout << "请选择：";
}

int main()
{
	int num;
	string plaintext, ciphertext;
	char c;
	while (1)
	{
		Menu();
		cin >> c;
		if (c == '0')
		{
			cout << endl;
			cout << "退出" << endl;
			return 0;
		}
		cout << "使用希尔密码进行消息的加解密" << endl;
		cout << "请输入矩阵维数:";
		cin >> num;
		Hill_Cipher hh(num);
		if (c == '1')
		{
			cout << "请输入明文信息:";
			cin >> plaintext;
			ciphertext = hh.encryption(plaintext, num);
			cout << endl;
			cout << "输出的密文消息为:" << endl;
			cout << ciphertext << endl;
		}
		else if (c == '2')
		{
			cout << "请输入密文信息:";
			cin >> ciphertext;
			hh.encryption(ciphertext, num);
			plaintext = hh.deciphering(ciphertext, num);
			cout << "该密文解密过后,明文消息:";
			cout << plaintext << endl;
		}
	}
	return 0;
}
