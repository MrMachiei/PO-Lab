#include "Osoba.hpp"

void Osoba::setImieNazwisko(std::string imieNazwisko){ this->imieNazwisko = imieNazwisko;}
void Osoba::setDataUrodzenia(std::string dataUrodzenia){
    int dzien = std::stoi(dataUrodzenia.substr(0,2));
    int miesiac = std::stoi(dataUrodzenia.substr(3,2));
    int rok = std::stoi(dataUrodzenia.substr(6,4));
    if( dzien <= 31 && dzien >= 1 && miesiac >= 1 && dzien <= 12 && rok > 0) this->dataUrodzenia = dataUrodzenia;
}
std::string Osoba::getImieNazwisko(){return imieNazwisko;}
std::string Osoba::getDataUrodzenia(){return dataUrodzenia;}