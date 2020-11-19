#include "Adres.hpp"

Adres::Adres(){}

Adres::Adres(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto): ulica(ulica),
numerDomu(numerDomu), numerLokalu(numerLokalu), kodPocztowy(kodPocztowy), miasto(miasto){}

Adres::Adres(std::string ulica, int numerDomu, int kodPocztowy, std::string miasto): ulica(ulica), numerDomu(numerDomu),
numerLokalu(0), kodPocztowy(kodPocztowy), miasto(miasto){}

Adres::Adres(const Adres &A): ulica(A.ulica), numerDomu(A.numerDomu),
numerLokalu(A.numerLokalu), kodPocztowy(A.kodPocztowy), miasto(A.miasto){}

Adres::~Adres(){};

void Adres::wypisz(){
    std::cout << ulica << " " << numerDomu;
    if(numerLokalu == 0) std::cout << std::endl;
    else std::cout << "m. " << numerLokalu << std::endl;
    std::cout << kodPocztowy << " " << miasto << std::endl;
}