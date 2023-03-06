// Copyright 2023 Pratush Kc
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>
#include <string>
#include <vector>

#include "flight.hpp"
class Flight{
 public:
  //default constructor
  Flight();

  //init with all fields
  Flight(std::string _call_sign, std::string _date, 
  std::string _departure_time, double _distance, 
  double _top_speed, double _average_speed, double _total_time, 
  double _highest_altitude, double _average_altitude);

  // setter functions
  void set_call_sign(std::string _call_sign);

  void set_departure_date(std::string _departure_date);

  void set_departure_time(std::string _departure_time);

  void set_distance(double _distance);

  void set_top_speed(double _top_speed);

  void set_average_speed(double _average_speed);

  void set_total_time(double _total_time);

  void set_highest_altitude(double _highest_altitude);

  void set_average_altitude(double _average_altitude);


  // getter functions
  std::string get_call_sign();

  std::string get_departure_date();

  std::string get_departure_time();

  double get_distance();

  double get_top_speed();

  double get_average_speed();

  double get_total_time();

  double get_highest_altitude();

  double get_average_altitude();

  //friend function for printing out class
  friend std::ostream &operator << (std::ostream &out, const Flight &flight);

  
 private:
  std::string call_sign;
  std::string departure_date;
  std::string departure_time;
  double distance;
  double top_speed;
  double average_speed;
  double total_time;
  double highest_altitude;
  double average_altitude;

  /* To be included for potential future features
  std::vector<double> raw_times;
  std::vector<double> raw_latitudes;
  std::vector<double> raw_longitudes;
  std::vector<double> raw_altitudes;
  std::vector<double> raw_speeds;
  */
};

#endif
