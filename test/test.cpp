#include <iostream>
using namespace std;

int main()
{
    int && b = 10;
    cout << b << endl;
    b = 12;
    cout << b << endl;
    return 0;
}
