c:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pClo = new RandomListNode(0);
            pClo->label = pNode->label;
            pClo->next = pNode->next;
            pClo->random = nullptr;
            pNode->next = pClo;
            pNode = pClo->next;
        }
         
        pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pClo = pNode->next;
            if (pNode->random != nullptr)
            {
                pClo->random = pNode->random->next;
            }
            pNode = pClo->next;
        }
         
        pNode = pHead;
        RandomListNode *pCloHead = nullptr;
        RandomListNode *pCloNode = nullptr;
        if (pNode != nullptr)
        {
            pCloHead = pCloNode = pNode->next;
            pNode->next = pCloNode->next;
            pNode = pNode->next;
        }
        while (pNode != nullptr)
        {
            pCloNode->next = pNode->next;
            pCloNode = pCloNode->next;
            pNode->next = pCloNode->next;
            pNode = pNode->next;
        }
        return pCloHead;
    }
};
