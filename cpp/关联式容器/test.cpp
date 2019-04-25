#include <iostream>
#include <map>
#include <string>
using namespace std;

void Test1()
{
    map<string, string> m;
    m.insert(pair<string, string>("舞娘", "蔡依林"));
    m.insert(make_pair("布达拉", "周杰伦"));

    cout << m["舞娘"] << endl;
    cout << m.size() << endl;

    cout << m["haha"] << endl;
    cout << m.size() << endl;

    m["假如爱有天意"] = "李健";
    cout << m.size() <<endl;
}

void Test2()
{
    int array[] = {2, 1, 5, 9, 0, 4, 7, 4, 8, 6};
    map<int, int> m;

    for (auto e : array)
    {
        m.insert(make_pair(e, e));
    }

    map<int, int>::iterator it = m.begin(); 
    while (it != m.end())
    {
        cout << it->first << "-->" << it->second << endl;
        it++;
    }

    cout << "================== auto ================" << endl;
    for (auto&e : m)
    {
        cout << e.first << "-->" << e.second << endl;
    }
}

int main()
{
    Test2();
    return 0;
}
