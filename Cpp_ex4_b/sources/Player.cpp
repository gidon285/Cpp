#include "Player.hpp"
using namespace std;
namespace pandemic{
    Player::Player(Board& board,const City& city):_board(board),_city(city){}
    Player& Player::take_card(const City& city){
        if( ! _hand[city] ){
            _hand[city] = true;
        }
        return *this;
    }
    Player& Player::build(){
        if( _board.getStation(_city) ){
            return *this;
        }
        if( ! _hand[_city]){
            throw exception();
        }
        _hand[_city] = false; 
        _board.getStation(_city) = true;
        return *this;
    }
    Player& Player::treat(const City& city){
        if( _board.getSick(city) == 0 || _city != city){
            throw exception();
        }
        if( _board.getCure(_board.getColor(city))){
            _board[city] = 0;
        }else{
            _board[city]--;
        }
        return *this;
    }
    Player& Player::drive(const City& other){
        if( _board.getHood(_city).find(other) == _board.getHood(_city).end() || _city == other){
            throw exception();
        }
        _city = other;
        return *this;
    }
    Player& Player::fly_charter(const City& other){
        if( ! _hand[_city] || _city == other){
            throw exception();
        }
        _hand[_city] = false;
        _city = other;
        return *this;
    }
    Player& Player::fly_shuttle(const City& other){
        if( ! _board.getStation(_city) || ! _board.getStation(other) || _city == other){
            throw exception();
        }
        _city = other;
        return *this;
    }
    Player& Player::fly_direct(const City& other){
        if( ! _hand[other] || _city == other){
            throw exception();
        }
        _hand[other] = false;;
        _city = other;
        return *this;
    }
    Player& Player::discover_cure(const Color& color){
        int count = 0;
        if( !_board.getStation(_city)){
            throw exception();
        }
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
    Player& Player::remove_cards(){
        for( const auto& card : _hand){
            _hand[card.first] = false;
        }
        return *this;
    }


}
