#ifndef FABRYKAPR_H
#define FABRYKAPR_H

#include "Pracownik.hpp"
#include "FabrykaOsob.hpp"

class FabrykaPracownikow: public FabrykaOsob{
    public:
        Pracownik* utworz();
};

#endif //FABRYKAPR_H