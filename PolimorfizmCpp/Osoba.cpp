#include "Osoba.hpp"

Osoba::Osoba(): imieNazwisko(nullptr), dataUrodzenia(nullptr), adresZamieszkania(nullptr){}

Osoba::Osoba(std::string imieNazwisko): imieNazwisko(new std::string), dataUrodzenia(nullptr), adresZamieszkania(nullptr){
    *(this->imieNazwisko) = imieNazwisko;
}

Osoba::Osoba(Osoba const &A): imieNazwisko(new std::string(*(A.imieNazwisko))), dataUrodzenia(new std::string(*(A.dataUrodzenia))),
adresZamieszkania(new Adres(*(A.adresZamieszkania))){}

Osoba::Osoba(Osoba &&A): imieNazwisko(nullptr), dataUrodzenia(nullptr),
adresZamieszkania(nullptr){
    imieNazwisko = (A.imieNazwisko);
    dataUrodzenia = (A.dataUrodzenia);
    adresZamieszkania = A.adresZamieszkania;
    A.imieNazwisko = nullptr;
    A.dataUrodzenia = nullptr;
    A.adresZamieszkania = nullptr;
}

Osoba& Osoba::operator= (Osoba &&A){
    if( this != &A){
        delete imieNazwisko;
        delete dataUrodzenia;
        delete adresZamieszkania;

        imieNazwisko = A.imieNazwisko;
        dataUrodzenia = A.dataUrodzenia;
        adresZamieszkania = A.adresZamieszkania;
        A.imieNazwisko = nullptr;
        A.dataUrodzenia = nullptr;
        A.adresZamieszkania = nullptr;
    }
    return *this;
}

void Osoba::setImieNazwisko(std::string imieNazwisko){ 
    if(this->imieNazwisko == nullptr) this->imieNazwisko = new std::string;
    *(this->imieNazwisko) = imieNazwisko;
    }

void Osoba::setDataUrodzenia(std::string dataUrodzenia){
    if(this->dataUrodzenia == nullptr) this->dataUrodzenia = new std::string;
    int dzien = std::stoi(dataUrodzenia.substr(0,2));
    int miesiac = std::stoi(dataUrodzenia.substr(3,2));
    int rok = std::stoi(dataUrodzenia.substr(6,4));
    if( dzien <= 31 && dzien >= 1 && miesiac >= 1 && miesiac <= 12 && rok > 0) *(this->dataUrodzenia) = dataUrodzenia;
}

void Osoba::setAdresZamieszkania(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto){
    if( this->adresZamieszkania == nullptr ) adresZamieszkania = new Adres;
    if(ulica != "" && numerDomu > 0 && kodPocztowy > 0 && miasto != "" && numerLokalu > 0) 
    *adresZamieszkania = std::move(Adres(ulica, numerDomu, numerLokalu, kodPocztowy, miasto));
}

std::string Osoba::getImieNazwisko(){return *imieNazwisko;}

std::string Osoba::getDataUrodzenia(){return *dataUrodzenia;}

Adres Osoba::getAdresZamieszkania(){return *adresZamieszkania;}

void Osoba::przedstaw(){
    if( !(imieNazwisko == nullptr)) std::cout << *imieNazwisko << std::endl;
    if( !(dataUrodzenia == nullptr)) std::cout << "Urodzony(a): " << *dataUrodzenia << std::endl;
    if( !(adresZamieszkania == nullptr)) adresZamieszkania->wypisz();
}
Osoba::~Osoba(){
    if (imieNazwisko != nullptr) delete imieNazwisko;
    if (dataUrodzenia != nullptr) delete dataUrodzenia;
    if (adresZamieszkania != nullptr) delete adresZamieszkania;
}