#include <stdio.h>
#include "Board.hpp"
using namespace std;



int main(){

    ariel::Board b;
    b.post(1,0,ariel::Direction::Horizontal,"#############");
    b.post(2,0,ariel::Direction::Horizontal,"#__gidon's__#");
    b.post(3,0,ariel::Direction::Horizontal,"#__message__#");
    b.post(4,0,ariel::Direction::Horizontal,"#___board___#");
    b.post(5,0,ariel::Direction::Horizontal,"#___-----___#");
    b.post(6,0,ariel::Direction::Horizontal,"#___     ___#");
    b.post(7,0,ariel::Direction::Horizontal,"#___     ___#");
    b.post(8,0,ariel::Direction::Horizontal,"#___!!!!!___#");
    b.post(9,0,ariel::Direction::Horizontal,"#############");
    b.show();

	return 0;

}
