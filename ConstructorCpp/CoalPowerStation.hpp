#include "Logger.hpp"

class CoalPowerStation: public Logger{
    private:
    double *maxCoalOnFeeder;
    double *stockStatus;
    double *efficiency;
    int *numberOfEmployees;
    bool *isActive;

    public:
    CoalPowerStation();
    CoalPowerStation(const CoalPowerStation &A);
    CoalPowerStation(CoalPowerStation &&A);
    CoalPowerStation(double stockStatus);
    ~CoalPowerStation();
    void setMaxCoalOnFeeder(double amount);
    void setEfficiency(double efficiency);
    void setIsActive(bool isActive);
    double getMaxCoalOnFeeder();
    double getStockStatus();
    double getEfficiency();
    int getNumberOfEmployees();
    bool getIsActive();
    void addToStock(int amount);
    void hireEmployees(int amount);
    void fireEmployees(int amount);
    void takeMaxFeederFromStock();
};