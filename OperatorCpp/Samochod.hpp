#include <iostream>

class Samochod{
private:
    float pojemnoscBaku;
    float poziomPaliwa;
    unsigned int liczbaKilometrow;
    std::string model;
public:
    Samochod();
    Samochod(float bak, std::string model);
    Samochod(const Samochod &p);
    float odczytajPojemnoscBaku() const;
    operator bool() const;
    bool operator !() const;
    friend std::ostream & operator << (std::ostream &os, const Samochod &samochod);
    // deklaracja przyjaźni -> operator << to element innej klasy, 
    // nawiazujemy przyjazn -> moga wzajemnie korzytsac ze swoich elementow
    bool operator < (const Samochod &samochod) const;
    Samochod& operator ++ ();
    Samochod operator ++ (int);
    //uzyte const aby nie mozna bylo zmienic wartosci elementow w wyniku dzialania

};
struct cmp{
    bool operator() (const Samochod &a, const Samochod &b) const;
};