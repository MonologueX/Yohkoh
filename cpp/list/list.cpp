#include <iostream>
using namespace std;

namespace List
{
    template<class T>
    struct ListNode
    {
        ListNode(const T& value = T())
            : prev(nullptr)
            , next(nullptr)
            , val(value)
        {}
        ListNode<T> *prev;
        ListNode<T> *next;
        T val;
    };
    template<class T>
    class List
    {
        typedef ListNode<T> node;
        typedef node* PNode;
    public:
        List()
        {
            CreateNode();
            m_pHead->next = m_pHead;
            m_pHead->prev = m_pHead;
        }

        List(size_t n, const T& val)
        {
            CreateNode();
            for (size_t i= 0; i < n; i++)
            {
                push_back(val);
            }
        }
        List(T* first, T* last)
        {
            while (first != last)
            {
                push_back(*first++);
            }
        }
        ~List()
        {
            clear();
            delete m_pHead;
            m_pHead = nullptr;
        }
        ///////////////////////////////////////////////
        //  capacity
        ///////////////////////////////////////////////
        size_t size()const
        {
            size_t count = 0;
            PNode pCur = m_pHead->next;
            while (pCur != m_pHead)
            {
                count++;
                pCur = pCur->next;
            }
        }

        bool empty()const
        {
            return m_pHead->next == m_pHead->next;
        }
    private:
        void CreateNode(const T& val = T())
        {
            return new node(val);
        }
    private:
        PNode* m_pHead;
    };

};


int main()
{
    
    return 0;
}
