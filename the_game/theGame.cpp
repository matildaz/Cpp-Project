#include "mobs.hpp"
#include <SFML/Graphics.hpp>
#include "string"
#include "vector"
#include "memory"

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

    lightMobs mob_1;
    lightMobs mob_2;
    lightMobs mob_3;
    int cntMob = 0;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Clock clock;

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
                cntMinoyaur += 1;
                if (cntMinoyaur > 3)
                    cntMinoyaur = 0;
                n = 0;
                if (cntMinoyaur == 0)
                    mobPicture = minotaur_1_stand;
                else if (cntMinoyaur == 1)
                    mobPicture = minotaur_2_stand;
                else {
                    mobPicture = minotaur_3_stand;
                    cntMob += 1;
                }
            }
            sf::sleep(sf::milliseconds(50));
            clock.getElapsedTime();
            clock.restart();
        }

    sf::Texture texture;
    texture.loadFromFile(texture_mob(n, mobPicture));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 100);

    window.draw(sprite);

    // end the current frame
    window.display();
    window.clear(sf::Color::White);
    n += 1;
    if (n > 17)
        n = 0;

    if (mob_3.isNotAlive() == true) {
        mob_1.levelUp();
        mob_2.levelUp();
        mob_3.levelUp();
        cntMob = 0;
        }
    }

    return 0;
}