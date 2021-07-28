#include "Board.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    FieldDoctor::FieldDoctor(Board& board, const City& city): Player(board, city){
        _role ="FieldDoctor";
    }
    
    FieldDoctor& FieldDoctor::treat(const City& other){
        if( _city != other){
            if(_board.getHood(_city).find(other) == _board.getHood(_city).end() || _board[other] == 0){
                throw exception();
            }
            if( _board.getCure(_board.getColor(other))){
                _board[other] = 0;
            }else{
                _board[other]--;
            }
        }else{
            if( _board[other] == 0){
                throw exception();
            }
            if( _board.getCure(_board.getColor(other))){
                _board[other] = 0;
            }else{
                _board[other]--;
            } 
        }
        return *this;
    }
}