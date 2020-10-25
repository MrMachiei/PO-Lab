#include "CoalPowerStation.hpp"
void foo(CoalPowerStation a){
    std::cout << "Hello from foo!" << std::endl;
}
int main(int argc, char* argv[]){
    CoalPowerStation example(100);
    example.setMaxCoalOnFeeder(50);
    example.setEfficiency(0.87);
    example.setIsActive(true);
    example.hireEmployees(10);
    foo(example);
    return 0;
}