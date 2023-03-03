#ifndef compute_hpp
#define compute_hpp
#include "flight.hpp"
#include <string>
#include <vector>
#include <fstream>
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


#endif