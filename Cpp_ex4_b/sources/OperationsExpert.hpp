#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class OperationsExpert : public Player{
    public:
        OperationsExpert(Board& board, const City& city);
        OperationsExpert& build();
    };
}