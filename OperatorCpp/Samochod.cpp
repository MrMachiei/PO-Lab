#include "Samochod.hpp"

Samochod::Samochod() :pojemnoscBaku(0), poziomPaliwa(0), liczbaKilometrow(0),
        model(""){}
Samochod::Samochod(float bak, std::string model): pojemnoscBaku(bak), poziomPaliwa(0),
        liczbaKilometrow(0), model(model){}
Samochod::Samochod(const Samochod &p): pojemnoscBaku(p.pojemnoscBaku), poziomPaliwa(p.poziomPaliwa),
    liczbaKilometrow(p.liczbaKilometrow), model(p.model){}
float Samochod::odczytajPojemnoscBaku() const{
    return this->pojemnoscBaku;
}
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
bool cmp::operator() (const Samochod &a, const Samochod &b) const{
    return a.odczytajPojemnoscBaku() < b.odczytajPojemnoscBaku();
}
Samochod& Samochod::operator ++ (){
    ++(this->liczbaKilometrow);
    return *this;
}
Samochod Samochod::operator ++ (int){
    Samochod tmp(*this);
    ++(*this);
    return tmp;
}
Samochod& Samochod::operator,(Samochod A){
    this->liczbaKilometrow += A.liczbaKilometrow;
    return *this;
}
Samochod& Samochod::operator|=(Samochod A){
    this->liczbaKilometrow |= A.liczbaKilometrow;
    return *this;
}