#include "Hash.hpp"

template <class HB, class K>
void TestFind(HB ht, K key)
{
    if (ht.Find(key))
        cout << "找到了!!!" << endl;
    else
        cout << "没有找到!!!" << endl;
}

template <class HB, class K>
void TestErase(HB ht, K key)
{
    TestFind(ht, key);
    ht.Erase(key);
    TestFind(ht, key);
}

int main()
{
    HashTable<int, int> ht(10);
    for (int i = 0; i < 10; i++)
    {
        ht.Insert(make_pair(i, i));
    }

    TestFind(ht, 5);
    TestFind(ht, 11);

    TestErase(ht, 6);
    return 0;
}
