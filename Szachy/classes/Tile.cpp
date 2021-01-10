#include "Tile.hpp"
#include "GameWindow.hpp"
    
Tile::Tile(){
    width = nullptr;
    height = nullptr;
    font = nullptr;
    text = nullptr;
    color = nullptr;
    id = nullptr;
    x = nullptr;
    y = nullptr;
}
Tile::Tile(int x_, int y_, std::string s_, sf::Color c_, int w_,
int h_, sf::Font* f_, int id_, int px_, int py_){
    locked = new bool(false);
    width = new int(w_);
    height = new int(h_);
    font = f_;
    text = new std::string(s_);
    color = new sf::Color(c_);
    id = new int(id_);
    x = new int(x_);
    y = new int(y_);
    firstMove = new bool(true);
    posX = new int(px_);
    posY = new int(py_);
}
bool Tile::isLocked(){
    if (locked != nullptr) return *locked;
    else return false;
}
bool Tile::isFirst(){
    return *firstMove;
}
int Tile::getX(){
    return *posX;
}
int Tile::getY(){
    return *posY;
}
void Tile::move(Tile* x){
    *firstMove = false;
    int *temp;
    temp = this->posX;
    this->posX = x->posX;
    x->posX= temp;
    temp = this->posY;
    this->posY = x->posY;
    x->posY= temp;
    
    temp = this->x; 
    this->x = x->x;
    x->x = temp;
   
    temp = this->y; 
    this->y = x->y;
    x->y = temp;

    temp = this->width;
    this->width = x->width;
    x->width = temp;

}
void Tile::lock(){
    *locked = true;
}
void Tile::unlock(){
    *locked = false;
}
int Tile::getId(){
    return *id;
}
void Tile::setId(int i_){
    *id = i_;
}
Tile::~Tile(){
    if(locked != nullptr) delete locked;
    if(firstMove != nullptr) delete firstMove;
    if(posX != nullptr) delete posX;
    if(posY != nullptr) delete posY;
}