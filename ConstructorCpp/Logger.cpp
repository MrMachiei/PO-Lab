#include "Logger.hpp"
void Logger::log(std::string t){
    time_t date;
    time(&date);
    std::cout << ctime(&date) << t << std::endl;
}
Logger::Logger(): debug(true){
}
Logger::Logger(bool debug): debug(debug){
}