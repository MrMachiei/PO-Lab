#ifndef OSOBA_H
#define OSOBA_H

#include "Adres.hpp"

class Osoba{
    protected:
        std::string* imieNazwisko;
        std::string* dataUrodzenia;
        Adres* adresZamieszkania;
    public:
        Osoba();
        Osoba(std::string imieNazwisko);
        void setImieNazwisko(std::string imieNazwisko);
        void setDataUrodzenia(std::string dataUrodzenia);
        void setAdresZamieszkania(std::string ulica, int numerDomu, int kodPocztowy, std::string miasto);
        void setAdresZamieszkania(std::string ulica, int numerDomu, int numerLokalu,int kodPocztowy, std::string miasto);
        std::string getImieNazwisko();
        std::string getDataUrodzenia();
        Adres getAdresZamieszkania();
        ~Osoba();
        void przedstaw();
};
#endif //OSOBA_H