#ifndef SE_HPP
#define SE_HPP
#include <exception>
class StackException: public std::exception{
    public:
        StackException(){};
        virtual const char* what() const noexcept override{
            return "Bledna_operacja_na_stosie!";
        }
};
#endif //SE_HPP