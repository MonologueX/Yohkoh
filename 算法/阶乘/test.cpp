#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    while (cin >> num)
    {
        if (!(num & (num-1)))
            cout << "True" << endl;
        else 
            cout << "False" << endl;
    }
    return 0;
}
