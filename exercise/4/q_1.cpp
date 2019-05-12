#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void PrintABC(std::vector<int> array)
    {
        if ((array[2] - array[0]) == (array[1]) + array[3])
        {
            int B = (array[1] + array[3])/2;
            int A = array[0] + B;
            int C = array[3] - B;
            cout << A << ' ' << B << ' ' << C << endl;
        }
        else 
            cout << "No" << endl;
    }
};

int main ()
{
    std::vector<int> array;
    array.resize(4);
    for (auto i = 0; i < 4; i++)
    {
        cin >> array[i];
    }
    Solution s;
    s.PrintABC(array);
    return 0;
}
