#include "Board.hpp"
using namespace std;
namespace pandemic{
    Board::Board(){

        _cure[Color::Black] = false;
        _cure[Color::Blue] = false;
        _cure[Color::Red] = false;
        _cure[Color::Yellow] = false;

        for(const auto& e : all_places){
            _research[e] = false;
            _sick[e] = 0;
        }
        
        _colors[City::Algiers] = Color::Black;
        _colors[City::Atlanta] = Color::Blue;
        _colors[City::Baghdad] = Color::Black;
        _colors[City::Bangkok] = Color::Red;
        _colors[City::Beijing] = Color::Red;
        _colors[City::Bogota] = Color::Yellow;
        _colors[City::BuenosAires] = Color::Yellow;
        _colors[City::Cairo] = Color::Black;
        _colors[City::Chennai] = Color::Black;
        _colors[City::Chicago] = Color::Blue;
        _colors[City::Delhi] = Color::Black;
        _colors[City::Essen] = Color::Blue;
        _colors[City::HoChiMinhCity] = Color::Red;
        _colors[City::HongKong] = Color::Red;
        _colors[City::Istanbul] = Color::Black;
        _colors[City::Jakarta] = Color::Red;
        _colors[City::Johannesburg] = Color::Yellow;
        _colors[City::Karachi] = Color::Black;
        _colors[City::Khartoum] = Color::Yellow;
        _colors[City::Kinshasa] = Color::Yellow;
        _colors[City::Kolkata] = Color::Black;
        _colors[City::Lagos] = Color::Yellow;
        _colors[City::Lima] = Color::Yellow;
        _colors[City::London] = Color::Blue;
        _colors[City::LosAngeles] = Color::Yellow;
        _colors[City::Madrid] = Color::Blue;
        _colors[City::Manila] = Color::Red;
        _colors[City::MexicoCity] = Color::Yellow;
        _colors[City::Miami] = Color::Yellow;
        _colors[City::Milan] = Color::Blue;
        _colors[City::Montreal] = Color::Blue;
        _colors[City::Moscow] = Color::Black;
        _colors[City::Mumbai] = Color::Black;
        _colors[City::NewYork] = Color::Blue;
        _colors[City::Osaka] = Color::Red;
        _colors[City::Paris] = Color::Blue;
        _colors[City::Riyadh] = Color::Black;
        _colors[City::SanFrancisco] = Color::Blue;
        _colors[City::Santiago] = Color::Yellow;
        _colors[City::SaoPaulo] = Color::Yellow;
        _colors[City::Seoul] = Color::Red;
        _colors[City::Shanghai] = Color::Red;
        _colors[City::StPetersburg] = Color::Blue;
        _colors[City::Sydney] = Color::Red;
        _colors[City::Taipei] = Color::Red;
        _colors[City::Tehran] = Color::Black;
        _colors[City::Tokyo] = Color::Red;
        _colors[City::Washington] = Color::Blue;

        _neighbors[City::Algiers] = {City::Madrid, City::Paris, City::Istanbul,City::Cairo};
        _neighbors[City::Atlanta] = {City::Chicago,City::Miami,City::Washington};
        _neighbors[City::Baghdad] = {City::Tehran,City::Istanbul,City::Cairo,City::Riyadh,City::Karachi};
        _neighbors[City::Bangkok] = {City::Kolkata,City::Chennai,City::Jakarta,City::HoChiMinhCity,City::HongKong};
        _neighbors[City::Beijing] = {City::Shanghai,City::Seoul};
        _neighbors[City::Bogota] = {City::MexicoCity,City::Lima,City::Miami,City::SaoPaulo,City::BuenosAires};
        _neighbors[City::BuenosAires] = {City::Bogota,City::SaoPaulo};
        _neighbors[City::Cairo] = {City::Algiers,City::Istanbul,City::Baghdad,City::Khartoum,City::Riyadh};
        _neighbors[City::Karachi] = {City::Tehran,City::Baghdad,City::Riyadh,City::Mumbai,City::Delhi};
        _neighbors[City::Johannesburg] = {City::Kinshasa,City::Khartoum};
        _neighbors[City::Jakarta] = {City::Chennai,City::Bangkok,City::HoChiMinhCity,City::Sydney};
        _neighbors[City::Istanbul] = {City::Milan,City::Algiers,City::StPetersburg,City::Cairo,City::Baghdad,City::Moscow};
        _neighbors[City::HongKong] = {City::Bangkok,City::Kolkata,City::HoChiMinhCity,City::Shanghai,City::Manila,City::Taipei};
        _neighbors[City::HoChiMinhCity] = {City::Jakarta,City::Bangkok,City::HongKong,City::Manila};
        _neighbors[City::Essen] = {City::London,City::Paris,City::Milan,City::StPetersburg};
        _neighbors[City::Delhi] = {City::Tehran,City::Karachi,City::Mumbai,City::Chennai,City::Kolkata};
        _neighbors[City::Chicago] = {City::SanFrancisco,City::LosAngeles,City::MexicoCity,City::Atlanta,City::Montreal};
        _neighbors[City::Chennai] = {City::Mumbai,City::Delhi,City::Kolkata,City::Bangkok,City::Jakarta};
        _neighbors[City::MexicoCity] = {City::LosAngeles,City::Chicago,City::Miami,City::Lima,City::Bogota};
        _neighbors[City::Manila] = {City::Taipei,City::SanFrancisco,City::HoChiMinhCity,City::Sydney,City::HongKong};
        _neighbors[City::Madrid] = {City::London,City::NewYork,City::Paris,City::SaoPaulo,City::Algiers};
        _neighbors[City::LosAngeles] = {City::SanFrancisco,City::Chicago,City::MexicoCity,City::Sydney};
        _neighbors[City::London] = {City::NewYork,City::Madrid,City::Essen,City::Paris};
        _neighbors[City::Lima] = {City::MexicoCity,City::Bogota,City::Santiago};
        _neighbors[City::Lagos] = {City::SaoPaulo,City::Khartoum,City::Kinshasa};
        _neighbors[City::Kolkata] = {City::Delhi,City::Chennai,City::Bangkok,City::HongKong};
        _neighbors[City::Kinshasa] = {City::Lagos,City::Khartoum,City::Johannesburg};
        _neighbors[City::Khartoum] = {City::Cairo,City::Lagos,City::Kinshasa,City::Johannesburg};
        _neighbors[City::Miami] = {City::Atlanta,City::MexicoCity,City::Washington,City::Bogota};
        _neighbors[City::Milan] = {City::Essen,City::Paris,City::Istanbul};
        _neighbors[City::Montreal] = {City::Chicago,City::Washington,City::NewYork};
        _neighbors[City::Moscow] = {City::StPetersburg,City::Istanbul,City::Tehran};
        _neighbors[City::Mumbai] = {City::Karachi,City::Delhi,City::Chennai};
        _neighbors[City::NewYork] = {City::Montreal,City::Washington,City::London,City::Madrid};
        _neighbors[City::Osaka] = {City::Taipei,City::Tokyo};
        _neighbors[City::Paris] = {City::Algiers,City::Essen,City::Madrid,City::Milan,City::London};
        _neighbors[City::Riyadh] = {City::Baghdad,City::Cairo,City::Karachi};
        _neighbors[City::SanFrancisco]={City::LosAngeles,City::Chicago,City::Tokyo,City::Manila};
        _neighbors[City::Santiago] = {City::Lima};
        _neighbors[City::SaoPaulo] = {City::Bogota,City::BuenosAires,City::Lagos,City::Madrid};
        _neighbors[City::Seoul] = {City::Beijing,City::Shanghai,City::Tokyo};
        _neighbors[City::Shanghai] = {City::Beijing,City::HongKong,City::Taipei,City::Seoul,City::Tokyo};
        _neighbors[City::StPetersburg] = {City::Essen,City::Istanbul,City::Moscow};
        _neighbors[City::Sydney] = {City::Jakarta,City::Manila,City::LosAngeles};
        _neighbors[City::Taipei] = {City::Shanghai,City::HongKong,City::Osaka,City::Manila};
        _neighbors[City::Tehran] = {City::Baghdad,City::Moscow,City::Karachi,City::Delhi};
        _neighbors[City::Tokyo] = {City::Seoul,City::Shanghai,City::Osaka,City::SanFrancisco};
        _neighbors[City::Washington] = {City::Atlanta,City::NewYork,City::Montreal,City::Miami};

    }
    int& Board::operator[](City city){
        return _sick[city];
    }
    bool Board::is_clean(){
        for( const auto& place : _sick){
            if( place.second > 0){
                return false;
            }
        }
        return true;
    }
    ostream& operator<<(ostream& os, const Board& other){
        return os;
    }
    void Board::remove_cures(){
        for( auto& potion : _cure){
            potion.second = false;
        }
    }
    void Board::remove_stations(){
        for ( auto& stat : _research){
            stat.second = false;
        }
    }

}
