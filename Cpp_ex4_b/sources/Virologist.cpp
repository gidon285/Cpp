#include "Board.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Virologist::Virologist(Board& board, const City& city): Player(board, city){
        _role = "Virologist";
    }
    Virologist& Virologist::treat(const City& city){
        if( _city != city){
            if( _board[city] == 0 || ! _hand[city] ){
                throw exception();
            }
            if( _board.getCure(_board.getColor(city)) ){
                _board[city] = 0;
                _hand[city] = false;
            }else{
                _board[city]--;
                _hand[city] = false;
            }
        }else{
           if( _board.getCure(_board.getColor(city)) ){
                _board[city] = 0;
                _hand[city] = false;
            }else{
                _board[city]--;
                _hand[city] = false;
            } 
        }
        return *this;

    }
}   