#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include "PlayerManager.hpp"
#include "RoomManager.hpp"
#include "Log.hpp"

#define MATCH_LEVEL 101

class Hall
{
public:
    Hall()
        :m_match_pool(MATCH_LEVEL)
        ,m_match_num(0)
    {
    }

    int MatchNum()
    {
        return m_match_num;
    }

    void IncMatchNum()
    {
        m_match_num++;
    }

    void ResetMatchNum()
    {
        m_match_num = 0;
    }

    // 获得匹配池Id
    void GetAllMatchId(std::vector<uint32_t>& id_list)
    {
        for (auto i = MATCH_LEVEL-1; i >= 0; i--)
        {
            auto& v = m_match_pool[i];
            if (v.empty())
            {
                continue;
            }
            for (auto it = v.begin(); it != v.end(); it++)
            {
                id_list.push_back(*it);
            }
        }
    }

    ///////////////////////////////////////////////
    //  锁
    ///////////////////////////////////////////////
    void LockMatchPool()
    {
        pthread_mutex_lock(&match_lock);
    }
    void UnlockMatchPool()
    {
        pthread_mutex_unlock(&match_lock);
    }

    //  等待
    void ServiceWait()
    {
        pthread_cond_wait(&match_cond, &match_lock);
    }
    // 唤醒
    void ServiceWakeup()
    {
        pthread_cond_signal(&match_cond);
    }

    // 注册
    uint32_t Register(std::string& name, std::string& password)
    {
        return m_pm.InsertPlayer(name, password);
    }

    // 登录
    uint32_t Login(uint32_t& id, std::string& password)
    {
        return m_pm.SearchPlayer(id, password);
    }

    // 将ID Push 到匹配池
    bool PushIdInMatchPool(uint32_t& id)
    {
        LOG(INFO, "Push Player Into Match Pool ...");
        m_pm.SetMatching(id);
        int rate = m_pm.GetRate(id);
        std::cout << "rate:" << rate <<std::endl;
        LockMatchPool();
        auto& v_level = m_match_pool[rate];
        auto it = v_level.begin();
        for (; it != v_level.end(); it++)
        {
            if (*it == id)
            {
                return false;
            }
        }
        v_level.push_back(id);
        IncMatchNum();
        UnlockMatchPool();
        ServiceWakeup();
        return true;
    }

    // 清空
    void MatchPoolClear()
    {
        LOG(INFO, "Match pool clear");
        for (auto i = MATCH_LEVEL - 1; i >= 0; i--)
        {
            auto& v = m_match_pool[i];
            if (v.empty())
            {
                continue;
            }
            std::vector<uint32_t>().swap(v);
            ResetMatchNum();
        }
    }

    int IsPlayerReady(uint32_t& id)
    {
        return m_pm.Ready(id);
    }

    void GamePrepare(uint32_t& one, uint32_t& two)
    {
        m_pm.SetPlayStatus(one, two);
        uint32_t room_id = m_rm.CreateRoom(one, two);
        m_pm.SetPlayRoom(room_id, one, two);
       // m_pm.SignalPlayer(one, two);
    }
    static void* MatchService(void* arg)
    {
        pthread_detach(pthread_self());
        Hall* hp = (Hall*)arg;

        while (1)
        {
            hp->LockMatchPool();
            while (hp->MatchNum() < 2)
            {
                LOG(INFO, "Serivice pthread wait ...");
                hp->ServiceWait();
            }
            LOG(INFO, "service thread weakup ...");
            std::vector<uint32_t> id_list;
            hp->GetAllMatchId(id_list);

            int num = id_list.size();
            num &= (~1);

            for (auto i = 0; i <= num; i += 2)
            {
                uint32_t play_one = id_list[i];
                uint32_t play_two = id_list[i+1];
                hp->GamePrepare(play_one, play_two);
            }
            hp->MatchPoolClear();
            hp->UnlockMatchPool();
        }
    }

    void InitHall()
    {
        pthread_mutex_init(&match_lock, NULL);
        pthread_cond_init(&match_cond, NULL);
        
        pthread_t tid;
        pthread_create(&tid, NULL, MatchService, this);
    }

    ///////////////////////////////////////////////
    //  获得
    ///////////////////////////////////////////////
    std::string GetPlayerBoard(uint32_t& room_id)
    {
        std::string board;
        m_rm.GetBoard(room_id, board);
        return board;
    }
    uint32_t GetPlayerRoomId(uint32_t& id)
    {
        return m_pm.GetPlayerRoomId(id);
    }
    char GetPlayerPiece(uint32_t& room_id, uint32_t& id)
    {
        return m_rm.GetPlayerPiece(room_id, id);
    }
    bool IsMyTurn(uint32_t& room_id, uint32_t& id)
    {
        return m_rm.IsMyTurn(room_id, id);
    }
    void Step(uint32_t& room_id, uint32_t& id, int x, int y)
    {
        return m_rm.Step(room_id, id, x, y);
    }
    char Judge(uint32_t& room_id)
    {
        return m_rm.Judge(room_id);
    }

    ~Hall()
    {
        pthread_mutex_destroy(&match_lock);
        pthread_cond_destroy(&match_cond);
    }

private:
    PlayerManager m_pm;
    RoomManager m_rm;
    std::vector<std::vector<uint32_t> > m_match_pool;
    int m_match_num;
    pthread_mutex_t match_lock;
    pthread_cond_t match_cond;
};
