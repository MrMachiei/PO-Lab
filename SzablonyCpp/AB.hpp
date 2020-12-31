#ifndef AB_HPP
#define AB_HPP
#include <iostream>
template<typename T>
class A{
    typename T::id i;
    public:
    void f(){
        i.g();
    }
    
};
class B{
    public:
        class id{
            public:
                void g(){};
        };
};
#endif //AB_HPP