#include "BTree.hpp"
#include <iostream>
using namespace std;

int main()
{
    BTree<int, 3> tree;
    int a[] = {53, 139, 75, 49, 145, 36, 101};
    for (auto e : a)
    {
        tree.Insert(e);
    }
    return 0;
}
