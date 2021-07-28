#include "Board.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board& board, const City& city):Player(board,city){
        _role ="Dispatcher";
    }
    Dispatcher& Dispatcher::fly_direct(const City& other){
        if( _city == other){
            throw exception();
        }
        if( _board.getStation(_city)){
            _city = other;
            return *this;
        }
        if(!_hand[other]){
            throw exception();
        }
        _hand[other]= false;
        _city = other;
        return *this;
    }


}