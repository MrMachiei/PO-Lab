#ifndef PL_HPP
#define PL_HPP
#include <iostream>
#include <vector>
#include "Tile.hpp"
class Player{
    private:
        std::string *name;
    public:
        Player();
        Player(std::string);
        void makeMove(Tile*, Tile*);
        void setName(std::string);
        Player* surrender();
       ~Player();
};

#endif //PL_HPP