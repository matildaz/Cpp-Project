#include "mobs.hpp"
#include <SFML/Graphics.hpp>

auto textureSprite(sf::RenderWindow window) {
    sf::Texture texture;
    texture.loadFromFile("\sprites\minotaur_1\Minotaur_01_Taunt_000.png");
    sf::Sprite  sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200, 100);
    window.draw(sprite);
}

bool cursorPosition(sf::Vector2i position) {
    if ((position.x >= 200) && (position.x <= 600)) {
        if (position.y >= 100 && position.y <= 400)
            return true;
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 1000), "My window");

    sf::Texture texture;
    texture.loadFromFile("sprites/minotaur_1/Minotaur_01_Taunt_000.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Cursor cursor;
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position = sf::Mouse::getPosition();
                if (cursorPosition(position) == true)
                    continue;
            }
        }

    window.draw(sprite);

    // end the current frame
    window.display();
    }

    return 0;
}