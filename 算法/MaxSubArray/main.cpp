/***********************************
 * 文件名称: main.cpp
 * 文件描述: 最大连续子数组
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
#include <vector>
using namespace std;

template <class T> 
class Solution
{
public:
    T MaxSubArray(std::vector<T> array, int from, int to)
    {
        if (from == to)
        {
            return array[from];
        }
        int mid = (from+to) >> 1;
        T m1 = MaxSubArray(array, from, mid);
        T m2 = MaxSubArray(array, mid+1, to);
        int left = array[mid];
        int now = array[mid];
        for (auto i = mid-1; i >= from; --i)
        {
            now += array[i];
            left = max(now, left);
        }
        int right = array[mid+1];
        for (auto i = mid+2; i <= to; ++i)
        {
            now += array[i];
            right = max(now, right);
        }
        T m3 = left+right;
        return max(m1, m2, m3);
    }
private:
};

int main()
{
    std::vector<int> array;
    int num = 0;
    while (cin >> num)
    {
        array.resize(num);
        for (auto i = 0; i < num; i++)
        {
            cin >> array[i];
        }
        Solution<int> s;
        s.MaxSubArray(array, 0, num);
    }
    return 0;
}
