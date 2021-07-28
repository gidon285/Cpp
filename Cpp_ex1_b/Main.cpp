#include <iostream>
#include "snowman.hpp"

int main(){

    std::cout<< "Please enter a number" <<std::endl;
    int input=0;
    while(true)
    {
        std::cin >> input;
        if(!std::cin){

            std::cout<< "invalid input"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::string s = ariel::snowman(input);
        std::cout << s << std::endl;

        return 0;
    }
}

