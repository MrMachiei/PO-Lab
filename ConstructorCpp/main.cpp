#include "CoalPowerStation.hpp"
void foo(CoalPowerStation a){
    std::cout << "Hello from foo!" << std::endl;
}
void bar(const CoalPowerStation &a){
    std::cout << "Hello from bar!" << std::endl;
}
void qux(const CoalPowerStation &&a){
    std::cout << "Hello from qux!" << std::endl;
}
int main(int argc, char* argv[]){
    CoalPowerStation example(100);
    //example.setMaxCoalOnFeeder(50);
    //example.setEfficiency(0.87);
    //example.setIsActive(true);
    //zrobic to samo co z emp
    example.hireEmployees(10);
    bar(std::move(example));
    return 0;
}