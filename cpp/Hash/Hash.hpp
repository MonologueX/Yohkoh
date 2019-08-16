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
    HashNode(const V& data = V())
        : m_data(data)
        , m_next(nullptr)
    {
    }
    V m_data;
    HashNode<V>* m_next;
};
template <class V, class K, class KOV, class KTOINT>
class HashTable;

template <class V, class K, class KOV, class KTOINT>
struct HashTableIterator 
{
    typedef HashNode<V> Node;
    typedef Node* PNode;
    typedef HashTableIterator<V, K, KOV, KTOINT> Self;
public:
    HashTableIterator(HashTable<V, K, KOV, KTOINT>* ht = nullptr, PNode node = nullptr)
        : m_ht(ht)
        , m_node(node)
    {}

    HashTableIterator(const Self& s)
        : m_ht(s.m_ht)
        , m_node(s.m_node)
    {}

    V& operator*()
    {
        return m_node->m_data;
    }

    V* operator->()
    {
        return &(operator*());
    }

    bool operator!=(const Self& s)const 
    {
        return m_node != s.m_node;
    }

    bool operator==(const Self& s)const 
    {
        return m_node == s.m_node;
    }

    Self operator++()
    {
        Next();
        return *this;
    }

    Self operator++(int)
    {
        Self temp(*this);
        Next();
        return temp;
    }
private:
    void Next()
    {
        if (m_node->m_next)
        {
            m_node = m_node->m_next;
        }
        else 
        {
            size_t bucketNo = m_ht->HashFunc(KOV()(m_node->m_data))+1;
            for (; bucketNo < m_ht->m_table.size(); ++bucketNo)
            {
                m_node = m_ht->m_table[bucketNo];
                if (m_node)
                {
                    return;
                }
            }
        }
    }
private:
    PNode m_node;
    HashTable<V, K, KOV, KTOINT>* m_ht;
};

template <class V, class K, class KOV, class KTOINT>
class HashTable
{
public:
    friend HashTableIterator<V, K, KOV, KTOINT>;
    typedef HashNode<V> Node;
    typedef Node* PNode;
    typedef HashTable<V, K, KOV, KTOINT> Self;
public:
    typedef HashTableIterator<V, K, KOV, KTOINT> Iterator;
public:
    HashTable(size_t capacity = 10)
        : m_size(0)
    {
        m_table.resize(GetNextPrime(capacity));
    }

    ~HashTable()
    {
        //Clear();
    }

