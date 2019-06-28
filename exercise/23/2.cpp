#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	Solution(std::string A, std::string B)
		: m_A(A)
		, m_B(B)
	{
		m_array.resize(m_B.size() + 1);
		for (auto& e : m_array)
			e.resize(m_A.size() + 1, 0);
	}

	int calStringDistance()
	{
		if (m_A.empty() || m_B.empty())
			return max(m_A.size(), m_B.size());
		
		for (auto i = 0; i <= m_A.size(); i++)
			m_array[0][i] = i;
		for (auto i = 1; i <= m_B.size(); i++)
			m_array[i][0] = i;
		for (auto i = 1; i <= m_B.size(); i++)
		{
			for (auto j = 1; j <= m_A.size(); j++)
			{
				m_array[i][j] = 1 + min(m_array[i - 1][j], m_array[i][j - 1]);
				if (m_B[i-1] == m_A[j-1])
					m_array[i][j] = min(m_array[i - 1][j - 1], m_array[i][j]);
				else
					m_array[i][j] = min(m_array[i - 1][j - 1] + 1, m_array[i][j]);
			}
		}
		return m_array[m_B.size()][m_A.size()];
	}
private:
	std::vector<std::vector<int> > m_array;
	std::string m_A;
	std::string m_B;
};

int main()
{
	std::string A, B;
	while (cin >> A >> B)
	{
		Solution s(A, B);
		cout << s.calStringDistance() << endl;
	}
	return 0;
}
