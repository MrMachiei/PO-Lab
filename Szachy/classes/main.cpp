#include "dir/GameWindow.hpp"
#include "dir/Button.hpp"

#include <unistd.h>

int main()
{
    GameWindow *window = new GameWindow();
    sf::Color *bg = new sf::Color(250,250,250);
    window->show();
    window->makeMenu();
    
    while (window->isOpen())
    {
        window->clear(*bg);
        
        sf::Event event;
        sf::Vector2f mp;
        mp.x = sf::Mouse::getPosition(*window).x;
        mp.y = sf::Mouse::getPosition(*window).y;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed){
                mp.x = sf::Mouse::getPosition(*window).x;
                mp.y = sf::Mouse::getPosition(*window).y;
                
                window->checkPress(mp);
                
            }
            if (event.type == sf::Event::TextEntered){
                window->addToName(std::string (1,event.text.unicode));
            }
        }

        if(window->isRunning()){
            window->drawBoard();
            window->drawTiles(mp);
            
        }
        window->drawButtons(mp);
        window->display();
    }
    delete window;
    delete bg;
    return 0;
}