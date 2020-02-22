#include <iostream>
using namespace std;

template <class T>
class SmartPtr
{
    public:
        SmartPtr(T* ptr = nullptr)
            : m_ptr(ptr)
        {}

        ~SmartPtr()
        {
            if (m_ptr)
            {
                delete m_ptr;
                m_ptr = nullptr;
            }
        }

        T& operator*()
        {
            return *m_ptr;
        }

        T* operator->()
        {
            return m_ptr;
        }
    private:
        T* m_ptr;
};
template <class T>

class AutoPtr
{
    public:
        AutoPtr(T* ptr = nullptr)
            : m_ptr(ptr)
        {}

        ~AutoPtr()
        {
            if (m_ptr)
            {
            }
        }
    private:
        T* m_ptr;
};


void Test()
{
    int*p = new int;
    *p = 100;
    SmartPtr<int> sp1(p);
    *sp1 = 200;
}

int main()
{
    
    return 0;
}
