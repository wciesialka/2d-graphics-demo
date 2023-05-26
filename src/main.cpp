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
    text.setString("Oh, boy! I sure do love my peppers!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setPosition(200, 550);

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
    peppers.setPosition(175, 25);

    window.draw(peppers);
    return true;
}

/**
 * @brief Function responsible for rendering shapes on window.
 * 
 * @param[in] window Window to render shapes on.
 * @return Success status.
*/
bool render_shapes(sf::RenderWindow& window){
    // Table
    const sf::Color table_color(0x55342bff); 

    sf::RectangleShape tabletop(sf::Vector2f(400, 40));
    tabletop.setFillColor(table_color);
    tabletop.setPosition(100, 300);

    sf::RectangleShape table_leg(sf::Vector2f(40, 300));
    table_leg.setFillColor(table_color);
    table_leg.setPosition(280, 300);

    window.draw(tabletop);
    window.draw(table_leg);

    // Chair
    sf::RectangleShape chair_seat(sf::Vector2f(200, 20));
    chair_seat.setFillColor(table_color);
    chair_seat.setPosition(500, 500);

    sf::RectangleShape chair_back(sf::Vector2f(20, 200));
    chair_back.setFillColor(table_color);
    chair_back.setPosition(680, 300);

    sf::RectangleShape left_chair_leg(sf::Vector2f(20, 100));
    left_chair_leg.setFillColor(table_color);
    left_chair_leg.setPosition(500, 500);

    sf::RectangleShape right_chair_leg(sf::Vector2f(20, 100));
    right_chair_leg.setFillColor(table_color);
    right_chair_leg.setPosition(680, 500);

    window.draw(chair_seat);
    window.draw(chair_back);
    window.draw(left_chair_leg);
    window.draw(right_chair_leg);

    // Figure
    sf::CircleShape head(50);
    head.setFillColor(sf::Color::White);
    head.setOutlineColor(sf::Color::Black);
    head.setOutlineThickness(5);
    head.setPosition(550, 50); 

    // We have to render each line individually or some get skipped during rendering - I'm not sure why this is.
    sf::Vertex body[2];
    body[0].position = sf::Vector2f(600, 150);
    body[0].color = sf::Color::Black;
    body[1].position = sf::Vector2f(600, 495);
    body[1].color = sf::Color::Black;

    sf::Vertex thighs[2];
    thighs[0].position = sf::Vector2f(600, 495);
    thighs[0].color = sf::Color::Black;
    thighs[1].position = sf::Vector2f(400, 495);
    thighs[1].color = sf::Color::Black;

    sf::Vertex calves[2];
    calves[0].position = sf::Vector2f(400, 495);
    calves[0].color = sf::Color::Black;
    calves[1].position = sf::Vector2f(375, 600);
    calves[1].color = sf::Color::Black;

    sf::Vertex arms[2];
    arms[0].position = sf::Vector2f(600, 250);
    arms[0].color = sf::Color::Black;
    arms[1].position = sf::Vector2f(280, 280);
    arms[1].color = sf::Color::Black;

    window.draw(head);
    window.draw(body, 2, sf::Lines);
    window.draw(thighs, 2, sf::Lines);
    window.draw(calves, 2, sf::Lines);
    window.draw(arms, 2, sf::Lines);

    // Plate
    sf::CircleShape plate(100);
    plate.setScale(1.5, 0.25);
    plate.setFillColor(sf::Color(0xC0C0C0ff));
    plate.setPosition(150, 275);

    window.draw(plate);

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

        // Render shapes
        render_shapes(window);

        // Render text
        render_text(window);

        // Render image
        render_image(window);

        window.display();
    }

    return 0;
}