    ///////////////////////////////////////////////
    //  插入
    ///////////////////////////////////////////////
    bool InsertEqual(const V& data)
    {
        CheckCapacity();
        size_t index = HashFunc(KOV()(data));
        PNode cur = m_table[index];
        PNode newNode = new Node(data);
        while (cur)
        {
            if (KOV()(data) == KOV()(cur->m_data))
            {
                break;
            }
            cur = cur->m_next;
        }
        if (cur == nullptr)
        {
            newNode->m_next = m_table[index];
            m_table[index] = newNode;
        }
        else 
        {
            newNode->m_next = cur->next;
            cur->m_next = newNode;
        }
        ++m_size;
        return true;
    }
    bool InsertUnique(const V& data)
    {
        CheckCapacity();
        // 计算哈希桶号
        size_t index = HashFunc(KOV()(data));
        // 检测 key 是否存在
        PNode cur = m_table[index];
        while (cur)
        {
            if (KOV()(data) == KOV()(cur->m_data))
                return false;
            cur = cur->m_next;
        }
        // 插入节点
        cur = new Node(data);
        cur->m_next = m_table[index];
        ++m_size;
        return true;
    }
    ///////////////////////////////////////////////
    //  删除
    ///////////////////////////////////////////////
    bool EraseEqual(const K& key)
    {
        size_t index = HashFunc(key);
        PNode cur = m_table[index];
        PNode pre = nullptr;
        bool flag = false;
        while (cur)
        {
            if (key == KOV()(cur->m_data))
            {
                if (nullptr == pre)
                {
                    m_table[index] = cur->m_next;
                    delete cur;
                    cur = m_table[index];
                }
                else 
                {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->m_next;
                }
                flag = true;
                --m_size;
            }
            else 
            {
                pre = cur;
                cur = cur->m_next;
            }
        }
        return flag;;
    }
    bool EraseUnique(const K& key)
    {
        size_t index = HashFunc(key);
        PNode cur = m_table[index];
        PNode pre = nullptr;
        while (cur)
        {
            if (key == KOV()(cur->m_data))
            {
                if (nullptr == pre)
                    m_table = cur->m_next;
                else 
                    pre->m_next = cur->m_next;
                delete cur;
                --m_size;
                return true;
            }
            else 
            {
                pre = cur;
                cur = cur->m_next;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////
    //  查找
    ///////////////////////////////////////////////
    PNode Find(const K& key)
    {
        size_t index = key % m_table.size();
        PNode cur = m_table[index];
        while (cur)
        {
            if (key == KOV()(key))
            {
                return true;
            }
            cur = cur->m_next;
        }
        return nullptr;
    }

    ///////////////////////////////////////////////
    //  增容
    ///////////////////////////////////////////////
    void CheckCapacity()
    {
        if (m_size == m_table.capacity())
        {
            Self newHt(GetNextPrime(m_size));
            for (size_t i = 0; i < m_table.size(); i++)
            {
                PNode cur = m_table[i];
                while (cur)
                {
                    // 节点重复创建
                    // newHt.InsertEqual(cur->m_data);
                    size_t bucketNo = newHt.HashFunc(KOV()(cur->m_data));
                    PNode pos = newHt.m_table[bucketNo];
                    while (pos)
                    {
                        if (KOV(pos->m_data == KOV(cur->m_data)))
                        {
                            break;
                        }
                        pos = pos->m_next;
                    }
                    if (nullptr == pos)
                    {
                        cur->m_next = newHt.m_table[bucketNo];
                        newHt.m_table[bucketNo] = cur;
                    }
                    else 
                    {
                        cur->m_next = pos->m_next;
                        pos->m_next = cur;
                    }
                    ++newHt.m_size;
                }
            }
            swap(newHt);
        }
    }

    size_t Size()
    {
        return m_size;
    }

    size_t Empty()
    {
        return m_size == 0;
    }

    size_t Count(const K& key)
    {
        int count = 0;
        size_t index = key % m_table.size();
        PNode cur = m_table[index];
        while (cur)
        {
            if (key == KOV()(key))
                count++;
            cur = cur->m_next;
        }
        return count;
    }

    Iterator Begin()
    {
        for (size_t bucketNo = 0; bucketNo < m_table.size(); bucketNo++)
        {
            if (m_table[bucketNo])
            {
                return Iterator(this, m_table[bucketNo]);
            }
        }
        return End();
    }

    Iterator End()
    {
        return Iterator(this, nullptr);
    }
    
    void Clear()
    {
        for (size_t bucketNo = 0; bucketNo < m_table.size(); bucketNo++)
        {
            PNode cur = m_table[bucketNo];
            while (cur)
            {
                m_table[bucketNo] = cur->m_next;
                delete cur;
                cur = m_table[bucketNo];
            }
        }
    }

    void Swap(Self& ht)
    {
        this->m_table.swzp(ht.m_table);
        swap(this->m_size, ht.m_size);
    }

    size_t BucktCount() const 
    {
        return m_table.size();
    }

    size_t BucketSIze(size_t bucketNo)
    {
        PNode cur = m_table[bucketNo];
        size_t count = 0;
        while (cur)
        {
            count++;
            cur = cur->m_next;
        }
        return count;
    }

private:
    size_t HashFunc(const K& key)
    {
        // 将 data 中的 key 提取出来
        // 将 key 转化成整型
        return (KTOINT()(key)) % m_table.capacity();
    }

private:
    std::vector<Node> m_table;
    size_t m_size;
};

struct KeyOfValue
{
    int operator()(int key)
    {
        return key;
    }
};

void Test()
{
    HashTable<int, int, KeyOfValue, KeyToIntDef<int>> ht;
}
