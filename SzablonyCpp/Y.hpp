#ifndef Y_HPP
#define Y_HPP
#include <iostream>
#include "X.hpp"
template<typename T, typename C = X<T>>
class Y{
    T zmienna;
    C klasaX;
};
#endif //Y_HPP