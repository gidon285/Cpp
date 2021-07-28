#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class Researcher : public Player{
    public:
        Researcher(Board& board, const City& city);
        Researcher& discover_cure(const Color& color);
    };
}