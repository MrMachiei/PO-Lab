#ifndef STUDENT_H
#define STUDENT_H

#include "Osoba.hpp"
#include <vector>
#include <map>

class Student: public Osoba{
    private:
        std::map<std::string, int> *listaOcen;
    public:
        Student();
        Student(std::string imieNazwisko);
        Student(const Student &A);
        Student(Student &&A);
        ~Student();
        void setOcena(std::string przedmiot, int ocena);
        int getOcena(std::string przedmiot);
        std::map<std::string, int> getListaOcen();
        void przedstaw();
};
#endif //STUDENT_H