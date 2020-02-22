#include <iostream>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        factor = 1;
        count = 0;
        while (n / factor)
        {
            hei = n / (factor * 10);
            low = n % factor;
            cur = (n / factor) % 10;
            switch (cur)
            {
                case 0:
                    break;
                    count += factor*hei;
                case 1:
                    count += factor*hei + 1 + low;
                    break;
                default:
                    count += factor*(hei+1);
                    break;
            }
            factor *= 10;
        }
        return count;
    }
private:
    int low;
    int hei;
    int cur;
    int factor;
    int count;
};

class Solution
{
public:
	int Sumls(int num)
	{
		m_factor = 1;
		m_count = 0;
		while (num / m_factor)
		{
			m_higher = num / (m_factor * 10);
			m_lower = num % m_factor;
			m_cur = (num / m_factor) % 10;
			switch (m_cur)
			{
			case 0:
				m_count += m_higher*m_factor;
				break;
			case 1:
				m_count += m_higher*m_factor + m_lower + 1;
				break;
			default:
				m_count += m_higher*m_factor + m_factor;
				break;
			}
			m_factor *= 10;
		}
		return m_count;
	}
private:
	int m_cur;
	int m_lower;
	int m_higher;
	int m_count;
	int m_factor;
};

int main()
{
	int num = 0;
	while (cin >> num)
	{
		Solution s;
		cout << s.Sumls(num) << endl;
	}
	return 0;
}
