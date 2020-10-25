#include <iostream>

class CoalPowerStation{
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
    ~CoalPowerStation();
};