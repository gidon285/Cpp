#include "Board.hpp"
#include "Player.hpp"
#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    Scientist::Scientist(Board& board, const City& city,int n): Player(board, city),_n(n) {
        _role = "Scientist";
    }
    Scientist& Scientist::discover_cure(const Color& color){
        int count = 0;
        if( !_board.getStation(_city)){
            throw exception();
        }
        for( const auto& card : _hand){
            if( card.second && _board.getColor(card.first) == color ){
                count++;
            }
        }
        if(count < _n){
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