#include "Samochod.hpp"

int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
    if(s1){
        std::cout << "S1\n";
    }
    if(!s1){
        std::cout << "!S1\n";
    }
    if(s2){
        std::cout << "S2\n";
    }
    if(!s2){
        std::cout << "!S2\n";
    }
    if(s3){
        std::cout << "S3\n";
    }
    if(!s3){
        std::cout << "!S3\n";
    }
}