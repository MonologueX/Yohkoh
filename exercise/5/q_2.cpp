#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void PrintMaxNum(std::vector<int>& array, int num)
    {
        int sum = 0;
        int result = array[0];
        for (auto i = 0; i < num; i++)
        {
            sum += array[i];
            if (sum > result)
                result = sum;
            if (sum < 0)
                sum = 0;
        }
        cout << result << endl;
    }
};

int main()
{
    std::vector<int> array;
    int num = 0;
    cin >> num;
    array.resize(num);
    for (auto i = 0; i < num; i++)
    {
        cin >> array[i];
    }
    Solution s;
    s.PrintMaxNum(array, num);
    return 0;
}
