#ifndef compute_hpp
#define compute_hpp
#include "flight.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "boost/regex.hpp"

bool validate_paths(std::vector<std::string> paths);

Flight parse_and_compute(std::string file_path);


std::string get_callsign(std::string _raw_string);

std::string get_date(std::string _raw_string);

#endif