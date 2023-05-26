/**
 * @file main.cpp
 * @brief Driver file
 * 
 * @author Willow Ciesialka
 * @date 2023-05-25
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "helvetica.hpp"
#include "peppers.hpp"

#define VIEW_WIDTH 800
#define VIEW_HEIGHT 600
#define WINDOW_TITLE "Graphics Demo"
#define BG_COLOR 0x825f87ff

/**
 * @brief Function responsible for rendering text onto the window.
 * 
 * @param[in] window Window to render text onto.
 * @return Success status.
*/
bool render_text(sf::RenderWindow& window){
    sf::Font font;
    if(!font.loadFromMemory(helvetica_standard_ttf, helvetica_standard_ttf_len)){
        return false;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Hello, world!");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(300, 400);

    window.draw(text);
    return true;
}

/**
 * @brief Function responsible for rendering image onto the window.
 * 
 * @param[in] window Window to render image on.
 * @return Success status.
*/
bool render_image(sf::RenderWindow& window){
    sf::Texture peppers_texture;
    if(!peppers_texture.loadFromMemory(peppers_jpg, peppers_jpg_len)){
        return false;
    }
    sf::Sprite peppers;
    peppers.setTexture(peppers_texture);
    peppers.setPosition(275, 50);

    window.draw(peppers);
    return true;
}

/**
 * @brief Main function responsible for rendering the window.
*/
int main(){
    sf::VideoMode vm(VIEW_WIDTH, VIEW_HEIGHT);
    sf::RenderWindow window(vm, WINDOW_TITLE);
    const sf::Color bg_color(BG_COLOR);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(bg_color);

        // Render text
        render_text(window);

        // Render image
        render_image(window);

        window.display();
    }

    return 0;
}