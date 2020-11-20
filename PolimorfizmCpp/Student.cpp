#include "Student.hpp"

Student::Student(): Osoba(), listaOcen(nullptr){}

Student::Student(std::string imieNazwisko):Osoba(imieNazwisko), listaOcen(nullptr){}

Student::Student(const Student &A): Osoba(A), listaOcen(new std::map<std::string, int>(*(A.listaOcen))){}

Student::Student(Student &&A): Osoba(A), listaOcen(nullptr){
    listaOcen = A.listaOcen;
    A.listaOcen = nullptr; 
}

Student::~Student(){
    if(listaOcen != nullptr){
        listaOcen->clear();
    }
    delete listaOcen;
}

void Student::setOcena(std::string przedmiot, int ocena){
    if( listaOcen == nullptr ) listaOcen = new std::map<std::string, int>;
    if(ocena < 1 || ocena > 5) return;
    (*listaOcen)[przedmiot] = ocena;
}

int Student::getOcena(std::string przedmiot){
    if( listaOcen == nullptr ) return 0;
    auto it = listaOcen->find(przedmiot);
    if( it != listaOcen->end()) return it->second;
    return 0;
}

std::map<std::string, int> Student::getListaOcen(){
    if( listaOcen == nullptr ) new std::map<std::string, int>;
    return *listaOcen;
}

void Student::przedstaw(){
    if( imieNazwisko != nullptr) std::cout << *imieNazwisko << std::endl;
    if( dataUrodzenia != nullptr) std::cout << "Urodzony(a): " << *dataUrodzenia << std::endl;
    if( adresZamieszkania != nullptr) adresZamieszkania->wypisz();
    std::cout << "Oceny: " << std::endl;
    if( listaOcen != nullptr ){
        for(auto it = listaOcen->begin(); it != listaOcen->end(); it++){
            std::cout << it->first << ": " << it->second << std::endl;
        }
    }
}