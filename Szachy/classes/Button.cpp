#include "dir/Button.hpp"

    Button::Button(): width(nullptr), height(nullptr), font(nullptr),
    text(nullptr), color(nullptr), id(nullptr),x(nullptr), y(nullptr){
    }
    Button::Button(int x_, int y_, std::string s_, sf::Color c_, int w_,
    int h_, sf::Font* f_, int id_): width(new int(w_)), height(new int(h_)),
    font(f_), text(new std::string(s_)), color(new sf::Color(c_)),id(new int(id_)),  x(new int(x_)), y(new int(y_)){
    }
    void Button::press(float x, float y){}
    void Button::set(){
        setPosition(*x,*y);
        setSize(sf::Vector2f(*width,*height));
        setFillColor(*color);
    }
    std::string Button::getStr(){
        return *text;
    }
    int Button::getId(){
        return *id;
    }
    sf::Vector2f Button::getSize(){
        sf::Vector2f v;
        v.x = *width;
        v.y = *height;
        return v;
    }
    sf::Vector2f Button::getPos(){
        sf::Vector2f v;
        v.x = *x;
        v.y = *y;
        return v;
    }
    Button::~Button(){
        if( width != nullptr ) delete width;
        if( height != nullptr ) delete  height;
        if( text != nullptr ) delete text;
        if( id != nullptr ) delete id;
        if( id != nullptr) delete color;
        if( x != nullptr ) delete x;
        if( y != nullptr ) delete y;
    }