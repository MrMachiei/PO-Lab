#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "Osoba.hpp"
#include <set>

class Pracownik: public Osoba{
    private:
        std::set <std::string> *listaPrzedmiotow;
    public:
        Pracownik();
        Pracownik(std::string imieNazwisko);
        Pracownik(const Pracownik &A);
        Pracownik(Pracownik &&A);
        ~Pracownik();
        void dodajPrzedmiot(std::string przedmiot);
        void usunPrzedmiot(std::string przedmiot);
        bool czyProwadzi(std::string przedmiot);
        void przedstaw();
};
#endif //PRACOWNIK_H