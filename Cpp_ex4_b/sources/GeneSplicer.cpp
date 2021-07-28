#include "Board.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    GeneSplicer::GeneSplicer(Board& board, const City& city): Player(board, city){
        _role ="GeneSplicer";
    }
    GeneSplicer& GeneSplicer::discover_cure(const Color& color){
        int count = 0;
        if( !_board.getStation(_city)){
            throw exception();
        }
        for( const auto& card : _hand){
            if( card.second){
                count++;
            }
        }
        if(count < discover){
            throw exception();
        }
        for( const auto& card2 : _hand){
            count--;
            _hand[card2.first] = false;
            if( count == 0){
                _board.getCure(color) = true;
                return *this;
            }
        }
        if( count > 0){
            throw exception();
        }
        return *this;
    }

}