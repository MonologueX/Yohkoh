#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> array;
    int num = 0;
    while (cin >> num)
        array.push_back(num);
    sort(array.begin(), array.end());
    num = array.size() / 2;
    for (auto i = 0; i < num; i++)
    {
        if (array[i] == array[i+num-1])
        {
            cout << array[i] << endl;
            break;
        }
    }
    return 0;
}
