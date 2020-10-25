#include "CoalPowerStation.hpp"

CoalPowerStation::CoalPowerStation(): maxCoalOnFeeder(nullptr),
stockStatus(nullptr),
efficiency(nullptr),
numberOfEmployees(nullptr),
isActive(nullptr){
    }
CoalPowerStation::~CoalPowerStation(){
    if(maxCoalOnFeeder != nullptr) delete maxCoalOnFeeder;
    if(stockStatus != nullptr) delete stockStatus;
    if(efficiency != nullptr) delete efficiency;
    if(numberOfEmployees != nullptr) delete numberOfEmployees;
    if(isActive != nullptr) delete isActive;
}
CoalPowerStation::CoalPowerStation(const CoalPowerStation &A):
    maxCoalOnFeeder(new double),
    stockStatus(new double),
    efficiency(new double),
    numberOfEmployees(new int),
    isActive(new bool){
    *maxCoalOnFeeder = *(A.maxCoalOnFeeder);
    *stockStatus = *(A.stockStatus);
    *efficiency = *(A.efficiency);
    *numberOfEmployees = *(A.numberOfEmployees);
    *isActive = *(A.isActive);
}
CoalPowerStation::CoalPowerStation(CoalPowerStation &&A){
    
}