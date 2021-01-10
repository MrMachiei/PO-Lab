#ifndef GW_HPP
#define GW_HPP
#include <iostream>
#include <fstream>
#include <map>
#include "Tile.hpp"
#include "Window.hpp"
#include "Player.hpp"

class GameWindow: public Window{
    private:
        Tile*** boardButtons;
        Button*** board;
        Button* boardBg;
        std::vector <Button* > *menu;
        std::vector <Button* > *top;
        std::vector <sf::Text* > *menuT;
        std::vector <sf::Text* > *topT;
        Tile* selectedTile;
        sf::Text** tHelp;
        sf::Texture **textures;
        sf::Music* win;
        Player **players;
        bool *started;
        bool *paused;
        bool *end;
        int *turn;
        bool *makingMove;
        bool *setMenu;
        bool *topMenu;
        
    public:
        GameWindow();
        //GameWindow(int, int);
        void updateData();
        void unPause();
        void move(Tile* , Tile* );
        void start();
        void pause();
        void nextTurn();
        void lockTiles();
        void updatePoints(std::string);
        int checkPress(sf::Vector2f);
        void makeMenu();
        void reset();
        void makeLeader();
        void updateTiles(Tile*);
        void loadTextures();
        void makeBoard();
        bool checkMouse(sf::Vector2f , Button *);
        void makeTiles();
        void drawBoard();
        void makeButtons();
        void drawButtons(sf::Vector2f);
        void calculateOffsetAndSize(int&, int&, int&);
        void drawTiles(sf::Vector2f);
        bool isRunning();
        bool isPaused();
        void addToName(std::string);
        //void close();
        void show();
        ~GameWindow();
};

#endif //GW_HPP