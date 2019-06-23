/***********************************
 * 文件名称: Hash.hpp
 * 文件描述: 模拟实现Hash
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#pragma once 
#include <iostream>
#include <vector>
using namespace std;

#include "common.hpp"

#if 0
enum STATE 
{
    EMPTY,
    EXISTS,
    DELETE,
};

template <class K, class V>
struct HashNode
{
    pair<K, V> m_kv;
    STATE m_state = EMPTY;
};

template <class K, class V>
class HashTable
{
public:
    typedef HashNode<K, V> Node;
    typedef Node* PNode;
public:
    HashTable(size_t N)
    {
        m_table.resize(N);
        m_size = 0;
    }
    HashTable()
    {
        m_table.resize(10);
        m_size = 0;
    }

    ///////////////////////////////////////////////
    //  插入
    ///////////////////////////////////////////////
    bool Insert(const pair<K, V>& kv)
    {
        CheckCapacity();
        size_t index = kv.first % m_table.size();
        while (m_table[index].m_state == EXISTS)
        {
            if (m_table[index].m_kv.first == kv.first)
            {
                return false;
            }

            ++index;
            if (index == m_table.size())
            {
                index = 0;
            }
        }
        m_table[index].m_kv = kv;
        m_table[index].m_state = EXISTS;
        ++m_size;
        return true;
    }
    // 检查容量
    void CheckCapacity()
    {
        if (m_size*10 / m_table.size() >= 7)
        {
            size_t newCapacity = m_table.size() == 0 ? 1 : 2*m_table.size();
            std::vector<Node> newT;
            HashTable<K, V> newHt(newCapacity);
            for (size_t i = 0; i < m_table.size(); i++)
            {
                if (m_table[i].m_state == EXISTS)
                {
                    newHt.Insert(m_table[i].m_kv);
                    //size_t index = m_table[i].m_kv.first % newT.size();
                    //newT[index] = m_table[i];
                }
            }
            m_table.swap(newHt.m_table);
        }
    }

    ///////////////////////////////////////////////
    //  查找
    ///////////////////////////////////////////////
    bool Find(const K& key)
    {
        size_t index = key % m_table.size();
        if (m_table[index].m_state == EXISTS)
        {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////
    //  删除
    ///////////////////////////////////////////////
    bool Erase(const K& key)
    {
        size_t index = key % m_table.size();
        if (index > m_size)
        {
            return false;
        }
        m_table[index].m_state = DELETE;
        m_size--;
        return true;
    }
private:
    std::vector<Node> m_table;
    size_t m_size;
};
#endif

template <class V>
struct HashNode
{
    HashNode(const V& data)
        : m_data(data)
        , m_next(nullptr)
    {
    }
    V m_data;
    HashNode<V>* m_next;
};

template <class K, class V, class KeyOfValue>
class HashTable
{
public:
    typedef HashNode<V> Node;
    typedef Node* PNode;
public:
    HashTable(size_t capacity = 10)
    {
        m_table.resize(GetNextPrime(capacity));
        m_size = 0;
    }
    HashTable()
    {
        m_table.resize(10);
        m_size = 0;
    }

    ///////////////////////////////////////////////
    //  插入
    ///////////////////////////////////////////////
    bool Insert(const V& data)
    {
        CheckCapacity();
        KeyOfValue kov;
        size_t index = kov(data) % m_table.size();
        PNode cur = m_table[index];
        while (cur)
        {
            if (kov(cur->data) == kov(data))
            {
                return false;
            }

            ++index;
            if (index == m_table.size())
            {
                index = 0;
            }
        }
        m_table[index].m_kv = kv;
        m_table[index].m_state = EXISTS;
        ++m_size;
        return true;
    }
    // 检查容量
    void CheckCapacity()
    {
        if (m_size*10 / m_table.size() >= 7)
        {
            size_t newCapacity = m_table.size() == 0 ? 1 : 2*m_table.size();
            std::vector<Node> newT;
            HashTable<K, V> newHt(newCapacity);
            for (size_t i = 0; i < m_table.size(); i++)
            {
                if (m_table[i].m_state == EXISTS)
                {
                    newHt.Insert(m_table[i].m_kv);
                    //size_t index = m_table[i].m_kv.first % newT.size();
                    //newT[index] = m_table[i];
                }
            }
            m_table.swap(newHt.m_table);
        }
    }

    ///////////////////////////////////////////////
    //  查找
    ///////////////////////////////////////////////
    bool Find(const K& key)
    {
        size_t index = key % m_table.size();
        if (m_table[index].m_state == EXISTS)
        {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////
    //  删除
    ///////////////////////////////////////////////
    bool Erase(const K& key)
    {
        size_t index = key % m_table.size();
        if (index > m_size)
        {
            return false;
        }
        m_table[index].m_state = DELETE;
        m_size--;
        return true;
    }
private:
    std::vector<Node> m_table;
    size_t m_size;
};
