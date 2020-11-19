#include "Adres.hpp"

Adres::Adres(){}
Adres::Adres(std::string ulica, int numerDomu, int numerLokalu, int kodPocztowy, std::string miasto): ulica(ulica),
numerDomu(numerDomu), numerLokalu(numerLokalu), kodPocztowy(kodPocztowy), miasto(miasto){}
Adres::Adres(std::string ulica, int numerDomu, int kodPocztowy, std::string miasto): ulica(ulica), numerDomu(numerDomu),
kodPocztowy(kodPocztowy), miasto(miasto){}
Adres::Adres(Adres &&A): ulica(A.ulica), numerDomu(A.numerDomu),
numerLokalu(A.numerLokalu), kodPocztowy(A.kodPocztowy), miasto(A.miasto){}
Adres::Adres(const Adres &A): ulica(A.ulica), numerDomu(A.numerDomu),
numerLokalu(A.numerLokalu), kodPocztowy(A.kodPocztowy), miasto(A.miasto){}
Adres::~Adres(){};