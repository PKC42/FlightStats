// Copyright 2023 Pratush Kc
#include "flight.hpp"


// default constructor
Flight::Flight(){

}

// init with call sign
Flight::Flight(std::string _call_sign){

}

std::ostream &operator << (std::ostream &out, const Flight &flight){
    out << flight.call_sign << std::endl;

    return out;
}
