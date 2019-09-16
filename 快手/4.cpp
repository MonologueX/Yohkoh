#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<string> result;
std::array<string, 10> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrd", "tuv", "wxyz"};
std::string temp = "";
void PrintStr(std::string str, int num)
{
	if (num == str.size())
	{
		if (temp.size() == str.size())
			result.push_back(temp);
		return;
	}

	for (int i = num; i < str.size(); i++)
	{
		for (int j = 0; j < arr[str[i] - '0'].size(); j++)
		{
			temp += arr[str[i] - '0'][j];
			PrintStr(str, i+1);
			temp.erase(temp.size() - 1);
		}
	}
}

int main()
{
	std::string str;
	while (cin >> str)
	{
		PrintStr(str, 0);
		sort(result.begin(), result.end());
		cout << "[";
		for (int i = 0; i < result.size()-1; i++)
			cout << result[i] << ",";
		cout << result[result.size() - 1] << "]" << endl;
	}
	return 0;
}
