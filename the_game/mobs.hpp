#include "algorithm"
#include "string"
#include "vector"

std::vector<std::string > minotaur_1_stand = { "sprites/minotaur_1/Minotaur_01_Taunt_000.png", "sprites/minotaur_1/Minotaur_01_Taunt_001.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_002.png", "sprites/minotaur_1/Minotaur_01_Taunt_003.png", "sprites/minotaur_1/Minotaur_01_Taunt_004.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_005.png", "sprites/minotaur_1/Minotaur_01_Taunt_006.png", "sprites/minotaur_1/Minotaur_01_Taunt_007.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_008.png", "sprites/minotaur_1/Minotaur_01_Taunt_009.png", "sprites/minotaur_1/Minotaur_01_Taunt_010.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_011.png", "sprites/minotaur_1/Minotaur_01_Taunt_012.png", "sprites/minotaur_1/Minotaur_01_Taunt_013.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_014.png", "sprites/minotaur_1/Minotaur_01_Taunt_015.png", "sprites/minotaur_1/Minotaur_01_Taunt_016.png",
	"sprites/minotaur_1/Minotaur_01_Taunt_017.png" };

std::vector<std::string > minotaur_2_stand = { "sprites/minotaur_2/Minotaur_02_Taunt_000.png", "sprites/minotaur_2/Minotaur_02_Taunt_001.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_002.png", "sprites/minotaur_2/Minotaur_02_Taunt_003.png", "sprites/minotaur_2/Minotaur_02_Taunt_004.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_005.png", "sprites/minotaur_2/Minotaur_02_Taunt_006.png", "sprites/minotaur_2/Minotaur_02_Taunt_007.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_008.png", "sprites/minotaur_2/Minotaur_02_Taunt_009.png", "sprites/minotaur_2/Minotaur_02_Taunt_010.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_011.png", "sprites/minotaur_2/Minotaur_02_Taunt_012.png", "sprites/minotaur_2/Minotaur_02_Taunt_013.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_014.png", "sprites/minotaur_2/Minotaur_02_Taunt_015.png", "sprites/minotaur_2/Minotaur_02_Taunt_016.png",
	"sprites/minotaur_2/Minotaur_02_Taunt_017.png" };

std::vector<std::string > minotaur_3_stand = { "sprites/minotaur_3/Minotaur_03_Taunt_000.png", "sprites/minotaur_3/Minotaur_03_Taunt_001.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_002.png", "sprites/minotaur_3/Minotaur_03_Taunt_003.png", "sprites/minotaur_3/Minotaur_03_Taunt_004.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_005.png", "sprites/minotaur_3/Minotaur_03_Taunt_006.png", "sprites/minotaur_3/Minotaur_03_Taunt_007.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_008.png", "sprites/minotaur_3/Minotaur_03_Taunt_009.png", "sprites/minotaur_3/Minotaur_03_Taunt_010.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_011.png", "sprites/minotaur_3/Minotaur_03_Taunt_012.png", "sprites/minotaur_3/Minotaur_03_Taunt_013.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_014.png", "sprites/minotaur_3/Minotaur_03_Taunt_015.png", "sprites/minotaur_3/Minotaur_03_Taunt_016.png",
	"sprites/minotaur_3/Minotaur_03_Taunt_017.png" };

std::vector<std::string > boss_1_sprites = { "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_000.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_001.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_002.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_003.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_004.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_005.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_006.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_007.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_008.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_009.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_010.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_011.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_012.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_013.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_014.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_015.png", "sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_016.png",
	"sprites/Wraith_3/PNG Sequences/Taunt/Wraith_03_Taunt_017.png" };

