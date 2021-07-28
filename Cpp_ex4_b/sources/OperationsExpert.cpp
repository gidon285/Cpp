#include "Board.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic
{
    OperationsExpert::OperationsExpert(Board& board, const City& city): Player(board, city){
        _role = "OperationsExpert";
    }
    OperationsExpert& OperationsExpert::build(){
        if( _board.getStation(_city) ){
            return *this;
        }
        _board.getStation(_city) = true;
        return *this;
    }
}