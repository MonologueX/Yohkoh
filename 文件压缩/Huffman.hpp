#define __HUFFMAN_H__ 
#ifdef __HUFFMAN_H__
#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

template<class W>
class HuffmanNode
{
public:
	HuffmanNode(W& weight)
	:m_left(nullptr)
	, m_right(nullptr)
	, m_parent(nullptr)
	, m_weight(weight)
	{}
	HuffmanNode *m_left;
	HuffmanNode *m_right;
	HuffmanNode *m_parent;
	W m_weight;
};

template<class W>
struct cmp
{
	typedef HuffmanNode<W> Node;
	typedef Node* PNode;
	bool operator()(PNode &left, PNode &right)
	{
		return (left->m_weight) > (right->m_weight);
	}
};
	
template<class W>
class HuffmanTree
{
	typedef HuffmanNode<W> Node;
	typedef Node* PNode;
	
public:
	HuffmanTree()
		:m_root(nullptr)
	{}

	HuffmanTree(std::vector<W> &array)
	{
		CreateHuffmanTree(array);
	}
	~HuffmanTree()
	{
		DestoryHuffmanTree(m_root);
		std::cout << "哈夫曼树销毁成功" << std::endl;
	}
	PNode GetRoot()
	{
		return m_root;
	}

private:
	int CreateHuffmanTree(std::vector<W> &array)
	{
		if (array.empty())
			return -1;
		std::priority_queue<PNode, std::vector<PNode>, cmp<W>> q;
		for (size_t i = 0; i < array.size(); ++i)
		{
			if (array[i].m_count != 0)
				q.push(new Node(array[i]));
		}
		if (q.size() == 0)
		{
			std::cout << "数组为空" << std::endl;
			m_root = nullptr;
			return -1;
		}
		while (q.size() > 1)
		{
			PNode pLeft = q.top();
			//std::cout << "Left:" << pLeft->m_weight.m_count << std::endl;
			q.pop();
			PNode pRight = q.top();
			//std::cout << "Right:" << pRight->m_weight.m_count << std::endl;
			q.pop();

			PNode pParent = new Node(pRight->m_weight + pLeft->m_weight);
			pParent->m_left = pLeft;
			pLeft->m_parent = pParent;
			pParent->m_right = pRight;
			pRight->m_parent = pParent;
			q.push(pParent);
		}
		m_root = q.top();
		std::cout << "哈夫曼树创建成功" << std::endl;
		return 1;
	}
	int DestoryHuffmanTree(PNode &pRoot)
	{
		if (pRoot)
		{
			DestoryHuffmanTree(pRoot->m_left);
			DestoryHuffmanTree(pRoot->m_right);
			delete pRoot;
			pRoot = nullptr;
		}
		return 1;
	}
private:
	PNode m_root;
};
#endif
