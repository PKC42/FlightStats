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

    file.open(file_path, std::ios::in);
    
    if(!file){
        std::cerr << "Error: " << file_path <<" not found!" << std::endl;
        exit(1);
    }

    std::vector<double> raw_times;
    std::vector<double> raw_latitudes;
    std::vector<double> raw_longitudes;
    std::vector<double> raw_altitudes;
    std::vector<double> raw_speeds;

   
    
    for(int i = 0; file.eof() == false; i++){
        file >> line_data;

        if(i == 1){
            std::string callsign = get_callsign(line_data);
            std::string departure_date = get_date(line_data);
            std::string departure_time = get_departure_time(line_data);
        }
        
        if(i != 0){
            raw_times.push_back(get_time_stamp(line_data));
            raw_latitudes.push_back(get_latitude(line_data));
            raw_longitudes.push_back(get_longitude(line_data));
            raw_altitudes.push_back(get_altitude(line_data));
            raw_speeds.push_back(get_speed(line_data));
        }
    }

    
    double distance = get_distance_traveled(raw_latitudes, raw_longitudes);
    std::cout << distance << std::endl;
    //double top_speed;
    //double average_speed; 
    //double total_time
    //double highest_altitude;
    //double average_altitude;

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

std::string get_departure_time(std::string raw_string){
    std::string departure_time;

    for(int i = 0; i <= 30; i++){
        if(i >= 22){
            departure_time.push_back(raw_string.at(i));
        }
    }

    return departure_time;
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

template<typename T>
void print_vector(std::vector<T> vector){
    for(int i = 0; i < (int)vector.size(); i++){
        std::cout << vector.at(i) << " ";
        if(i % 5 == 0){
            std::cout << std::endl;
        }
    }

}

double get_distance_traveled(std::vector<double>latitudes, 
    std::vector<double>longitudes){
    double summed_distance = 0;
    double lat_diff, long_diff, x;

    for(int i = 0; i < (int)latitudes.size() - 1; i++){
        lat_diff = latitudes[i] - latitudes[i + 1];
        long_diff = longitudes[i] - longitudes[i + 1];
        
        //haversine formula (Split in 2)
        x = pow(sin(lat_diff/2), 2) +
            pow(sin(long_diff/2), 2) *
            (cos(lat_diff/2)) * cos(long_diff/2);
        
        // radius of earth is approx 6378.14 km
        summed_distance += 2*6378.14 * asin(sqrt(x));
    }

    return summed_distance;
}

double deg_to_rad(double val){
    return (val * M_PI) / 180;
}