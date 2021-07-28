#include "Board.hpp"
#include "Player.hpp"
#include "Researcher.hpp"

using namespace std;

namespace pandemic
{
    Researcher::Researcher(Board& board, const City& city): Player(board, city){
        _role ="Researcher";
    }
    Researcher& Researcher::discover_cure(const Color& color){
      int count = 0;
        for( const auto& card : _hand){
            if( card.second && _board.getColor(card.first) == color ){
                count++;
            }
        }
        if(count < discover){
            throw exception();
        }
        for( const auto& card2 : _hand){
            if( card2.second && _board.getColor(card2.first) == color ){
                count--;
                _hand[card2.first] = false;
            }
            if( count == 0){
                _board.getCure(color) = true;
                return *this;
            }
        }
        return *this;
    }
}