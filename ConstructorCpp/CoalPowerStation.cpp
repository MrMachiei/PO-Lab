#include "CoalPowerStation.hpp"
CoalPowerStation::CoalPowerStation(): maxCoalOnFeeder(nullptr),
stockStatus(nullptr),
efficiency(nullptr),
numberOfEmployees(nullptr),
isActive(nullptr){
    *stockStatus = 0;
    reset();
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
    reset();
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
        reset();
}
CoalPowerStation::CoalPowerStation(double stockStatus):
    maxCoalOnFeeder(new double),
    stockStatus(new double),
    efficiency(new double),
    numberOfEmployees(new int),
    isActive(new bool){
        *maxCoalOnFeeder = 0;
        *efficiency = 1;
        *numberOfEmployees = 0;
        *isActive = true;
        *(this->stockStatus) = stockStatus;
        reset();
    }
void CoalPowerStation::setMaxCoalOnFeeder(double amount){
    start();
    if(maxCoalOnFeeder == nullptr){
        maxCoalOnFeeder = new double;
        *maxCoalOnFeeder = 0;
    }
    if (amount <= 0) return; //miejsce na exception
    if (*maxCoalOnFeeder == 0) *maxCoalOnFeeder = amount;
    //miejsce na exception
    log("Wywołano setMaxCoalOnFeeder\n");
    stop();
    }
void CoalPowerStation::setEfficiency(double efficiency){
    start();
    if(this->efficiency == nullptr){
        this->efficiency = new double;
        *(this->efficiency) = 1;
    }
    if (efficiency > 1 || efficiency <= 0) return; //Exception
    *(this->efficiency) = efficiency;
    log("Wywołano setEfficiency\n");
    stop();
}
void CoalPowerStation::setIsActive(bool isActive){
    start();
    if(this->isActive == nullptr){
        this->isActive = new bool;
        *(this->isActive) = true;
    }
    *(this->isActive) = isActive;
    stop();
    log("Wywołano setIsActive\n");
}
    //%%%%%%%%
double CoalPowerStation::getMaxCoalOnFeeder(){
     if (maxCoalOnFeeder == nullptr) return 0;
    return *maxCoalOnFeeder;
}
double CoalPowerStation::getStockStatus(){
     if (stockStatus == nullptr) return 0;
    return *stockStatus;
}
double CoalPowerStation::getEfficiency(){
     if (efficiency == nullptr) return 0.0;
    return *efficiency;
}
int CoalPowerStation::getNumberOfEmployees(){
    if (numberOfEmployees == nullptr) return 0;
    return *numberOfEmployees;
}
bool CoalPowerStation::getIsActive(){
    if (isActive == nullptr) return false;
    return *isActive;
}
//voidy czy booleany?
//%%%%%%%%
void CoalPowerStation::addToStock(int amount){
    start();
    if(stockStatus == nullptr) return;
    if (amount <= 0) return; //miejsce na exception
    *stockStatus += amount;
    stop();
    log("Wywołano addToStock\n");
}
void CoalPowerStation::hireEmployees(int amount){
    start();
    if (amount <= 0) return;// false; //miejsce na exception
    if(numberOfEmployees == nullptr){
        numberOfEmployees = new int;
        *numberOfEmployees = 0;
    }
    *numberOfEmployees += amount;
    stop();
    log("Wywołano hireEmployees\n");
    //return true;
}
void CoalPowerStation::fireEmployees(int amount){
    start();
    if(numberOfEmployees == nullptr) return;
    if (amount <= 0) return; //miejsce na exception
    if (amount >= *numberOfEmployees) return; //tez exception
    *numberOfEmployees -= amount;
    stop();
    log("Wywołano fireEmployees\n");
    //return true;  
}
//sprawdzic czy da sie wszystko zrobic!!!
void CoalPowerStation::takeMaxFeederFromStock(){
    start();
    if(stockStatus == nullptr || maxCoalOnFeeder == nullptr) return;
    if (*stockStatus < *maxCoalOnFeeder) return; // miesjce na exception
    *stockStatus -= *maxCoalOnFeeder;
    //return true;
    stop();
    log("Wywołano takeMaxFeederFromStock\n");
}