 #include <iostream>
using namespace std;

int main()
{
    int num = 0;
    while (cin >> num)
    {
        int one = 1;
        int two = 0;
        int temp = 0;
        for (int i = 0; i < num; i++)
        {
            temp = two;
            two = one + two;
            one = temp;
        }
        cout << two << endl;
    }
    return 0;
}
