#ifndef FABRYKAST_H
#define FABRYKAST_H

#include "Student.hpp"
#include "FabrykaOsob.hpp"

class FabrykaStudentow: public FabrykaOsob{
    public:
        Student* utworz();
};

#endif //FABRYKAST_H