#ifndef OSOBA_H
#define OSOBA_H

#include "Adres.hpp"

class Osoba{
    protected:
        std::string imieNazwisko;
        std::string dataUrodzenia;
        Adres adresZamieszkania;
    public:
        void setImieNazwisko(std::string imieNazwisko);
        void setDataUrodzenia(std::string dataUrodzenia);
        std::string getImieNazwisko();
        std::string getDataUrodzenia();
};
#endif //OSOBA_H