#include "Adres.hpp"

Adres::Adres(): ulica(nullptr), numerDomu(nullptr), numerLokalu(nullptr), kodPocztowy(nullptr), miasto(nullptr){}

Adres::Adres(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto): ulica(new std::string(ulica)),
numerDomu(new int(numerDomu)), numerLokalu(new int(numerLokalu)), kodPocztowy(new int(kodPocztowy)), miasto(new std::string(miasto)){}

Adres::Adres(Adres &&A): ulica(A.ulica),numerDomu(A.numerDomu),
numerLokalu(A.numerLokalu), kodPocztowy(A.kodPocztowy), miasto(A.miasto){
    A.ulica = nullptr;
    A.numerDomu = nullptr;
    A.numerLokalu = nullptr;
    A.kodPocztowy = nullptr;
    A.miasto = nullptr;
}

Adres::Adres(const Adres &A): ulica(new std::string(*(A.ulica))),numerDomu(new int(*(A.numerDomu))),
numerLokalu(new int(*(A.numerLokalu))), kodPocztowy(new int(*(A.kodPocztowy))), miasto(new std::string(*(A.miasto))){
}

Adres& Adres::operator= (Adres&& A){
    if( this != &A){
        delete this->ulica;
        delete this->kodPocztowy;
        delete this->miasto;
        delete this->numerDomu;
        delete this->numerLokalu;
        this->ulica = A.ulica;
        this->numerDomu = A.numerDomu;
        this->numerLokalu = A.numerLokalu;
        this->kodPocztowy = A.kodPocztowy;
        this->miasto = A.miasto;
        A.ulica = nullptr;
        A.numerDomu = nullptr;
        A.numerLokalu = nullptr;
        A.kodPocztowy = nullptr;
        A.miasto = nullptr;
    }
    return *this;
}

Adres::~Adres(){
    delete ulica;
    delete numerDomu;
    delete numerLokalu;
    delete kodPocztowy;
    delete miasto;
}

void Adres::wypisz(){
    std::cout << *ulica << " " << *numerDomu;
    std::cout << " m." << *numerLokalu << std::endl;
    std::cout << *kodPocztowy << " " << *miasto << std::endl;
}