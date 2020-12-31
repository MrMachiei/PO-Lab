#ifndef X_HPP
#define X_HPP
#include <iostream>
template <typename T>
class X{
    private:
        T x;
    public:
        X(){};
        X(T _x){
            this->x = _x;
        }
        T getX() const{
            return this->x;
        }
        friend std::ostream& operator << (std::ostream& os, X const& x){
            os << x.x;
            return os;
        }
};

template <typename T> 
bool operator > (X<T> const& a, X<T> const& b){
    return a.getX() > b.getX();
}

template <>
bool operator > (X<std::string> const& a, X<std::string> const& b){
    return a.getX().size() > b.getX().size();
}
#endif //X_HPP