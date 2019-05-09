#pragma once 

#include <iostream>
#include <pthread.h>
#include <string>
#include <time.h>

typedef enum
{
    OFFLINE = 0,
    ONLINE,
    MATCHING,
    PLAYING,
}statut_t;

class Player
{
public:
    // 构造函数
    Player(std::string& name, std::string& password, uint32_t &id)
        : m_name(name)
        , m_password(password)
        , m_id(id)
    {
        m_win = 0;
        m_lose = 0;
        m_draw = 0;
        m_st = OFFLINE;
    }
    Player()
    {}

    const std::string& Password()
    {
        return m_password;
    }

    void Online()
    {
        m_st = ONLINE;
    }

    int Status()
    {
        return m_st;
    }

    int Rate()
    {
        int total = m_win + m_lose;
        if (total == 0)
        {
            return 0;
        }
        return m_win * 100 / total;
    }

    void Matching()
    {
        m_st = MATCHING;
    }
    void Playing()
    {
        m_st = PLAYING;
    }

    uint32_t Room()
    {
        return m_room_id;
    }
    void SetRoom(uint32_t& room_id)
    {
        m_room_id = room_id;
    }
    ~Player()
    {}

private:
    std::string m_name;
    std::string m_password;
    uint32_t m_id;

    int m_win;
    int m_lose;
    int m_draw;

    statut_t m_st;
    uint32_t m_room_id;
};

