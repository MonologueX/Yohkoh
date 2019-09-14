#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    Solution s;
    while (cin >> num)
    {
        cout << s.totalNQueens(num) << endl;
    }
    return 0;
}
