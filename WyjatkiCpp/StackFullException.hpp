#ifndef SFE_HPP
#define SFE_HPP
#include "StackException.hpp"
#include <iostream>
class StackFullException: public StackException{
    private:
        int element = 0;
        int maxStackSize = 0;
        std::string message;
    public:
        StackFullException(){};
        StackFullException(std::string p, int e, int s): message(p), element(e), maxStackSize(s){}
        virtual const char* what() const noexcept override{
            return ("Blad_Przepelnienia_Rozmiar:_" + std::to_string(maxStackSize) + "_Element:_" + std::to_string(element)).c_str();
        }
};

#endif //SFE_HPP