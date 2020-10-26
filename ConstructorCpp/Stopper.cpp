#include "Stopper.hpp"
Stopper::Stopper(): time(0){
}
void Stopper::reset(){
    time = 0;
}
double Stopper::getTime(){
    return time;
}
void Stopper::start(){
    startTime = clock();
}
void Stopper::stop(){
    stopTime = clock();
    time += (double)(stopTime-startTime)/CLOCKS_PER_SEC;
}
void Stopper::writeTime(){
    std::cout << getTime();
}
