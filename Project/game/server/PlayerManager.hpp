#pragma once 

#include <iostream>
#include <unordered_map>
#include "Player.hpp"
#include "Log.hpp"

#define DEAULT_ID 10000

class PlayerManager
{
public:
    PlayerManager()
        : assign_id(DEAULT_ID)
    {}

    // 插入
    uint32_t InsertPlayer(std::string& name, std::string& password)
    {
        uint32_t id = assign_id++;
        Player p(name, password, id);
        player_set.insert({id , p});
        LOG(INFO, "insert player done ...");
        return id;
    }

    // 查找
    uint32_t SearchPlayer(uint32_t& id, std::string& password)
    {
        auto iter = player_set.find(id);
        if (iter == player_set.end())
        {
            LOG(WARING, "Search Player Error ...");
            return 1;
        }

        Player& p = iter->second;
        if (p.Password() != password)
        {
            LOG(WARING, "Player Password Error ...");
            return 2;
        }

        p.Online();
        LOG(INFO, "Player Online Success...");
        return id;
    }

    ///////////////////////////////////////////////
    //  设置
    ///////////////////////////////////////////////
    
    void SetPlayStatus(uint32_t& one, uint32_t& two)
    {
        player_set[one].Playing();
        player_set[two].Playing();
    }
    
    void SetMatching(uint32_t& id)
    {
        player_set[id].Matching();
    }

    void SetPlayRoom(uint32_t& room_id, uint32_t& one, uint32_t& two)
    {
        player_set[one].SetRoom(room_id);
        player_set[two].SetRoom(room_id);
    }

    ///////////////////////////////////////////////
    //  获得
    ///////////////////////////////////////////////
    uint32_t GetPlayerRoomId(uint32_t& id)
    {
        return player_set[id].Room();
    }

    int GetRate(uint32_t& id)
    {
        return player_set[id].Rate();
    }

    int Ready(uint32_t& id)
    {
        return player_set[id].Status();
    }

    ~PlayerManager()
    {}

private:
    std::unordered_map<uint32_t, Player> player_set;
    uint32_t assign_id;
};
