#include "CoalPowerStation.hpp"

CoalPowerStation::CoalPowerStation(): maxCoalOnFeeder(nullptr), stockStatus(nullptr), efficiency(nullptr), numberOfEmployees(nullptr), isActive(nullptr){
    }
CoalPowerStation::~CoalPowerStation(){
    if(maxCoalOnFeeder != nullptr) delete maxCoalOnFeeder;
    if(stockStatus != nullptr) delete stockStatus;
    if(efficiency != nullptr) delete efficiency;
    if(numberOfEmployees != nullptr) delete numberOfEmployees;
    if(isActive != nullptr) delete isActive;
}