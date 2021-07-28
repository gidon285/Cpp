#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using std::string;
using std::map;
using std::pair;
using std::ifstream;
using std::ostream;
using std::istream;

namespace ariel {
    static map <string, map <string, double>> table;
    const static double EPS = 0.00001;

    class NumberWithUnits {
        private:
            double val;
            string unit;

        public:
            //Constructor
            NumberWithUnits(double amount, const string &unit_type);
            //Units Initialization
		    static void read_units(ifstream &file_name);
            //Arithmetic Operators
            NumberWithUnits operator- () const;
            NumberWithUnits operator+ (const NumberWithUnits &other_num) const;
            NumberWithUnits operator+ () const;
            NumberWithUnits & operator-- ();
            NumberWithUnits & operator++ ();
            NumberWithUnits operator-- (int);
            NumberWithUnits operator++ (int);
            NumberWithUnits operator- (const NumberWithUnits &other_num) const;
            NumberWithUnits& operator+= (const NumberWithUnits &num);
            NumberWithUnits& operator-= (const NumberWithUnits &num);
            NumberWithUnits operator* (double factor) const;
            friend NumberWithUnits operator* (double factor, const NumberWithUnits &other_num);
            //Boolean Operators
            bool operator> (const NumberWithUnits &other_num) const;
            bool operator< (const NumberWithUnits &other_num) const;
            bool operator== (const NumberWithUnits &other_num) const;
            bool operator<= (const NumberWithUnits &other_num) const;
            bool operator>= (const NumberWithUnits &other_num) const;
            bool operator!= (const  NumberWithUnits &other_num) const;
            //IO Stream
            friend ostream& operator<< (ostream& stream, const NumberWithUnits &num);
            friend istream& operator>> (istream& stream, NumberWithUnits &num);
	};
}
