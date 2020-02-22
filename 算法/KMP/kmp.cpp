#include <iostream>
#include <vector>
#include <string>
using namespace std;

///////////////////////////////////////////////
//  PrefixTable
///////////////////////////////////////////////
void PrefixTable(std::string parttern, std::vector<int>& prefix, int n)
{
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while (i < n)
	{
		if (parttern[i] == parttern[len])
		{
			len++;
			prefix[i++] = len;
		}
		else
		{
			if ((len > 0))
				len = prefix[len - 1];
			else
				prefix[i++] = len;
		}
	}
}

void MovePrefix(std::vector<int>& prefix, int n)
{
	for (auto i = n - 1; i > 0; i--)
		prefix[i] = prefix[i - 1];
	prefix[0] = -1;
}

///////////////////////////////////////////////
//  KMP
///////////////////////////////////////////////
void KmpSearch(std::string text, std::string parttern)
{
	int n = parttern.size();
	int m = text.size();
	std::vector<int> prefix;
	prefix.resize(n);
	PrefixTable(parttern, prefix, n);
	MovePrefix(prefix, n);
	int i = 0, j = 0;
	while (i < m)
	{
		if (j == n - 1 && text[i] == parttern[j])
		{
			cout << "Found parttern at:" << i - j << endl;
			j = prefix[j];
		}
		if (text[i] == parttern[j])
		{
			i++, j++;
		}
		else
		{
			j = prefix[j];
			if (j == -1)
				i++, j++;
		}
	}
}

int main()
{
	string m_text; string m_parttern;
	m_text += "ABABCABAA";
	m_parttern += "ABABABCABAAGJHFR";
	KmpSearch(m_text, m_parttern);
	return 0;
}
