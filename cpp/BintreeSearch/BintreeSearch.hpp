/***********************************
 * 文件名称: BintreeSarch.hpp
 * 文件描述: 二叉搜索树模拟 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#pragma once 
#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
    BSTNode(const T& data)
        : m_left(nullptr)
        , m_right(nullptr)
        , m_data(data)
    {}

    BSTNode<T>* m_left; 
    BSTNode<T>* m_right; 
    T m_data; 
};

template <class T>
class BSTree
{
    typedef BSTNode<T> Node;
    typedef Node* PNode;
public:
    BSTree()
        : m_root(nullptr) 
    {}

    // 中序
    void Inorder()
    {
        _Inorder(m_root);
    }

    // 查找
    PNode Find(const T& data)
    {
        return _Find(data);
    }

    // 插入
    bool Insert(const T& data)
    {
        return _Insert(data);
    }

    // 删除
    bool Erase(const T& data)
    {
        _Erase(data);
    }

    ~BSTree()
    {
        Destory(m_root);
    }

private:
    bool _Erase(const T& data)
    {
        PNode cur = m_root;
        PNode parent = nullptr;
        while (cur)
        {
            if (data == cur->m_data)
            {
                break;
            }
            else if (data < cur->m_data)
            {
                parent = cur;
                cur = cur->m_left;
            }
            else 
            {
                parent = cur;
                cur = cur->m_right;
            }
        }
        if (nullptr == cur)
        {
            return false;
        }

        // 叶子结点和只有右孩子
        if (nullptr == cur->m_left)
        {
            if (m_root == cur)
            {
                m_root = cur->m_right;
            }
            else 
            {
                if (cur == parent->m_left)
                {
                    parent->m_left = cur->m_right;
                }
                else 
                {
                    parent->m_right = cur ->m_right;
                }
            }
        }
        // 只有左孩子
        else if (nullptr == cur->m_right)
        {
            if (cur == m_root)
            {
                m_root = cur->m_left;
            }
            else 
            {
                if (cur == parent->m_left)
                {
                    parent->m_left = cur->m_right;
                }
                else 
                {
                    parent->m_right = cur ->m_right;
                }
            }
        }
        // 左右孩子都存在
        else 
        {
            PNode FirstOfIn = cur->m_right;
            parent = cur;
            while (FirstOfIn->m_left)
            {
                parent = FirstOfIn;
                FirstOfIn = FirstOfIn->m_left;
            }
            cur->m_data = FirstOfIn->m_data;
            if (FirstOfIn == parent->m_left)
            {
                parent->m_left = FirstOfIn->m_right;
            }
            else 
            {
                parent->m_right = FirstOfIn->m_right;
            }
            cur = FirstOfIn;
        }
        delete cur;
        return true;
    }

    bool _Insert(const T& data)
    {
        // 树为空
        if (nullptr == m_root)
        {
            m_root = new Node(data);
            return true;
        }

        // 树不为空
        PNode cur = m_root;
        PNode parent = nullptr;
        while (cur)
        {
            parent = cur;
            if (data < cur->m_data)
            {
                cur = cur->m_left;
            }
            else if (data > cur->m_data)
            {
                cur = cur->m_right;
            }
            else 
                return true;
        }
        cur = new Node(data);
        if (data < parent->m_data)
        {
            parent->m_left = cur;
        }
        else 
        {
            parent->m_right = cur;
        }
        return true;
    }

    PNode _Find(const T& data)
    {
        PNode cur = m_root;
        while (cur)
        {
            if (data == cur->m_data)
            {
                return cur;
            }
            else if (data < cur->m_data)
            {
                cur = cur->m_left;
            }
            else 
            {
                cur = cur->m_right;
            }
        }
        return nullptr;
    }

    void _Inorder(PNode root)
    {
        if (root)
        {
            _Inorder(root->m_left);
            cout << root->m_data << " ";
            _Inorder(root->m_right);
        }
        cout << endl;
    }
    void Destory(PNode& root)
    {
        if (root)
        {
            Destory(root->m_left);
            Destory(root->m_right);
            delete root;
            root = nullptr;
        }
    }
private:
    PNode m_root;
};
