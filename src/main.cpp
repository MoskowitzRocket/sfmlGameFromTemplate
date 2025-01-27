#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include "../headers/Game.h"
#include "../headers/Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
    //window.setFramerateLimit(60);

    Game bat(800/2, 600-30);
    Ball ball(800/2, 0);
    sf::Clock clock;
    int scores = 0;
    int lives = 3;

    sf::Font font("../../assets/fonts/ExtraBeige.ttf");
    sf::Text hud(font);

    while(window.isOpen()){

        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }

            if(const auto keyPressed = event->getIf<sf::Event::KeyPressed>()){
                bat.HandleMovement(keyPressed->scancode, true);
            } 
            else if (const auto keyReleased = event->getIf<sf::Event::KeyReleased>()){
                bat.HandleMovement(keyReleased->scancode, false);
            }

        }
        sf::Time dt = clock.restart();

        //update bat
        bat.update(dt);
        ball.update(dt);

        std::stringstream ss;
        ss << "Scores: " << scores << " Lives: " << lives << "Dt: " << dt.asSeconds() << "FPS: " << 1.f / dt.asSeconds();
        hud.setString(ss.str());

        if(ball.getPosition().position.y > window.getSize().y){
            ball.reboundBottom();
            lives--;
            if(lives < 1){
                lives = 3;
                scores = 0;
            }
        }
        if (ball.getPosition().position.y < 0){
            ball.reboundBatOrTop();
            scores++;
        }
        if(ball.getPosition().position.x < 0 || ball.getPosition().position.x > window.getSize().x){
            ball.reboundSide();
        }
        if(ball.getPosition().findIntersection(bat.getPosition())){
            ball.reboundBatOrTop();
            scores++;
        }


        //draw bat
        window.clear();

        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(hud);

        window.display();


    }


    return 0;
}
