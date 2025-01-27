#include "../headers/Game.h"

Game::Game(float startX, float startY) : m_position({startX, startY}){
    m_batShape.setSize({20, 5});
    m_batShape.setPosition(m_position);
    m_movingLeft = false;
    m_movingRight = false;
}

sf::RectangleShape Game::getShape(){
    return m_batShape;
}

sf::FloatRect Game::getPosition(){
    return m_batShape.getGlobalBounds();
}

void Game::HandleMovement(sf::Keyboard::Scancode key, bool isPressed){
    // if(key == sf::Keyboard::Scancode::A){
    //     m_movingLeft = isPressed;
    // }else if(key == sf::Keyboard::Scancode::D){
    //     m_movingRight = isPressed;
    // }
    switch(key){
        case sf::Keyboard::Scancode::A:
            m_movingLeft = isPressed;
            break;
        case sf::Keyboard::Scancode::D:
            m_movingRight = isPressed;
            break;
    }

    
}

void Game::update(sf::Time dt){
    if(m_movingLeft){
        m_position.x -= m_speed * dt.asSeconds();
    }

    if(m_movingRight){
        m_position.x += m_speed * dt.asSeconds();
    }

    m_batShape.setPosition(m_position);
}