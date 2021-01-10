#include "Tile.hpp"
#include "Player.hpp"

Player::Player(): name(nullptr){}
Player::Player(std::string n_): name(new std::string){
    setName(n_);
}
void Player::makeMove(Tile* t1, Tile* t2){
    t1->move(t2);
}
void Player::setName(std::string n_){
    *name = n_;
}
Player* Player::surrender(){
    return this;
}
Player::~Player(){
    if(name != nullptr) delete name;
}
