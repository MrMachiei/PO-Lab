#include "FabrykaPracownikow.hpp"

Pracownik* FabrykaPracownikow::utworz(){
    return new Pracownik();
}