#include <iostream>
#include <vector>

class YangHui
{
public:
	YangHui(int _n = 0, int _m = 0);
	void Adjust();
	void GetResult();

private:
	void Adjust1(std::vector<int>& n, std::vector<int>& m);
	void Adjust2(std::vector<int>& m);
	void Cal(std::vector<int>& n);

private:
	std::vector<int> m_n;
	std::vector<int> m_m;
};
