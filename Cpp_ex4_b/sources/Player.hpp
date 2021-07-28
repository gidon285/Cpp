#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "Board.hpp"
#include "Color.hpp"
using namespace std;
#define discover 5
using namespace pandemic;
namespace pandemic{
    class Player
    {
   
    public:
     
        Player(Board& board, const City& city);
        virtual Player& build();
        virtual Player& take_card(const City& city);
        virtual Player& treat(const City& city);
        virtual Player& drive(const City& other);
        virtual Player& fly_charter(const City& other);
        virtual Player& fly_shuttle(const City& other);
        virtual Player& fly_direct(const City& other);
        virtual Player& discover_cure(const Color& color);
        virtual Player& remove_cards();
        virtual map<City,bool>& getHand(){return _hand;};
        virtual string role(){return _role;};

        protected:
            map<City,bool> _hand;
            Board& _board;
            City _city;
            string _role;
    };
   

}