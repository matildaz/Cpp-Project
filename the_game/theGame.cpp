#include "mobs.hpp"
#include <SFML/Graphics.hpp>
#include "string"
#include "vector"
#include "memory"

std::string texture_mob(int n, std::vector<std::string > mob)
{
	return mob[n];
}

bool cursorPosition(sf::Vector2i position)
{
	if ((position.x >= 200) && (position.x <= 600))
	{
		if (position.y >= 100 && position.y <= 550)
			return true;
	}
}

bool cursorPositionInfo(sf::Vector2i position)
{
	if (position.x >= 703 && position.x <= 767)
	{
		if (position.y >= 35 && position.y <= 99)
			return true;
	}
}

bool cursorPositionUp(sf::Vector2i position)
{
	if ((position.x >= 75) && (position.x <= 725))
	{
		if (position.y >= 859 && position.y <= 939)
			return true;
	}
}

int rendInfoWindow()
{
	sf::RenderWindow infoWindow(sf::VideoMode(500, 400), "Information");

	sf::Font font;
	sf::Text text;
	font.loadFromFile("external/Fonts/BalooTammudu2-Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(20, 20);
	text.setString("May the force be with you, knight!\nHere are some things\nyou need to know:\n1) First of all - do not\ngive mobs chance to stay alive\n2) If you want to upgrade your sward -\njust klick on button with the cost of upgade\n3) Kill them all!");

	while (infoWindow.isOpen())
	{
		sf::Event event;
		while (infoWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				infoWindow.close();
		}

		infoWindow.clear(sf::Color::White);
		infoWindow.draw(text);
		infoWindow.display();
	}

	return 0;
}

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 1000), "My window");

	bool block = false;

	// background
	sf::Texture background;
	background.loadFromFile("sprites/background/Group 7backgroundV1.png");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	// vars
	int n = 0;
	auto mobPicture = minotaur_1_stand;
	int cntMinoyaur = 0;
	int cntMob = 0;

	// Player and mobs
	player knight;
	lightMobs mob_1(minotaur_1_stand);
	lightMobs mob_2(minotaur_2_stand);
	lightMobs mob_3(minotaur_3_stand);
	boss boss_1(boss_1_sprites);

	// Sprites and textures
	sf::Sprite sprite;
	sf::Texture texture;

	// Texts and fonts
	sf::Font font;
	sf::Text text;
	font.loadFromFile("external/Fonts/BalooTammudu2-Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(450, 660);

	sf::Text playerDamage;
	playerDamage.setFont(font);
	playerDamage.setCharacterSize(40);
	playerDamage.setFillColor(sf::Color::Red);
	playerDamage.setStyle(sf::Text::Bold);
	playerDamage.setPosition(100, 660);

	sf::Text playerCoins;
	playerCoins.setFont(font);
	playerCoins.setCharacterSize(40);
	playerCoins.setFillColor(sf::Color::Red);
	playerCoins.setStyle(sf::Text::Bold);
	playerCoins.setPosition(100, 770);

	sf::Text playerCostOfUpgrade;
	playerCostOfUpgrade.setFont(font);
	playerCostOfUpgrade.setCharacterSize(40);
	playerCostOfUpgrade.setFillColor(sf::Color::Red);
	playerCostOfUpgrade.setStyle(sf::Text::Bold);
	playerCostOfUpgrade.setPosition(100, 870);

	sf::Text bossIsNow;
	bossIsNow.setFont(font);
	bossIsNow.setCharacterSize(60);
	bossIsNow.setFillColor(sf::Color::Red);
	bossIsNow.setStyle(sf::Text::Bold);
	bossIsNow.setPosition(310, 50);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		sf::Clock clock;
		window.clear(sf::Color::White);
		window.draw(backgroundSprite);

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!block)
				{
					block = true;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						sf::Vector2i position = sf::Mouse::getPosition(window);
						if (cursorPositionInfo(position) == true)
						{
							rendInfoWindow();
						}

						if (cursorPositionUp(position) == true & knight.coins >= knight.costOfUpgrade)
						{
							knight.coins -= knight.costOfUpgrade;
							knight.swordUpgrade();
							knight.costUpdate();
							std::string coinsStr = std::to_string(knight.coins);
							coinsStr += " Coins";
							playerCoins.setString(coinsStr);
						}
					}

					if (mob_1.isNotAlive() == false)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);
							if (cursorPosition(position) == true)
							{
								mob_1.healthPoints -= knight.damage;
								std::string hpStr;
								if (mob_1.healthPoints <= 0)
								{
									hpStr = std::to_string(mob_2.healthPoints);
								}
								else
								{
									hpStr = std::to_string(mob_1.healthPoints);
								}

								hpStr += " HP";
								text.setString(hpStr);
								if (mob_1.isNotAlive())
								{
									knight.coins += mob_1.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}
					else if (mob_2.isNotAlive() == false)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);
							if (cursorPosition(position) == true)
							{
								mob_2.healthPoints -= knight.damage;
								std::string hpStr;
								if (mob_2.healthPoints <= 0)
								{
									hpStr = std::to_string(mob_3.healthPoints);
								}
								else
								{
									hpStr = std::to_string(mob_2.healthPoints);
								}

								hpStr += " HP";
								text.setString(hpStr);
								if (mob_2.isNotAlive())
								{
									knight.coins += mob_2.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}
					else if (mob_3.isNotAlive() == false)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);
							if (cursorPosition(position) == true)
							{
								mob_3.healthPoints -= knight.damage;
								std::string hpStr;
								if (mob_3.healthPoints <= 0)
								{
									hpStr = std::to_string(boss_1.healthPoints);
								}
								else
								{
									hpStr = std::to_string(mob_3.healthPoints);
								}

								hpStr += " HP";
								text.setString(hpStr);
								if (mob_3.isNotAlive())
								{
									knight.coins += mob_3.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}

					if (mob_3.isNotAlive() == true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);
							if (cursorPosition(position) == true)
							{
								boss_1.healthPoints -= knight.damage;
								std::string hpStr;
								if (boss_1.healthPoints <= 0)
								{
									hpStr = std::to_string(mob_1.healthPoints);
								}
								else
								{
									hpStr = std::to_string(boss_1.healthPoints);
								}

								hpStr += " HP";
								text.setString(hpStr);
								if (boss_1.isNotAlive())
								{
									knight.coins += boss_1.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
									mob_1.levelUp();
									mob_2.levelUp();
									mob_3.levelUp();
									boss_1.levelUp();
									cntMob = 0;
								}
							}
						}
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				block = false;
			}
		}

		sf::Cursor cursor;
		if (cursor.loadFromSystem(sf::Cursor::Hand))
			window.setMouseCursor(cursor);

		if (mob_1.isNotAlive() == false)
		{
			// upload the texture of mob
			texture.loadFromFile(minotaur_1_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
		}
		else if (mob_2.isNotAlive() == false)
		{
			// upload the texture of mob
			texture.loadFromFile(minotaur_2_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
			// checking the clicking on mob
		}
		else if (mob_3.isNotAlive() == false)
		{
			// upload the texture of mob
			texture.loadFromFile(minotaur_3_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
			// checking the clicking on mob
		}

		std::string damageStr = std::to_string(knight.damage);
		damageStr += " per one hit";
		playerDamage.setString(damageStr);
		playerCostOfUpgrade.setString(std::to_string(knight.costOfUpgrade) + " coins to upgrade your sword");

		if (mob_3.isNotAlive() == true)
		{
			bossIsNow.setString("BOSS");
			window.draw(bossIsNow);
			texture.loadFromFile(boss_1_sprites[n]);
			sprite.setTexture(texture);
			sprite.setPosition(100, 200);
			// checking the clicking on mob
		}

		window.draw(text);
		window.draw(sprite);
		window.draw(playerCoins);
		window.draw(playerDamage);
		window.draw(playerCostOfUpgrade);

		// end the current frame
		window.display();

		n += 1;
		if (n > 17)
			n = 0;

	}

	return 0;
}