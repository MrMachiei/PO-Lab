#ifndef T_HPP
#define T_HPP
#include "Button.hpp"

class Tile: public Button{
    private:
        int *posX, *posY;
        bool *locked;
        bool *firstMove;
    public:
        Tile();//: text(nullptr), color(nullptr), x(nullptr), y(nullptr){};
        Tile(int, int, std::string, sf::Color, int, int, sf::Font*, int, int, int);
        void press();// override;
        void lock();
        int getId();
        void unlock(); // locks and unlocks to move
        bool isLocked();
        bool isFirst();
        void move(Tile*);
        int getX();
        int getY();
        void setId(int);
        ~Tile();
};

#endif //T_HPP