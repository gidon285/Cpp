#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class Medic : public Player{
        public:

            Medic(Board& board, const City& city);
            Medic& treat(const City& city);
            Medic& fly_direct(const City& other);
            Medic& drive(const City& other);
            Medic& fly_charter(const City& other);
            Medic& fly_shuttle(const City& other);
        };
}