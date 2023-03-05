// Copyright 2023 Pratush Kc
#include "flight.hpp"


//default constructor
Flight::Flight(){

}
  
//init with all fields
Flight::Flight(std::string _call_sign, std::string _date, 
    std::string _departure_time, double _distance, 
    double _top_speed, double _average_speed, double _total_time, 
    double _highest_altitude, double _average_altitude){
        call_sign = _call_sign;
        departure_date = _date;
        departure_time = _departure_time;
        distance = _distance;
        top_speed = _top_speed;
        average_speed = _average_speed;
        total_time = _total_time;
        highest_altitude = _highest_altitude;
        average_altitude = _average_altitude;
    }
// setter functions
void Flight::set_call_sign(std::string _call_sign){
    call_sign = _call_sign;
}

void Flight::set_departure_date(std::string _departure_date){
    departure_date = _departure_date;
}

void Flight::set_departure_time(std::string _departure_time){
    departure_time = _departure_time;
}

void Flight::set_distance(double _distance){
    distance = _distance;
}

void Flight::set_top_speed(double _top_speed){
    top_speed = _top_speed;
}

void Flight::set_average_speed(double _average_speed){
    average_speed = _average_speed;
}

void Flight::set_total_time(double _total_time){
    total_time = _total_time;
}

void Flight::set_highest_altitude(double _highest_altitude){
    highest_altitude = _highest_altitude;
}

void Flight::set_average_altitude(double _average_altitude){
    average_altitude = _average_altitude;
}

// getter functions
std::string Flight::get_call_sign(){
    return call_sign;
}

std::string Flight::get_departure_date(){
    return departure_date;
}

std::string Flight::get_departure_time(){
    return departure_time;
}

double Flight::get_distance(){
    return distance;
}

double Flight::get_top_speed(){
    return top_speed;
}

double Flight::get_average_speed(){
    return average_speed;
}

double Flight::get_total_time(){
    return total_time;
}

double Flight::get_highest_altitude(){
    return highest_altitude;
}

double Flight::get_average_altitude(){
    return average_altitude;
}

std::ostream &operator << (std::ostream &out, const Flight &flight){
    out << flight.call_sign << std::endl;

    return out;
}
