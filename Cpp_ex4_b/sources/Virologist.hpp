#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class Virologist : public Player{
    public:
        Virologist(Board& board, const City& city);
        Virologist& treat(const City& city);
    };
}