/***********************************
 * 文件名称: AVLTree.cpp
 * 文件描述: AVL 树模拟实现
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#pragma once 

template <class T>
struct AVLTreeNode
{
    AVLTreeNode(const T& data)
        : m_left(nullptr) 
        , m_right(nullptr)
        , m_parent(nullptr)
        , m_data(data)
        , m_bf(0)
    {}

    AVLTreeNode<T>* m_left;
    AVLTreeNode<T>* m_right;
    AVLTreeNode<T>* m_parent;
    T m_data;
    int m_bf;
};

template <class T>
class AVLTree
{
    typedef AVLTreeNode<T> Node;        
    typedef Node* PNode;        
public:                                 
    AVLTree()
        : m_root(nullptr)
    {}
    bool Insert(const T& data)
    {
        if (nullptr == m_root)
        {
            m_root = new Node(data);
            return true;
        }
        PNode cur = m_root;
        PNode parent = nullptr;
        while (cur)
        {
            if (data < cur->m_data)
            {
                cur = cur->m_left;
                parent = cur;
            }
            else if (data > cur->m_data)
            {
                cur = cur->m_right;
                parent = cur;
            }
            else 
            {
                return false;
            }
            cur = new Node(data);
            if (data <parent->m_data)
            {
                parent->m_left = cur;
                cur->m_parent = parent;
            }
            else 
            {
                parent->m_right = cur;
                cur->m_parent = cur;
            }

            // 更新平衡因子
            if (cur == parent->m_left)
            {
                parent->m_bf--;
            }
            else 
            {
                parent->m_bf++;
            }
        }
    }
private:
    PNode m_root;
};

