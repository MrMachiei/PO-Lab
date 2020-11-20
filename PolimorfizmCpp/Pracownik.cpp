#include "Pracownik.hpp"

Pracownik::Pracownik(): Osoba(), listaPrzedmiotow(nullptr){}

Pracownik::Pracownik(std::string imieNazwisko):Osoba(imieNazwisko), listaPrzedmiotow(nullptr){}

Pracownik::Pracownik(const Pracownik &A): Osoba(A), listaPrzedmiotow(new std::set<std::string>(*(A.listaPrzedmiotow))){}

Pracownik::Pracownik(Pracownik &&A): Osoba(A), listaPrzedmiotow(nullptr){
    listaPrzedmiotow = A.listaPrzedmiotow;
    A.listaPrzedmiotow = nullptr; 
}

Pracownik::~Pracownik(){
    if(listaPrzedmiotow != nullptr){
        listaPrzedmiotow->clear();
    }
    delete listaPrzedmiotow;
}

void Pracownik::dodajPrzedmiot(std::string przedmiot){
    if (listaPrzedmiotow == nullptr) listaPrzedmiotow = new std::set<std::string>;
    auto it = listaPrzedmiotow->find(przedmiot);
    if (it == listaPrzedmiotow->end()) listaPrzedmiotow->insert(przedmiot);
}

void Pracownik::usunPrzedmiot(std::string przedmiot){
    if (listaPrzedmiotow == nullptr) return;
    auto it = listaPrzedmiotow->find(przedmiot);
    if (it == listaPrzedmiotow->end()) return;
    listaPrzedmiotow->erase(it);
}

bool Pracownik::czyProwadzi(std::string przedmiot){
    if (listaPrzedmiotow == nullptr) return false;
    if (listaPrzedmiotow->find(przedmiot) == listaPrzedmiotow->end()) return false;
    return true;
}

void Pracownik::przedstaw(){
    if( imieNazwisko != nullptr) std::cout << *imieNazwisko << std::endl;
    if( dataUrodzenia != nullptr) std::cout << "Urodzony(a): " << *dataUrodzenia << std::endl;
    if( adresZamieszkania != nullptr) adresZamieszkania->wypisz();
    std::cout << "Uczy: " << std::endl;
    if( listaPrzedmiotow != nullptr ){
        for(auto it = listaPrzedmiotow->begin(); it != listaPrzedmiotow->end(); it++){
            std::cout << *it << std::endl;
        }
    }
}