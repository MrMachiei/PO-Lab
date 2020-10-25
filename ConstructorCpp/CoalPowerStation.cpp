#include "CoalPowerStation.hpp"

CoalPowerStation::CoalPowerStation(): maxCoalOnFeeder(nullptr),
stockStatus(nullptr),
efficiency(nullptr),
numberOfEmployees(nullptr),
isActive(nullptr){
    *stockStatus = 0;
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
CoalPowerStation::CoalPowerStation(CoalPowerStation &&A):
    maxCoalOnFeeder(A.maxCoalOnFeeder),
    stockStatus(A.stockStatus),
    efficiency(A.efficiency),
    numberOfEmployees(A.numberOfEmployees),
    isActive(A.isActive){
        A.maxCoalOnFeeder = nullptr;
        A.stockStatus = nullptr;
        A.numberOfEmployees = nullptr;
        A.efficiency = nullptr;
        A.isActive = nullptr;
}
CoalPowerStation::CoalPowerStation(double stockStatus):
    maxCoalOnFeeder(nullptr),
    stockStatus(new double),
    efficiency(nullptr),
    numberOfEmployees(nullptr),
    isActive(nullptr){
        *(this->stockStatus) = stockStatus;
    }
void CoalPowerStation::setMaxCoalOnFeeder(double amount){
    if (amount <= 0) return; //miejsce na exception
    if (*maxCoalOnFeeder == 0) *maxCoalOnFeeder = amount;
    //miejsce na exception
    }
void CoalPowerStation::setEfficiency(double efficiency){
    if (efficiency > 1 || efficiency <= 0) return; //Exception
    *(this->efficiency) = efficiency;
}
void CoalPowerStation::setIsActive(bool isActive){
    *(this->isActive) = isActive;
}
    //%%%%%%%%
double CoalPowerStation::getMaxCoalOnFeeder(){
    return *maxCoalOnFeeder;
}
double CoalPowerStation::getStockStatus(){
    return *stockStatus;
}
double CoalPowerStation::getEfficiency(){
    return *efficiency;
}
double CoalPowerStation::getNumberOfEmployees(){
    return *numberOfEmployees;
}
bool CoalPowerStation::getIsActive(){
    return *isActive;
}
//voidy czy booleany?
//%%%%%%%%
void CoalPowerStation::addToStock(int amount){
    if (amount <= 0) return; //miejsce na exception
    *stockStatus += amount;
}
void CoalPowerStation::hireEmployees(int amount){
    if (amount <= 0) return;// false; //miejsce na exception
    if(numberOfEmployees == nullptr){
        numberOfEmployees = new int;
        *numberOfEmployees = 0;
    }
    *numberOfEmployees += amount;
    //return true;
}
void CoalPowerStation::fireEmployees(int amount){
    if (amount <= 0) return; //miejsce na exception
    //if (amount >= numberOfEmployees) return false; //tez exception
    *numberOfEmployees -= amount;
    //return true;  
}
//sprawdzic czy da sie wszystko zrobic!!!
void CoalPowerStation::takeMaxFeederFromStock(){
    if (*stockStatus < *maxCoalOnFeeder) return; // miesjce na exception
    *stockStatus -= *maxCoalOnFeeder;
    //return true;
}