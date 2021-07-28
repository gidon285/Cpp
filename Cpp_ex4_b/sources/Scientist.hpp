#pragma once
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{
    class Scientist : public Player{
    public:
        Scientist(Board& board, const City& city, int n);
        int& getN(){return _n;};
        Scientist& discover_cure(const Color& color);
    private:
        int _n;
    };
}