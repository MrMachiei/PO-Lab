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
    CoalPowerStation example(10000);
    example.setMaxCoalOnFeeder(1000);
    example.setEfficiency(0.87);
    example.setIsActive(true);
    example.hireEmployees(10);
    example.takeMaxFeederFromStock();
    std::cout << example.getStockStatus();
    bar(std::move(example));
    example.log("Jestem"); // Nie mozna było - standadowe dziedzicienie to dziedziczenie prywatne - wszystko staje sie private, czyli nasza metoda public stala sie private
    example.writeTime();
    return 0;
}