#include "../headers/Ball.h"

Ball::Ball(float startX, float startY) : m_position({startX, startY}){
    m_shape.setSize({10, 10});
    m_shape.setPosition(m_position);
}

sf::FloatRect Ball::getPosition(){
    return m_shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape(){
    return m_shape;
}

float Ball::getXVelocity(){
    return m_dx;
}

void Ball::reboundSide(){
    m_dx = -m_dx;
}

void Ball::reboundBatOrTop(){
    m_dy = -m_dy;
}

void Ball::reboundBottom(){
    m_position.y = 0;
    m_position.x = 500;
    m_dy = -m_dy;
}

void Ball::update(sf::Time dt){
    m_position = m_shape.getPosition();

    m_position.x += m_dx * m_speed * dt.asSeconds();
    m_position.y += m_dy * m_speed * dt.asSeconds();

    m_shape.setPosition(m_position);
}
