#ifndef B_HPP
#define B_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Button: public sf::RectangleShape{
    protected:
        int *width;
        int *height;
        sf::Font *font;
        std::string *text;
        sf::Color *color;
        int *id;
        int *x;
        int *y;
    public:
        Button();
        Button(int, int, std::string, sf::Color, int, int, sf::Font*, int);
        sf::Vector2f getSize();
        sf::Vector2f getPos();
        void press(float, float);
        void set();
        std::string getStr();
        int getId();
        virtual ~Button();
};

#endif //B_HPP