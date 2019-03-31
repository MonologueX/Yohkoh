#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void FunTest()
        {
            cout << "Base:FunTest()" << endl;
        }
    private:
};

class Derived : public Base
{
    public:
        virtual void FunTest()
        {
            cout << "Derived:FunTest()" << endl;
        }
    private:
};

void Test(Base &b)
{
    b.FunTest();
}

int main()
{
    Base b;
    Derived d;
    Test(b);
    Test(d);
    return 0;
}
