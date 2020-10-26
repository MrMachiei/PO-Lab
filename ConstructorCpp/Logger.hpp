#include "Stopper.hpp"
class Logger{
private:
    bool debug;
public:
    void log(std::string t);
    Logger();
    Logger(bool debug); // problem - konsturkotry klasy dziedzicaczej musza inicjalizowac klase glowna, a brakuje konstrukora domyslnego
};