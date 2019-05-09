#include <iostream>
#include <unordered_map>
#include "Room.hpp"

#define ROOM_ID 1024

class RoomManager
{
public:
    RoomManager()
        :assign_id(ROOM_ID)
    {}

    ///////////////////////////////////////////////
    //  创建房间
    ///////////////////////////////////////////////
    uint32_t CreateRoom(uint32_t& one, uint32_t& two)
    {
        Room r(one, two);
        uint32_t id = assign_id++;
        room_set.insert({id, r});
        return id;
    }

    ///////////////////////////////////////////////
    //  获得棋盘
    ///////////////////////////////////////////////
    void GetBoard(uint32_t& room_id, std::string& board)
    {
        room_set[room_id].Board(board);
    }

    char GetPlayerPiece(uint32_t& room_id, uint32_t id)
    {
        return room_set[room_id].Piece(id);
    }

    bool IsMyTurn(uint32_t& room_id, uint32_t id)
    {
        return room_set[room_id].IsMyTurn(id);
    }

    void Step(uint32_t& room_id, uint32_t id, int& x, int& y)
    {
        return room_set[room_id].Step(id, x, y);
    }

    char Judge(uint32_t& room_id)
    {
        return room_set[room_id].GameResult();
    }
    ~RoomManager()
    {}
private:
    std::unordered_map<uint32_t, Room> room_set;
    uint32_t assign_id;
};

