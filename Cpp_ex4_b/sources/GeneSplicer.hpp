#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class GeneSplicer : public Player{
    public:
        GeneSplicer(Board& board, const City& city);
        GeneSplicer& discover_cure(const Color& color);
    };
}