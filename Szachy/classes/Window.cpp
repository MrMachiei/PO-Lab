#include "dir/Window.hpp"
#include <fstream>
void Window::setSize(int w_, int h_){
    setWidth(w_);
    setHeight(h_);
}
void Window::setFont(std::string font_){
    font->loadFromFile(font_);
}
void Window::setLanguage(std::string lang){
    *(this->language) = lang;
}
void Window::setTilesSet(std::string tileSet_){
    *(this->tileSet) = tileSet_;
}
void Window::setWidth(int w_){
     if(width != nullptr){
        *width = w_;
    }
}
void Window::setHeight(int h_){
    if(height != nullptr){
        *height = h_;
    }
}
void Window::loadData(){
    std::fstream f;
    f.open("../resources/sett.txt", std::ios::in);
    f >> *language;
    f >> *tileSet;
    f >> *musicSet;
    f >> *fontName;
    f >> *width;
    f.close();
}
void Window::saveData(){
    std::fstream f;
    f.open("../resources/sett.txt", std::ios::out);
    f << *language << std::endl;
    f << *tileSet<< std::endl;
    f << *musicSet<< std::endl;
    f << *fontName<< std::endl;
    f << *width;
    f.close();
}
void Window::setMusic(std::string music_){
    music->openFromFile(music_);
}
void Window::drawButtons(){
    if(buttons == nullptr) return;
    for(auto it = buttons->begin(); it < buttons->end(); it++){
        (*it)->set();
        draw(**it);
    }
}
Window::~Window(){
    if(buttons != nullptr){
        for(auto it = buttons->begin(); it < buttons->end(); it++) delete *it;
        buttons->clear();
        delete buttons;
    }
    if(textes != nullptr){
        for(auto it = textes->begin(); it < textes->end(); it++) delete *it;
        textes->clear();
        delete textes;
    }
    if(font != nullptr){
        delete font;
    }
    if(width != nullptr){
        delete width;
    }
    if(height != nullptr){
        delete height;
    }
    if(music!= nullptr){
        music->stop();
        delete music;
    }
    if(eff != nullptr){
        eff->stop();
        delete eff;
    }
    if(language != nullptr){
        delete language;
    }
    if(tileSet != nullptr){
        delete tileSet;
    }
     if(fontName != nullptr){
        delete fontName;
    }
     if(musicSet != nullptr){
        delete musicSet;
    }
}
    sf::Font* Window::getFont(){
        return this->font;
    }