#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
using namespace std;
namespace pandemic{
    static const City all_places[]={City::Algiers,City::Atlanta,City::Baghdad,City::Bangkok,City::Beijing,City::Bogota,
                                City::BuenosAires,City::Cairo,City::Chennai,City::Chicago,City::Delhi,City::Essen,
                                City::HoChiMinhCity,City::HongKong,City::Istanbul,City::Jakarta,City::Johannesburg,
                                City::Karachi,City::Khartoum,City::Kinshasa,City::Kolkata,City::Lagos,City::Lima,
                                City::London,City::LosAngeles,City::Madrid,City::Manila,City::MexicoCity,City::Miami,
                                City::Milan,City::Montreal,City::Moscow,City::Mumbai,City::NewYork,City::Osaka,City::Paris,
                                City::Riyadh,City::SanFrancisco,City::Santiago,City::SaoPaulo,City::Seoul,City::Shanghai,City::StPetersburg,
                                City::Sydney,City::Taipei,City::Tehran,City::Tokyo,City::Washington
                                };
    
    class Board{
        public:

            Board();
            int& getSick(City city){return _sick[city];}
            Color& getColor(City city){return _colors[city];}
            bool& getCure(Color color){return _cure[color];};
            bool& getStation(City city){return _research[city];}
            set<City>& getHood(City city){return _neighbors[city];}
            int& operator[](City city);
            bool is_clean();
            friend ostream& operator<<(ostream& os, const Board& other);
            void remove_cures();
            void remove_stations();

        private:

            map<City,Color> _colors;
            map<Color,bool> _cure;
            map<City,bool> _research;
            map<City,set<City>> _neighbors;
            map<City,int> _sick;
    };
} 
