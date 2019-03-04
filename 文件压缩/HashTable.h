#pragma once
#include <stdlib.h>
#include <string.h>

const unsigned short HASH_BITS = 15;
const unsigned short HASH_SIZE = (1 << HASH_BITS);
const unsigned short HASH_MASK = HASH_SIZE - 1;

static size_t W_SIZE = 32 * 1024;
static size_t MIN_MATCH = 3;
static size_t MAX_MATCH = 258;

class HashTable
{
public:
	HashTable(size_t size)
	:m_prev(new unsigned short[size*2])
	,m_head(m_prev+size)
	, m_HashSize(size)
	{
		memset(m_head, 0, sizeof(unsigned short)*size);
	}

	~HashTable()
	{
		if (m_prev)
		{
			delete[] m_prev;
			m_head = nullptr;
			m_prev = nullptr;
		}
	}

public:
	void HashFunc(unsigned short &HashAddr, unsigned char ch);
	unsigned short GetNext(unsigned short &Matchpos);
	void Insert(unsigned short &HashAddr, unsigned char ch, unsigned short pos, unsigned short &MatchHead);

private:
	unsigned short H_SHIFT();

private:
	unsigned short * m_prev;
	unsigned short *m_head;
	size_t m_HashSize;
};

unsigned short HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

// 忘记加引用
void HashTable::HashFunc(unsigned short &HashAddr, unsigned char ch)
{
	HashAddr = (((HashAddr) << H_SHIFT()) ^ ch) & HASH_MASK;
}

void HashTable::Insert(unsigned short &HashAddr, unsigned char ch, unsigned short pos, unsigned short &MatchHead)
{
	HashFunc(HashAddr, ch);
	m_prev[pos & HASH_MASK] = m_head[HashAddr];
	MatchHead = m_head[HashAddr];
	m_head[HashAddr] = pos;
}

unsigned short HashTable::GetNext(unsigned short &MatchPos)
{
	return m_prev[MatchPos];
}
