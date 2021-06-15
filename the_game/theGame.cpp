#include "mobs.hpp"
#include <SFML/Graphics.hpp>
#include "string"
#include "vector"
#include "memory"

std::string texture_mob(int n, std::vector<std::string > mob)
{
	///<summary>
	/// Функция получает число и массив со спрайтами и выдает конкретный спрайт на выходе
	///</summary>
	///<param name="n"> переменная типа int указывающая на номер спрайта</param>
	///<param name="mob"> переменная типа std::vector<std::string > имеющая в себе некоторое количество спрайтов не превосходщее "n"</param>
	///<returns> Функция выдает на выходе спрайт с номером "n" из массива "mob"</returns>
	return mob[n];
}

bool cursorPosition(sf::Vector2i position)
{
	///<summary>
	/// Функция определения позиции курсора
	///</summary>
	///<param name="position"> переменная типа sf::Vector2i содержащая в себе координаты курсора</param>
	///<returns> Функция выдает "true" если курсор находится в заданной площади и "false" если курсор там не находится</returns>
	if ((position.x >= 200) && (position.x <= 600))
	{
		if (position.y >= 100 && position.y <= 550)
			return true;
	}
}

bool cursorPositionInfo(sf::Vector2i position)
{
	///<summary>
	/// Функция определения позиции курсора
	///</summary>
	///<param name="position"> переменная типа sf::Vector2i содержащая в себе координаты курсора</param>
	///<returns> Функция выдает "true" если курсор находится в заданной площади и "false" если курсор там не находится</returns>
	if (position.x >= 703 && position.x <= 767)
	{
		if (position.y >= 35 && position.y <= 99)
			return true;
	}
}

bool cursorPositionUp(sf::Vector2i position)
{
	///<summary>
	/// Функция определения позиции курсора
	///</summary>
	///<param name="position"> переменная типа sf::Vector2i содержащая в себе координаты курсора</param>
	///<returns> Функция выдает "true" если курсор находится в заданной площади и "false" если курсор там не находится</returns>
	if ((position.x >= 75) && (position.x <= 725))
	{
		if (position.y >= 859 && position.y <= 939)
			return true;
	}
}

