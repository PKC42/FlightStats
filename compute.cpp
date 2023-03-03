#include "compute.hpp"

bool validate_paths(std::vector<std::string> paths){

    std::fstream file_paths;
    bool result = true;

    for(int i = 0; i < (int)paths.size(); i++){
        file_paths.open(paths[i], std::ios::in);
        if(!file_paths){
            std::cerr << "Error: " << paths[i] <<" not found!" << std::endl;
            result = false;
        }
        file_paths.close();
    }

    return result;
}

Flight parse_and_compute(std::string file_path){
    Flight data;
    std::fstream file;
    std::string line_data;

    //std::vector <double> speeds;
    //std::vector <double> altitudes;
    //std::vector <double> time;
    //double date;
    //double time;

    file.open(file_path, std::ios::in);
    
    if(!file){
        std::cerr << "Error: " << file_path <<" not found!" << std::endl;
        exit(1);
    }
    
    while(1){
        if(file.eof()){
            break;
        }
        file >> line_data;
        
        //std::cout << line_data;
        //std::cout << std::endl;
    }

    return data;
}


std::string get_callsign(std::string raw_string){
    std::string call_sign;

    int i = 0, j = 0;

    for(i = 0; j != 3; i++){

        if(j == 2){
            call_sign.push_back(raw_string.at(i));
        }

        if(raw_string[i] == ','){
            j++;
        }
    }
    
    // pop off comma
    call_sign.pop_back();

    std::cout << call_sign << std::endl;

    return call_sign;
}

double get_time_stamp(std::string raw_string){
    std::string time_stamp_string;

    int i = 0, j = 0;

    for(i = 0; j != 1; i++){

        if(j == 0){
            time_stamp_string.push_back(raw_string.at(i));
        }

        if(raw_string[i] == ','){
            j++;
        }
    }
    
    // pop off comma
    time_stamp_string.pop_back();

    return std::stod(time_stamp_string);
    
}

std::string get_date(std::string raw_string){
    std::string date_string;
    int i = 0;

    for(i = 11; i < 21; i++){
        date_string.push_back(raw_string.at(i));
    }

    return date_string;
}

double get_latitude(std::string raw_string){
    std::string latitude;
    int i = 0, j = 0;

    for(i = 0; j != 2; i++){

        if(j > 0){
            latitude.push_back(raw_string.at(i));
        }

        if(raw_string.at(i) == '"'){
            j++;
        }
    }

    while(latitude.at(latitude.size() - 1) != ','){
        latitude.pop_back();
    }
    latitude.pop_back();

    return stod(latitude);
}

double get_longitude(std::string raw_string){
    std::string longitude;
    int i = 0; int j = 0;

    for(i = 0; j < 5; i++){

        if(j == 4){
            longitude.push_back(raw_string.at(i));
        }

        if(raw_string.at(i) == ','){
            j++;
        }
    }
    
    longitude.pop_back();
    longitude.pop_back();

    return stod(longitude);
}

double get_altitude(std::string raw_string){
    std::string altitude;
    int i = 0, j = 0;

    for(i = 0; j != 6; i++){
        if(j == 5){
            altitude.push_back(raw_string.at(i));
        }

        if(raw_string.at(i) == ','){
            j++;
        }
    }

    altitude.pop_back();

    return stod(altitude);
}

double get_speed(std::string raw_string){
    std::string speed;
    int i = 0, j = 0;

    for(i = 0; j != 7; i++){
        if(j == 6){
            speed.push_back(raw_string.at(i));
        }

        if(raw_string.at(i) == ','){
            j++;
        }
    }

    speed.pop_back();

    return stod(speed);
}