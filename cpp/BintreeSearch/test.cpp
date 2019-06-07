#include "BintreeSearch.hpp"

void Test()
{
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    BSTree<int> t;
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.Inorder();
    BSTNode<int>* pNode = t.Find(9);
    if (pNode)
    {
        cout << "find success!" << endl;
    }
    else 
    {
        cout << "find fail!" << endl;
    }
}
