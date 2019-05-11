#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class  Solution
{
public:
    long long GetNum(std::vector<int> array, int num)
    {
        sort(array.begin(), array.end());
        long long result = 0;
        for (auto i = 0; i < num; i++)
        {
            result += array[array.size() - i*2 - 2];
        }
        return result;
    }
};


int main()
{
    std::vector<int> array;
    int num = 0;
    cin >> num;
    array.resize(3*num);
    int temp = 0;
    for (auto i = 0; i < 3*num; i++)
    {
        cin >> temp;
        array[i] = temp;
    }
    Solution s;
    cout << s.GetNum(array, num) << endl;
    return 0;
}
