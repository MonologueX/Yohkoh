#pragma once 

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define SIZE 15
#define BLACK 'X'
#define WHITE 'O'

class Room
{
public:
    Room(uint32_t& id1, uint32_t& id2)
        : m_one(id1)
        , m_two(id2)
    {
        m_piece[0] = 'X';
        m_piece[1] = 'O';
        memset(m_board, '+', sizeof(m_board));
        m_result = 'N';
        m_current = m_one;
        pthread_mutex_init(&lock, NULL);
    } 

    Room()
    {}

    void Board(std::string& board)
    {
        for (auto i = 0; i < SIZE; i++)
        {
            for (auto j = 0; j < SIZE; j++)
            {
                board.push_back(m_board[i][j]);
            }
        }
    }

    char Piece(uint32_t& id)
    {
        int pos = (id == m_one ? 0 : 1);
        return m_piece[pos];
    }

    bool IsMyTurn(uint32_t& id)
    {
        return (id == m_current ? true : false);
    }

    void Step(uint32_t& id, int& x, int& y)
    {
        if (m_current == id)
        {
            int pos = (id == m_one ? 0 : 1);
            m_board[x][y] = m_piece[pos];
            m_current = (id == m_one ? m_two : m_one);
            m_result = Judge();
        }
    }

    char GameResult()
    {
        return m_result;
    }

    char Judge()
    {
        int row = SIZE;
        int col = SIZE;
        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col-4; j++)
            {
                if (m_board[i][j+0] != '+' && \
                    m_board[i][j+0] == m_board[i][j+1] && \
                    m_board[i][j+1] == m_board[i][j+2] && \
                    m_board[i][j+2] == m_board[i][j+3] && \
                    m_board[i][j+3] == m_board[i][j+4])
                {
                    return m_board[i][j];
                }
            }
        }
        for (auto j = 0; j < col; j++)
        {
            for (auto i = 0; i < row-4; i++)
            {
                if (m_board[i+0][j] != '+' && \
                    m_board[i+0][j] == m_board[i+1][j] && \
                    m_board[i+1][j] == m_board[i+2][j] && \
                    m_board[i+2][j] == m_board[i+3][j] && \
                    m_board[i+3][j] == m_board[i+4][j])
                {
                    return m_board[i][j];
                }
            }
        }
        for (auto i = 0; i < row-4; i++)
        {
            if (m_board[i+0][i+0] != '+' && \
                m_board[i+0][i+0] == m_board[i+1][i+1] && \
                m_board[i+1][i+1] == m_board[i+2][i+2] && \
                m_board[i+2][i+2] == m_board[i+3][i+3] && \
                m_board[i+3][i+3] == m_board[i+4][i+4])
            {
                return m_board[i][i];
            }
        }
        for (auto i = 0; i < row-4; i++)
        {
            if (m_board[i+0][col-i-1] != '+' && \
                m_board[i+0][col-i-1] == m_board[i+1][col-i-2] && \
                m_board[i+1][col-i-2] == m_board[i+2][col-i-3] && \
                m_board[i+2][col-i-3] == m_board[i+3][col-i-4] && \
                m_board[i+3][col-i-4] == m_board[i+4][col-i-5])
            {
                return m_board[i][col-i-1];
            }
        }
        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col; j++)
            {
                if ('+' == m_board[i][j])
                {
                    return 'N';
                }
            }
        }
        return 'E';
    }

    ~Room()
    {
        pthread_mutex_destroy(&lock);
    }
private:
    uint32_t m_one;
    uint32_t m_two;
    char m_piece[2];
    uint32_t m_current;
    char m_board[SIZE][SIZE];
    char m_result;
    pthread_mutex_t lock;
};
