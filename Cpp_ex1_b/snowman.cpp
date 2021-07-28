#include "snowman.hpp"
#include <iostream>
#include <exception>




namespace ariel
{
   
    const int Input_Size = 8;  //number of watned digits.
    const int Get_digit = 10;  // const 10 for modulo operator
    const std::string snow;         // snowman string
    std::string snowman(int input)
    {
        std::array<int,Input_Size> arr {};      // the array that will be given
        if( input <= 0){                        // input value
            throw ariel::myTotalinputexp();     
        }
        int arrlen = sizeof(arr)/ sizeof(int);  // get size of array
        int i = Input_Size -1 ;                 // the final index
        int digit = 0;                          // given digit
        while( i >= 0)
        {   
            digit = input % Get_digit;          // use modulo to get last digit.
            if(digit > 4 || digit < 1 ){
                throw ariel::myIternalinputexp();
            }
            if(input  == 0){
                throw ariel::myTotalinputexp();
            }
            arr.at(i) = digit;                  // save the digit.
            input /= Get_digit;                 // divide by 10 to progress building.
            i--;
        }
        if( i < 0 && input != 0 ){              // worst case handeling
            throw ariel::myTotalinputexp();
        }                                                                       // building the actual snowman
        return std::string( Hat.at(arr.at(h)-1)+"\n"+X1arm.at(arr.at(la)-1)+
                            +"("+LReye.at(arr.at(le)-1)+Nose.at(arr.at(n)-1) + 
                            LReye.at(arr.at(re)-1) + ")" + Y1arm.at(arr.at(ra)-1) +"\n"+
                            X2arm.at(arr.at(la)-1) + "(" + Torso.at(arr.at(t)-1) + ")" +
                            Y2arm.at(arr.at(ra)-1) + "\n" +"(" + Buttom.at(arr.at(b)-1) + ")");
    }
 
}   
