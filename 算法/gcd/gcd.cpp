#include <iostream>
using namespace std;

template <class T>
T gcd(T a, T b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    else 
    {
        if ((a & 0x01) == 0)
        {
            if ((b & 0x01) == 0)
                return (gcd(a>>1, b>>1)<<1);
            else 
                return gcd(a>>1, b);
        }
        else 
        {
            if ((b & 0x01) == 0)
                return gcd(a, b>>1);
            else 
                return gcd(b, a-b);
        }
    }
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << gcd(a, b) << endl;
    }
    return 0;
}
