#ifndef SEE_HPP
#define SEE_HPP
#include "StackException.hpp"
#include <iostream>
class StackEmptyException: public StackException{
    private:
        std::string message;
    public:
        StackEmptyException(){};
        StackEmptyException(std::string p): message(p){}
        virtual const char* what() const noexcept override{
            return message.c_str();
        }
};
#endif //SEE_HPP