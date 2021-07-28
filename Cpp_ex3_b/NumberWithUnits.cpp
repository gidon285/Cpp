#include "NumberWithUnits.hpp"
#include <sstream>
using namespace::std;

namespace ariel {

    NumberWithUnits::NumberWithUnits(double amount, const string &unit_type) {
        if (table.count(unit_type) > 0) {
            val = amount;
            unit = unit_type;
        }
        else {
            throw("Invalid Unit");
        }
    }

    void NumberWithUnits::read_units(ifstream &file_name) {
        string left, right;
        double sub_val = 0;
        while (!file_name.fail() && !file_name.eof() ) {
        file_name >> left;
        file_name >> left;
        file_name >> right;
        file_name >> sub_val;
        file_name >> right;
        table[left][right] = sub_val;
        table[right][left] = 1/sub_val;
        for (auto const &unit : table[left]) {
            table[unit.first][right] = sub_val / unit.second;
            table[right][unit.first] = unit.second / sub_val;
        }
        for (auto const &unit : table[right]) {
            table[unit.first][left] = (1/sub_val) / unit.second;
            table[left][unit.first] = unit.second / (1/sub_val);
        }
        }
    }

    NumberWithUnits NumberWithUnits::operator- () const {
        NumberWithUnits result(val * (-1), unit);
        return result;
    }

    NumberWithUnits & NumberWithUnits::operator-- () {
        val = val -1;
        return *this;
    }

    NumberWithUnits & NumberWithUnits::operator++ () {
        val = val +1;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator-- (int) {
        NumberWithUnits result(val, unit);
        val = val -1;
        return result;
    }

    NumberWithUnits NumberWithUnits::operator++ (int) {
        NumberWithUnits result(val, unit);
        val = val +1;
        return result;
    }

    NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0 && table[other_num.unit].count(unit) > 0) {
            double sum = val - (other_num.val * table[other_num.unit][unit]);
            return NumberWithUnits(sum, unit);   
        }
        throw("Invalid Unit");
    }

    NumberWithUnits NumberWithUnits::operator+ () const {
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator+ (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0 && table[other_num.unit].count(unit) > 0) {
            double sum = val + (other_num.val * table[other_num.unit][unit]);
            return NumberWithUnits(sum, unit);   
        }
        throw("Invalid Unit");
    }

    bool NumberWithUnits::operator> (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0) {
            return (table[unit][other_num.unit] * val > other_num.val
                || (table[unit][other_num.unit] * val - other_num.val) > EPS);
        }   
        throw("Invalid Unit");
    }

    bool NumberWithUnits::operator< (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0) {
            return (this->val < other_num.val * table[other_num.unit][unit]);
        }   
        throw("Invalid Unit");
    }

    bool NumberWithUnits::operator== (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0) {
            return (abs(val - other_num.val * table[other_num.unit][unit]) <= EPS);
        }
        throw("Invalid Unit");
    }

    bool NumberWithUnits::operator<= (const NumberWithUnits &other_num) const {
        return (*this < other_num || *this == other_num);
    }

    bool NumberWithUnits::operator>= (const NumberWithUnits &other_num) const {
        if (table[unit].count(other_num.unit) > 0) {
            return (this->val >= other_num.val * table[other_num.unit][unit]);
        }   
        throw("Invalid Unit");
    }

    bool NumberWithUnits::operator!= (const NumberWithUnits &other_num) const {
        return !(*this == other_num);
    }

    NumberWithUnits& NumberWithUnits::operator+= (const NumberWithUnits &num) {
        if (table[unit].count(num.unit) > 0) {
            val += (num.val * table[num.unit][unit]);
            return *this; 
        }
        throw("Invalid Unit");
    }

    NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits &num) {
        if (table[unit].count(num.unit) > 0) {
            val -= (num.val * table[num.unit][unit]);
            return *this; 
        }
        throw("Invalid Unit");
    }

    NumberWithUnits NumberWithUnits::operator* (double factor) const {
        return NumberWithUnits(val * factor, this->unit);
    }

    NumberWithUnits operator* (double factor, const NumberWithUnits &other_num) {
        return other_num * factor;
    }

    ostream& operator<< (ostream& stream, const NumberWithUnits &num) {
        stream << num.val << "[" << num.unit << "]";
        return stream;
    }

    istream& operator>> (istream& stream, NumberWithUnits &num) {
        double in_num = 0;
        string in_str, result_str, bracket, bracket2;
        stream >> in_num >> bracket;
        if (bracket[0] == '[' && bracket[bracket.size()-1] == ']') {
            for (string::size_type i=0; i < bracket.size(); i++) {
                if (bracket[i]  != '[' && bracket[i]  != ']' && bracket[i]  != ' ') {
                result_str += bracket[i];
                }
            }
            if (table.count(result_str) > 0) {
                num.val = in_num;
                num.unit = result_str;
                return stream;
            }
        }
        else if (bracket[0] == '[' && bracket[bracket.size()-1] != ']') {
            stream >> in_str;
            if (in_str == "]") {
                for (string::size_type i=0; i < bracket.size(); i++) {
                    if (bracket[i]  != '[' && bracket[i]  != ']' && bracket[i]  != ' ') {
                        result_str += bracket[i];
                    }
                }
                if (table.count(result_str) > 0) {
                    num.val = in_num;
                    num.unit = result_str;
                    return stream;
                }
            }
            else if (table.count(in_str) > 0) {
                stream >> bracket2;
                for (string::size_type i=0; i < in_str.size(); i++) {
                    if (in_str[i]  != '[' && in_str[i]  != ']' && in_str[i]  != ' ') {
                        result_str += in_str[i];
                    }
                }
                if (table.count(result_str) > 0) {
                    num.val = in_num;
                    num.unit = result_str;
                    return stream;
                }
            }
        }
        else {
            stream >> bracket2;
            for (string::size_type i=0; i < in_str.size(); i++) {
                if (in_str[i]  != '[' && in_str[i]  != ']' && in_str[i]  != ' ') {
                    result_str += in_str[i];
                }
            }
            if (table.count(result_str) > 0) {
                num.val = in_num;
                num.unit = result_str;
                return stream;
            }
        }
        throw("Wrong Input");
    }
}