int rendInfoWindow()
{
	///<summary>
	/// Функция по созданию всплывающего окна информации
	///</summary>
	///<returns> возвращает переменную типа int</returns>
	sf::RenderWindow infoWindow(sf::VideoMode(500, 400), "Information");	// генерация окна

	sf::Font font;	// создание шрифта
	sf::Text text;	// создание текста
	font.loadFromFile("external/Fonts/BalooTammudu2-Bold.ttf");	// загрузка шрифта
	text.setFont(font);	// совмещение шрифта и текста
	text.setCharacterSize(20);	// установка размера текста
	text.setFillColor(sf::Color::Black);	// установка цвета тектса
	text.setStyle(sf::Text::Bold);	// установка стиля текста
	text.setPosition(20, 20);	// утановка позиции текста
	text.setString("May the force be with you, knight!\nHere are some things\nyou need to know:\n1) First of all - do not\ngive mobs chance to stay alive\n2) If you want to upgrade your sward -\njust klick on button with the cost of upgade\n3) Kill them all!");
	// написание самого текста

	while (infoWindow.isOpen())	// открытие окна (пока окно открыто)...
	{
		sf::Event event;	// создание события
		while (infoWindow.pollEvent(event))	// распознование событий
		{
			if (event.type == sf::Event::Closed)	// есди событие равно закрытию окна, то окно закрывается
				infoWindow.close();
		}

		infoWindow.clear(sf::Color::White);	// очищение окна
		infoWindow.draw(text);	// прорисовка текста
		infoWindow.display();	// отображениие всего нарисованого в окне
	}

	return 0;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "My window");	// создание игрового окна

	// задний фон
	sf::Texture background;	// генерация текстуры заднего фона
	background.loadFromFile("sprites/background/Group 7backgroundV1.png");	// загрузка текстуры из файла
	sf::Sprite backgroundSprite;	// создание спрайта
	backgroundSprite.setTexture(background);	// отображение текстуры в виде спрайта

	// переменные
	bool block = false;	// переменная отвечает за нажатие клавиши (если false - не нажата, true - нажата)
	int n = 0;	// переменная отвечает за номер спрайта
	int cntMinoyaur = 0;	// 
	int cntMob = 0;	//

	// Player and mobs
	player knight;	// создание игрока
	lightMobs mob_1;	// создание первого моба
	lightMobs mob_2;	// создание второго моба
	lightMobs mob_3;	// создание третьего моба
	boss boss_1;	// создание босса

	// Спрайты и текстуры
	sf::Sprite sprite;
	sf::Texture texture;

	///<Тексты и шрифты>
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
	///</Тексты и шрифты>

	while (window.isOpen())	// открытие игрового окна
	{
		window.clear(sf::Color::White);	// очищение экрана 
		window.draw(backgroundSprite);	// зарисовка фона

		// проверка всех событий окна, которые были запущены с момента последней итерации цикла
		sf::Event event;

		while (window.pollEvent(event))
		{
			// закрытие окна при нажатии на кнопку закрытия
			if (event.type == sf::Event::Closed)
				window.close();

			// проверка на нажатие клавиши на мышке
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!block)	// если клавиша уже зажата, то программа не заходит в данный if
				{
					block = true;	// блокировка постоянного нажатия
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// проверка на наатие левой клавиши мыши
					{
						sf::Vector2i position = sf::Mouse::getPosition(window);	// вычисление позиции курора
						if (cursorPositionInfo(position) == true)	// если пользователь нажал на иконку информации, то открывается окно помощи
						{
							rendInfoWindow();
						}

						if (cursorPositionUp(position) == true & knight.coins >= knight.costOfUpgrade)	// проверка на нажатие определенной области и необходимого количества монет на улучшение
						{
							knight.coins -= knight.costOfUpgrade;
							knight.swordUpgrade();
							knight.costUpdate();
							std::string coinsStr = std::to_string(knight.coins);
							coinsStr += " Coins";
							playerCoins.setString(coinsStr);
						}
					}

					if (mob_1.isNotAlive() == false)	// проверка на наличие очков здоровья у первого моба
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// проверка на наатие левой клавиши мыши
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);	// вычисление позиции курора
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
								if (mob_1.isNotAlive())	// если моб погибает, то игроку достаются все монеты
								{
									knight.coins += mob_1.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}
					else if (mob_2.isNotAlive() == false)	// если первый моб мертв, идет проверка на наличие очков здоровья у второго моба
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// проверка на наатие левой клавиши мыши
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);	// вычисление позиции курора
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
								if (mob_2.isNotAlive())	// если моб погибает, то игроку достаются все монеты
								{
									knight.coins += mob_2.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}
					else if (mob_3.isNotAlive() == false)	// если второй моб погибает, то идет проверка на наличие очков здоровья у третьего моба
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// проверка на наатие левой клавиши мыши
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);	// вычисление позиции курора
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
								if (mob_3.isNotAlive())	// если моб погибает, то игроку достаются все монеты
								{
									knight.coins += mob_3.coins;
									std::string coinsStr = std::to_string(knight.coins);
									coinsStr += " Coins";
									playerCoins.setString(coinsStr);
								}
							}
						}
					}

					if (mob_3.isNotAlive() == true)	// если все мобы погибли, то на их место приходит БОСС
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// проверка на наатие левой клавиши мыши
						{
							sf::Vector2i position = sf::Mouse::getPosition(window);	// вычисление позиции курора
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
								if (boss_1.isNotAlive())	// если босс погибает, то игроку достается клад, а все мобы и сам босс воскрешаются, но с большим количеством очков здоровья
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

			if (event.type == sf::Event::MouseButtonReleased)	// если клавиша отжимается, то блокировка с зажимания снимается до повторного нажатия
			{
				block = false;
			}
		}

		sf::Cursor cursor;	// создание курсора как отдельного объекта
		if (cursor.loadFromSystem(sf::Cursor::Hand))	// отдельная прорисовка курсора
			window.setMouseCursor(cursor);

		if (mob_1.isNotAlive() == false)	// пока первый моб жив, идет его прорисовка 
		{
			// загрузка текстуры моба из файла
			texture.loadFromFile(minotaur_1_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
		}
		else if (mob_2.isNotAlive() == false)	// пока второй моб жив, идет его прорисовка
		{
			// загрузка текстуры моба из файла
			texture.loadFromFile(minotaur_2_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
		}
		else if (mob_3.isNotAlive() == false)	// пока третий моб жив, идет его прорисовка
		{
			// загрузка текстуры моба из файла
			texture.loadFromFile(minotaur_3_stand[n]);
			sprite.setTexture(texture);
			sprite.setPosition(0, 105);
		}

		// написание текста с показателями урона за один удар
		std::string damageStr = std::to_string(knight.damage);
		damageStr += " per one hit";
		playerDamage.setString(damageStr);
		playerCostOfUpgrade.setString(std::to_string(knight.costOfUpgrade) + " coins to upgrade your sword");

		if (mob_3.isNotAlive() == true)	// пока босс жив, идет его прорисовка
		{
			bossIsNow.setString("BOSS");
			window.draw(bossIsNow);
			texture.loadFromFile(boss_1_sprites[n]);
			sprite.setTexture(texture);
			sprite.setPosition(100, 200);
		}

		// зарисовки отдельных объектов
		window.draw(text);
		window.draw(sprite);
		window.draw(playerCoins);
		window.draw(playerDamage);
		window.draw(playerCostOfUpgrade);

		// отображение объектов на экране
		window.display();

		n += 1;
		if (n > 17)	// увеличение номера спрайта
			n = 0;

	}

	return 0;
}