struct lightMobs
{
	/*
	<summary>
	Структура lightMobs описывает мобов (противников)
	У каждого моба изначально есть такие параметры:
	1) healthPoints - отвечает за текущее количество очков здоровья
	2) standartHealthPoints - отвечает за то количество очков здоровья, с которым заспавнится моб
	3) coins - отвечает за то количество монет, которое получит игрок, когда убьет данного моба
	</summary>
	*/
	int healthPoints = 10;
	int standartHealthPoints = 10;
	int coins = 5;
	std::vector<std::string > sprites;

	int levelUp()
	{
		/// <summary>
		/// Функция не принимает на вход никаких параметров и отдает значение типа int
		/// </summary>
		/// <returns>
		/// При выполнении данной функции моб воскресает с большим количеством очков здоровья и монет в кармане
		/// </returns>
		while (healthPoints < standartHealthPoints)
			healthPoints += 1;
		healthPoints += 10;
		standartHealthPoints += 10;
		coins += 5;
		return 0;
	}

	bool isNotAlive()
	{
		/// <summary>
		/// Функция не принимает на вход никаких параметров и возвращает значение типа bool
		/// </summary>
		/// <returns>
		/// Функция проверяет на наличие у моба очков здоровья и в зависимости от результата выводит либо "true", либо "false"
		/// </returns>
		if (healthPoints <= 0)
			return true;
		else
			return false;
	}

	std::string getNextSprite(int n)
	{
		/// <summary>
		/// Функция принимает на вход один параметр и отдает конкретный спрайт
		/// </summary>
		/// <param name="n"> 
		/// Параметр отвечает за выбор конкретного спрайта для прорисовки
		/// </param>
		/// <returns>
		/// Возвращает конкретный спрайт в формате std::string
		/// </returns>
		return sprites[n];
	}
};

struct boss
{
	/*
	<summary>
	Структура boss описывает мобов (противников) повышенной сожности
	У каждого моба изначально есть такие параметры:
	1) healthPoints - отвечает за текущее количество очков здоровья
	2) standartHealthPoints - отвечает за то количество очков здоровья, с которым заспавнится моб
	3) coins - отвечает за то количество монет, которое получит игрок, когда убьет данного моба
	</summary>
	*/
	int healthPoints = 100;
	int coins = 100;
	std::vector<std::string > sprites;

	int levelUp()
	{
		/// <summary>
		/// Функция не принимает на вход никаких параметров и отдает значение типа int
		/// </summary>
		/// <returns>
		/// При выполнении данной функции моб воскресает с большим количеством очков здоровья и монет в кармане
		/// </returns>
		healthPoints += 100;
		coins += 100;
		return 0;
	}

	bool isNotAlive()
	{
		/// <summary>
		/// Функция не принимает на вход никаких параметров и возвращает значение типа bool
		/// </summary>
		/// <returns>
		/// Функция проверяет на наличие у моба очков здоровья и в зависимости от результата выводит либо "true", либо "false"
		/// </returns>
		if (healthPoints <= 0)
			return true;
		else
			return false;
	}
};

class player
{
	/*
	<summary>
	Класс Player описывает игрока у которого есть такие параметры:
	1) damage - урон наносимый за один удар по мобу
	2) coins - количество монет в кошельке (сейчас)
	3) costOfUpgrade - стоимость улучшения оружия
	</summary>
	*/
	public:
		int damage = 1;
		int coins = 0;
		int costOfUpgrade = 10;

		int swordUpgrade()
		{
			/// <summary>
			/// Функция не принимает на вход никаких параметров и возвращает значение типа int
			/// </summary>
			/// <returns>
			/// Функция увеличивает урон игрока за один удар на одну единицу
			/// </returns>
			damage += 1;
			return 0;
		}

		int costUpdate()
		{
			/// <summary>
			/// Функция не принимает на вход никаких параметров и возвращает значение типа int
			/// </summary>
			/// <returns>
			/// Функция срабатывает после того, как игрок увеличил свой урон, чтобы поднять цену на следующее увеличение урона
			/// </returns>
			costOfUpgrade += 10;
			return 0;
		}
};