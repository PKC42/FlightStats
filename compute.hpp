#ifndef compute_hpp
#define compute_hpp
#include "flight.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "boost/regex.hpp"

bool validate_paths(std::vector<std::string> paths);

Flight parse_and_compute(std::string file_path);

std::string get_callsign(std::string raw_string);

double get_time_stamp(std::string raw_string);

std::string get_date(std::string raw_string);

std::string get_departure_time(std::string raw_string);

double get_latitude(std::string raw_string);

double get_longitude(std::string raw_string);

double get_altitude(std::string raw_string);

double get_speed(std::string raw_string);

template<typename T>
void print_vector(std::vector<T> vector);

double get_distance_traveled(std::vector<double>latitudes, 
    std::vector<double>longitudes);

double deg_to_rad(double val);

#endif