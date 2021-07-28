#include "Board.hpp"
#include "Player.hpp"
#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Medic::Medic(Board& board, const City& city): Player(board, city){
        _role ="Medic";
    }
    Medic& Medic::treat(const City& city){
        if( _board[city] == 0  || _city != city){
            throw exception();
        }
        _board[city] = 0;
        return *this;
    }
    Medic& Medic::drive(const City& other){
        if( _board.getHood(_city).find(other) == _board.getHood(_city).end() || _city == other){
            throw exception();
        }
        if(_board.getCure(_board.getColor(other))){
            _board[other] = 0;
        }
        _city = other;
        return *this;
    }
    Medic& Medic::fly_charter(const City& other){
        if( ! _hand[_city] || _city == other){
            throw exception();
        }
        if(_board.getCure(_board.getColor(other))){
            _board[other] = 0;
        }
        _hand[_city] = false;
        _city = other;
        return *this;
    }
    Medic& Medic::fly_shuttle(const City& other){
        if( ! _board.getStation(_city) || ! _board.getStation(other) || _city == other){
            throw exception();
        }if(_board.getCure(_board.getColor(other))){
            _board[other] = 0;
        }
        _city = other;
        return *this;
      
    }
    Medic& Medic::fly_direct(const City& other){
        if( ! _hand[other] || _city == other){
            throw exception();
        }
        if(_board.getCure(_board.getColor(other))){
            _board[other] = 0;
        }
        _hand[other] = false;;
        _city = other;
        return *this;
    }
 

}