#include "Osoba.hpp"

Osoba::Osoba():imieNazwisko(""), dataUrodzenia(""), adresZamieszkania(){};

Osoba::Osoba(std::string imieNazwisko, std::string dataUrodzenia, Adres adresZamieszkania): imieNazwisko(imieNazwisko),
dataUrodzenia(dataUrodzenia), adresZamieszkania(adresZamieszkania){}

void Osoba::setImieNazwisko(std::string imieNazwisko){ this->imieNazwisko = imieNazwisko;}

void Osoba::setDataUrodzenia(std::string dataUrodzenia){
    int dzien = std::stoi(dataUrodzenia.substr(0,2));
    int miesiac = std::stoi(dataUrodzenia.substr(3,2));
    int rok = std::stoi(dataUrodzenia.substr(6,4));
    if( dzien <= 31 && dzien >= 1 && miesiac >= 1 && miesiac <= 12 && rok > 0) this->dataUrodzenia = dataUrodzenia;
}

void Osoba::setAdresZamieszkania(std::string ulica, int numerDomu, int kodPocztowy, std::string miasto){
    if(ulica != "" && numerDomu > 0 && kodPocztowy > 0 && miasto != "") 
    adresZamieszkania = std::move(Adres(ulica, numerDomu, kodPocztowy, miasto));
}

void Osoba::setAdresZamieszkania(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto){
    if(ulica != "" && numerDomu > 0 && kodPocztowy > 0 && miasto != "" && numerLokalu > 0) 
    adresZamieszkania = std::move(Adres(ulica, numerDomu, numerLokalu, kodPocztowy, miasto));
}

std::string Osoba::getImieNazwisko(){return imieNazwisko;}

std::string Osoba::getDataUrodzenia(){return dataUrodzenia;}

Adres Osoba::getAdresZamieszkania(){return adresZamieszkania;}

void Osoba::przedstaw(){
    std::cout << imieNazwisko << std::endl;
    std::cout << "Urodzony(a): " << dataUrodzenia << std::endl;
    adresZamieszkania.wypisz();
}
Osoba::~Osoba(){}