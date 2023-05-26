/**
 * @file main.cpp
 * @brief Driver file
 * 
 * @author Willow Ciesialka
 * @date 2023-05-25
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#define IMAGE_PATH "./peppers.jpg"
#define VIEW_WIDTH 800
#define VIEW_HEIGHT 600
#define WINDOW_TITLE "Graphics Demo"

int main(){
    sf::VideoMode vm(VIEW_WIDTH, VIEW_HEIGHT);
    sf::RenderWindow window(vm, WINDOW_TITLE);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}