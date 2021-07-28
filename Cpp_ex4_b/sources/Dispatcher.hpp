#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class Dispatcher : public Player{
    public:
        Dispatcher(Board& board, const City& city);
        Dispatcher& fly_direct(const City& other);
    };
}