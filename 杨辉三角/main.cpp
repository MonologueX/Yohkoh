#include <iostream>
#include <vector>

using namespace std;

class YangHui
{
public:
	YangHui(int _n = 0, int _m = 0)
	{
		vector<int> n;
		n.resize(_n);
		for (size_t i = 0; i < n.size(); i++)
		{
			n[i] = _n - i;
		}
		vector<int> m;
		m.resize(_m);
		for (size_t i = 0; i < m.size(); i++)
		{
			m[i] = _m - i;
		}
	}

private:
	void Adjust()
	{
		while (1)
		{
			for (size_t i = 0; i < n.size(); i++)
			{
				for (size_t j = 0; j < m.size(); j++)
				{
					if (0 == m.size() || 0 == n.size())
						return;
					if (0 == n[i] % m[j])
					{
						n[i] = n[i] / m[j];
						m.erase(m.begin() + j);
						j--;
					}
				}
			}

			for (size_t i = 0; i < n.size(); i++)
			{
				for (size_t j = 0; j < n.size(); j++)
				{
					if (0 == m.size() || 0 == n.size())
						return;
					if (0 == m[i] % n[j])
					{
						m[i] = m[i] / n[j];
						n.erase(n.begin() + j);
						j--;
					}
				}
			}

		}
	}
private:
	vector<int> n;
	vector<int> m;
};

int main()
{
	YangHui h(3, 2);
	return 0;
}
