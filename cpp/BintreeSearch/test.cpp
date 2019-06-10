#include "BintreeSearch.hpp"

void Test()
{
    ///////////////////////////////////////////////
    //  插入测试
    ///////////////////////////////////////////////
    
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    BSTree<int> t;
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.Inorder();

    ///////////////////////////////////////////////
    // 查找测试
    ///////////////////////////////////////////////
    
    BSTNode<int>* pNode = t.Find(9);
    if (pNode)
    {
        cout << "find success!" << endl;
    }
    else 
    {
        cout << "find fail!" << endl;
    }

    ///////////////////////////////////////////////
    //  删除测试
    ///////////////////////////////////////////////

	t.Erase(6);
	t.Inorder();
	cout << endl;

	t.Erase(8);
	t.Inorder();
	cout << endl;

	t.Erase(5);
	t.Inorder();
	cout << endl;
}
