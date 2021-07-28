#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class FieldDoctor : public Player{
    public:
        FieldDoctor(Board& board, const City& city);
        FieldDoctor& treat(const City& other);
    };
}