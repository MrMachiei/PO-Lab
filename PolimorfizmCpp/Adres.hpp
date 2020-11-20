#ifndef ADRES_H
#define ADRES_H
#include <iostream>

class Adres{
    private:
        std::string* ulica;
        int* numerDomu;
        int* kodPocztowy;
        int* numerLokalu;
        std::string* miasto;
    public:
        Adres();
        Adres(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto);
        Adres(const Adres &A);
        Adres(Adres &&A);
        Adres& operator= (Adres&& A);
        ~Adres();
        void wypisz();
};
#endif //ADRES_H