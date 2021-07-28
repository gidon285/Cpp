#include <iostream>
#include <array>


namespace ariel
{   
    struct myTotalinputexp : std::exception{            // exeption
        const char *what() const throw()
        {
        return "Invalid input, please enter non-negative, eight figures integers."; 
        }
    };
    struct myIternalinputexp : std::exception{          // expetion
        const char *what() const throw()
        {
        return "Invalid input, valid input is range between 1-4."; 
        }
    };
    const int Snowman_Arguments =4; // for size of the array
    const int h = 0;                // hat index
    const int n = 1;                // nose index
    const int le = 2;               // left eye index
    const int re = 3;               // right eye index
    const int la = 4;               // left arm index
    const int ra= 5;                // right arm index
    const int t = 6;                // torso index
    const int b = 7;                // button index
    const std::array<std::string,Snowman_Arguments> Hat  {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
    const std::array<std::string,Snowman_Arguments> Nose  {",",".","_"," "};
    const std::array<std::string,Snowman_Arguments> LReye {".","o","O","-"};
    const std::array<std::string,Snowman_Arguments> Y1arm {" ","/"," "," "};
    const std::array<std::string,Snowman_Arguments> Y2arm {">"," ","\\"," "};
    const std::array<std::string,Snowman_Arguments> X1arm {" ","\\"," "," "};
    const std::array<std::string,Snowman_Arguments> X2arm {"<"," ","/"," "};
    const std::array<std::string,Snowman_Arguments> Torso  {" : ","] [","> <","   "};
    const std::array<std::string,Snowman_Arguments> Buttom  {" : ","\" \"","___","   "};
    std::string snowman(int input);
}