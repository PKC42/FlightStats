// Copyright 2023 Pratush Kc
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "compute.hpp"
#include "flight.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Welcome to FlightStats!" << std::endl;
    std::cout << std::endl;
    std::cout << "Note: If you haven't "
    "already, please create a list of raw files and "
    "and their paths in a file called parse_list.txt "
    "at the same location as the executable." << std::endl;
    std::cout << std::endl;

    // vector for file paths
    std::vector<std::string> file_paths_vector;

    // open file and and list parse list strings in a vector
    std::fstream parse_file;
    parse_file.open("parse_list.txt", std::ios::in);
    if(!parse_file){
        std::cerr << "Error: parse_file.txt not found!" << std::endl;
    }

    // declare string type to hold file path
    std::string file_path;

    // read file paths and store into vector
    while(1){
        if(parse_file.eof()){
            break;
        }
        parse_file >> file_path;
        file_paths_vector.push_back(file_path);
    }

    // print out file paths
    std::cout <<"File paths: "<< std::endl;
    for(int i = 0; i < (int)file_paths_vector.size(); i++){
        std::cout << file_paths_vector[i] << std::endl;
    }

    std::cout << std::endl;

    // validate paths, exit program if there is an invalid path
    if(validate_paths(file_paths_vector) == false){
        exit(1);
    };
    
    if(file_paths_vector.empty() == true){
        std::cerr << "Error: parse_list.txt is empty!" << std::endl;
    }

    std::cout << "Would you like to enable multithreading?" << std::endl;
    char choice = 'n';
    if(choice == 'n'){
        std::cout << "Multithreading disabled." << std::endl;
        for(int i = 0; i < (int)file_paths_vector.size(); i++){
            std::cout << parse_and_compute(file_paths_vector[i]) << std::endl;
        }
    }
    else{

    }
    return 0;
}
