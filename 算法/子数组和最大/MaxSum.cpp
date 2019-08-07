#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int MaxSum(std::vector<int> array, int n)
    {
        nStart = array[n - 1];
        nAll = array[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            nStart = max(array[i], nStart + array[i]);
            nAll = max(nStart, nAll);
        }
        return nAll;
    }
private:
    int nStart;
    int nAll;
};


int main()
{
    std::vector<int> array{-2, 5, 3, -6, 4, -8, 6};
    Solution s;
    cout << s.MaxSum(array, array.size()) << endl;
    return 0;
}
