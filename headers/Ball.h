#pragma once
#include <SFML/Graphics.hpp>




class Ball{

    private:
        sf::Vector2f m_position;
        sf::RectangleShape m_shape;
        float m_speed = 300.f;
        float m_dx = 0.2f;
        float m_dy = 0.2f;




    public:
        Ball(float startX, float startY);
        sf::FloatRect getPosition();
        sf::RectangleShape getShape();
        float getXVelocity();
        void reboundSide();
        void reboundBatOrTop();
        void reboundBottom();
        void update(sf::Time dt);

};