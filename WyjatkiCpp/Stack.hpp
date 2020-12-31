#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
//noexcept - nie rzuca wyjatkow
//override - kompilator sprawdza czy rzeczywiscie nadpisujemy metode, identycznie jak w przypadku javy
//w c++ zgloszony moze byc dowolny wyjatek bez zaznaczenia jaki
class Stack{
    private:
        int maxStackSize;
        std::vector<int> dfs;
        int top;
    public:
        Stack();
        Stack(int max);
        void push(int newItem);
        int pop();
};

#endif //STACK_HPP

