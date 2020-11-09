#include "Samochod.hpp"

Samochod::Samochod() :pojemnoscBaku(0), poziomPaliwa(0), liczbaKilometrow(0),
        model(""){}
Samochod::Samochod(float bak, std::string model): pojemnoscBaku(bak), poziomPaliwa(0),
        liczbaKilometrow(0), model(model){}
Samochod::operator bool() const{
    if (model != "" && pojemnoscBaku > 0) return true;
    return false;
}
bool Samochod::operator !() const{
    if (model != "" && pojemnoscBaku > 0) return false;
    return true;
}
std::ostream & operator << (std::ostream &os, const Samochod &samochod){
 os << samochod.model  << " " << samochod.liczbaKilometrow << "\n";
 return os;
}
bool Samochod::operator < (const Samochod &samochod) const{
    return this->model < samochod.model;
}