// write your code here cpp
#include<iostream>
#include<string>

int main() 
{
	std::string s, t;
	while (std::cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != std::string::npos)
		{
			pos += t.size();
			++res;
		}
		std::cout << res << std::endl;
	}
}
