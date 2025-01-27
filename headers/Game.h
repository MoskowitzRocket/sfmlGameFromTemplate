#include <SFML/Graphics.hpp>

class Game{

    private:

        sf::Vector2f m_position;
        sf::RectangleShape m_batShape;
        bool m_movingLeft = false;
        bool m_movingRight = false;
        int m_speed = 300;


    public:

        Game(float startX, float startY);
        sf::RectangleShape getShape();
        sf::FloatRect getPosition();

        void HandleMovement(sf::Keyboard::Scancode key, bool isPressed);
        void update(sf::Time dt);



};