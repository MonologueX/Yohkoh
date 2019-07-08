/***********************************
* 文件名称: BTree.hpp
* 文件描述: B树
* 编译环境: Linux
* 作者相关: 心文花雨
***********************************/

#pragma once 
#include <iostream>
using namespace std;

template <class K, int M>
struct BTreeNode
{
	K m_keys[M];
	BTreeNode<K, M>* m_subs[M + 1];
	BTreeNode<K, M>* m_parent;
	int m_size;
	BTreeNode()
		: m_parent(nullptr)
		, m_size(0)
	{
		for (int i = 0; i < M + 1; ++i)
			m_subs[i] = nullptr;
		for (int i = 0; i < M; ++i)
			m_keys[i] = K();
	}
};

template <class K, int M>
class BTree
{
	typedef BTreeNode<K, M> Node;
	typedef Node* PNode;
public:
	BTree()
		: m_root(nullptr)
	{
	}

	bool Insert(const K& key)
	{
		if (nullptr == m_root)
		{
			m_root = new Node();
			m_root->m_keys[0] = key;
			m_root->m_size = 1;
			return true;
		}
		// 寻找是否存在，存在不插入
		std::pair<PNode, int> ret = Find(key);
		if (-1 != ret.second)
		{
			return false;
		}

		PNode node = ret.first;
		K k = key;
		// 孩子结点，重要
		PNode subNode = nullptr;
		while (true)
		{
			InsertKey(node, key, subNode);
			if (node->m_size < M)
			{
				return true;
			}
			// 结点满了，进行分裂
			PNode newNode = new Node;
			int mid = M / 2;
			int j = 0;
			int i = mid + 1;
			for (; i < node->m_size; ++i)
			{
				newNode->m_keys[j] = node->m_keys[i];
				node->m_keys[i] = K();
				node->m_size--;
				newNode->m_subs[j] = node->m_subs[i];
				if (node->m_subs[i])
				{
					node->m_subs[i]->m_parent = newNode;
				}

				newNode->m_size++;
				++j;
			}
			node->m_subs[j] = node->m_subs[i];
			if (node->m_subs[i])
			{
				node->m_subs[i]->m_parent = newNode;
			}

			PNode parent = node->m_parent;
			// 根节点
			if (nullptr == parent)
			{
				m_root = new Node;
				m_root->m_keys[0] = node->m_keys[mid];
				node->m_size--;
				node->m_keys[mid] = K();
				m_root->m_subs[0] = node;
				m_root->m_subs[1] = newNode;
				node->m_parent = m_root;
				newNode->m_parent = m_root;
				m_root->m_size = 1;
				return true;
			}
			else
			{
				// 非根节点
				k = node->m_keys[mid];
				subNode = newNode;
				node = parent;
			}
		}
		return false;
	}

	~BTree()
	{
	}
private:
	void InsertKey(PNode node, const K& key, PNode subNode)
	{
		// 插入排序
		int end = node->m_size - 1;
		while (end >= 0)
		{
			if (node->m_keys[end] > key)
			{
				node->m_keys[end + 1] = node->m_keys[end];
				node->m_subs[end + 2] = node->m_subs[end + 1];
				--end;
			}
			else
				break;
		}
		node->m_keys[end + 1] = key;
		node->m_subs[end + 2] = subNode;
		if (nullptr != subNode)
		{
			subNode->m_parent = node;
		}
		node->m_size++;
	}

	std::pair<PNode, int> Find(const K& key)
	{
		PNode cur = m_root;
		PNode parent = nullptr;
		while (cur)
		{
			int i = 0;
			for (; i < cur->m_size;)
			{
				if (cur->m_keys[i] == key)
				{
					return make_pair(cur, i);
				}
				else if (cur->m_keys[i] > key)
				{
					break;
				}
				else if (cur->m_keys[i] < key)
				{
					++i;
				}
			}
			parent = cur;
			cur = cur->m_subs[i];
		}
		return make_pair(parent, -1);
	}
private:
	PNode m_root;
};
