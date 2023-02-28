// Copyright 2023 Pratush Kc
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>
#include <string>

#include "flight.hpp"
class Flight{
 public:
  //default constructor
  Flight();

  //init with call sign
  Flight(std::string _call_sign);

  //friend function for printing out class
  friend std::ostream &operator << (std::ostream &out, const Flight &flight);
  
 private:
  std::string call_sign;
  double distance;
  double top_speed;
  double average_speed;
  double total_time;
};

#endif
