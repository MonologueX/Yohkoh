#include <iostream>
#include <setjmp.h>
#include <malloc.h>
using namespace std;

///////////////////////////////////////////////
//  C语言异常处理
///////////////////////////////////////////////
#if 0
int Div(int left, int right)
{
    if (0 == right)
    {
        exit(0);
    }
    return left / right;
}

jmp_buf buff;
void TestFunc1()
{
    FILE* pf = fopen("test.txt", "r");
    if (nullptr == pf)
    {
        longjmp(buff, 1);
    }
    fclose(pf);
}

void TestFunc2()
{
    // int* p = (int*)malloc(sizeof(int)*0xfffffff);
    int* p = nullptr; 
    if (nullptr == p)
    {
        longjmp(buff, 2);
    }
    free(p);
}

int main()
{
    int state = setjmp(buff);
    if (state == 0)
    {
        TestFunc1();
        TestFunc2();
    }
    else 
    {
        switch (state)
        {
            case 1:
                cout << "打开文件失败" << endl;
                break;
            case 2:
                cout << "malloc申请失败" << endl;
                break;
            default:
                cout << "未知错误" << endl;
        }
    }
    return 0;
}

#endif

///////////////////////////////////////////////
//  C++异常处理
/////////////////////////////////////////////// 
#if 0
void TestFunc1()
{
    FILE* pf = fopen("test.txt", "r");
    if (nullptr == pf)
    {
        throw 1;
    }
    fclose(pf);
}
void TestFunc2()
{
    // int* p = (int*)malloc(sizeof(int)*0xfffffff);
    int* p = nullptr; 
    if (nullptr == p)
    {
        throw 'a';
    }
    free(p);
}

int main()
{
    try 
    {
        TestFunc2();
        TestFunc1();
    }
    catch (int err)
    {
        cout << err << endl;
    }
    catch (char err)
    {
        cout << err << endl;
    }
    return 0;
}
#endif

#if 0
void TestFunc1()
{
    FILE* pf = fopen("test.txt", "r");
    if (nullptr == pf)
    {
        throw 1;
    }
    fclose(pf);
}
void TestFunc2()
{
    // int* p = (int*)malloc(sizeof(int)*0xfffffff);
    int* p = nullptr; 

    TestFunc1();

    try 
    {
        TestFunc1();
    }
    catch (int err)
    {
        cout << err << endl;
    }

    free(p);
}

int main()
{
    try 
    {
        TestFunc2();
    }
    catch (int err)
    {
        cout << err << endl;
    }
    return 0;
}
#endif 

#if 0
class Exception
{
    public:
        Exception()
        {
            cout << "Exception" << this << endl;
        }

        Exception(const Exception& e)
        {
            (void)e;
            cout << "Exception(const Exception& e)" << this << endl;
        }

        ~Exception() 
        {
            cout << "~Exception()" << this << endl;
        }
};

void TestFunc()
{
    Exception e;
    throw e;
}

int main()
{
    try 
    {
        TestFunc();
    }
    catch (const Exception & e)
    {
        cout << &e << endl;
    }
    return 0;
}
#endif 

#if 0
void TestFunc1()
{
    FILE* pf = fopen("test.txt", "r");
    if (nullptr == pf)
    {
        throw 1;
    }
    fclose(pf);
}

int main()
{
    try 
    {
        TestFunc1();
    }
    // ... 
    catch (...)
    {
        // 异常的重新抛出
        throw;
    }
    return 0;
}
#endif

#if 0
class Exception
{};

class DBException : public Exception 
{};

void TestFunc()
{
    DBException db;
    throw db;
}

int main()
{
    try 
    {
        TestFunc();
    }
    catch (const Exception & e)
    {
        cout << &e << endl;
    }
    return 0;
}
#endif 

void TestFunc1()
{
    throw 1;
}

void TestFunc2()
{
    try 
    {
        TestFunc1();
    }
    catch (int err) 
    {
        cout << err << endl;
    }
    TestFunc1();
}

void TestFunc3()
{
    TestFunc2();
}

void TestFunc4()
{
    TestFunc3();
}

int main()
{
    try 
    {
        TestFunc4();
    }
    catch (int err)
    {
        cout << err << endl;
    }
    return 0;
}
