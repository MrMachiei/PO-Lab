#ifndef ADRES_H
#define ADRES_H
#include <iostream>

class Adres{
    private:
        std::string ulica;
        int numerDomu;
        int kodPocztowy;
        int numerLokalu;
        std::string miasto;
    public:
        Adres();
        Adres(std::string ulica, int numerDomu, int numedLokalu, int kodPocztowy, std::string miasto);
        Adres(std::string ulica, int numerDomu, int kodPocztowy, std::string miasto);
        Adres(const Adres &A);
        ~Adres();
        void wypisz();
};
#endif //ADRES_H