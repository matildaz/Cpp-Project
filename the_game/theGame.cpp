#include "mobs.hpp"
#include <SFML/Graphics.hpp>
#include "string"
#include "vector"

std::string texture_mob(int n, std::vector<std::string> mob) {
    return mob[n];
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

    int n = 0;
    auto mobPicture = minotaur_1_stand;
    int cntMinoyaur = 0;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Texture texture;
        texture.loadFromFile(texture_mob(n,mobPicture));
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(0, 100);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Cursor cursor;
        if (cursor.loadFromSystem(sf::Cursor::Hand))
            window.setMouseCursor(cursor);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            if (cursorPosition(position) == true) {
                cntMinoyaur = n % 3;
                n = 0;
                if (cntMinoyaur == 0)
                    mobPicture = minotaur_1_stand;
                else if (cntMinoyaur == 1)
                    mobPicture = minotaur_2_stand;
                else
                    mobPicture = minotaur_3_stand;
            }                    
        }

    window.draw(sprite);

    // end the current frame
    window.display();
    window.clear(sf::Color::White);
    n += 1;
    if (n > 17)
        n = 0;
    }

    return 0;
}