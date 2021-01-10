#ifndef WIN_HPP
#define WIN_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <vector>
#include "Button.hpp"
#include <fstream>

class Window: public sf::RenderWindow{
    protected:
        std::vector <Button*> *buttons;
        std::vector <sf::Text* > *textes;
        sf::Font *font;
        int *width;
        int *height;
        sf::Music *music;
        sf::Music *eff;
        std::string *language;
        std::string *tileSet;
        std::string *musicSet;
        std::string *fontName;
        void setSize(int, int);
        void setFont(std::string);
        void setLanguage(std::string);
        void setTilesSet(std::string);
        void setWidth(int);
        void setHeight(int);
        void setMusic(std::string);
    public:
        //Window(); // abstrac class does not need a constructor
        //sf::Window *window;
        //void virtual close() = 0 override;
        sf::Font* getFont();
        void loadData();
        void saveData();
        void virtual show() = 0;
        void virtual makeButtons() = 0;
        void drawButtons();
        virtual ~Window();
};

#endif // WIN_HPP