#include "algorithm"
#include "string"
#include "vector"

std::vector<std::string> minotaur_1_stand = { "sprites/minotaur_1/Minotaur_01_Taunt_000.png","sprites/minotaur_1/Minotaur_01_Taunt_001.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_002.png","sprites/minotaur_1/Minotaur_01_Taunt_003.png","sprites/minotaur_1/Minotaur_01_Taunt_004.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_005.png","sprites/minotaur_1/Minotaur_01_Taunt_006.png","sprites/minotaur_1/Minotaur_01_Taunt_007.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_008.png","sprites/minotaur_1/Minotaur_01_Taunt_009.png","sprites/minotaur_1/Minotaur_01_Taunt_010.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_011.png","sprites/minotaur_1/Minotaur_01_Taunt_012.png","sprites/minotaur_1/Minotaur_01_Taunt_013.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_014.png","sprites/minotaur_1/Minotaur_01_Taunt_015.png","sprites/minotaur_1/Minotaur_01_Taunt_016.png",
    "sprites/minotaur_1/Minotaur_01_Taunt_017.png" };

std::vector<std::string> minotaur_2_stand = { "sprites/minotaur_2/Minotaur_02_Taunt_000.png","sprites/minotaur_2/Minotaur_02_Taunt_001.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_002.png","sprites/minotaur_2/Minotaur_02_Taunt_003.png","sprites/minotaur_2/Minotaur_02_Taunt_004.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_005.png","sprites/minotaur_2/Minotaur_02_Taunt_006.png","sprites/minotaur_2/Minotaur_02_Taunt_007.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_008.png","sprites/minotaur_2/Minotaur_02_Taunt_009.png","sprites/minotaur_2/Minotaur_02_Taunt_010.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_011.png","sprites/minotaur_2/Minotaur_02_Taunt_012.png","sprites/minotaur_2/Minotaur_02_Taunt_013.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_014.png","sprites/minotaur_2/Minotaur_02_Taunt_015.png","sprites/minotaur_2/Minotaur_02_Taunt_016.png",
    "sprites/minotaur_2/Minotaur_02_Taunt_017.png" };

std::vector<std::string> minotaur_3_stand = { "sprites/minotaur_3/Minotaur_03_Taunt_000.png","sprites/minotaur_3/Minotaur_03_Taunt_001.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_002.png","sprites/minotaur_3/Minotaur_03_Taunt_003.png","sprites/minotaur_3/Minotaur_03_Taunt_004.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_005.png","sprites/minotaur_3/Minotaur_03_Taunt_006.png","sprites/minotaur_3/Minotaur_03_Taunt_007.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_008.png","sprites/minotaur_3/Minotaur_03_Taunt_009.png","sprites/minotaur_3/Minotaur_03_Taunt_010.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_011.png","sprites/minotaur_3/Minotaur_03_Taunt_012.png","sprites/minotaur_3/Minotaur_03_Taunt_013.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_014.png","sprites/minotaur_3/Minotaur_03_Taunt_015.png","sprites/minotaur_3/Minotaur_03_Taunt_016.png",
    "sprites/minotaur_3/Minotaur_03_Taunt_017.png" };

struct lightMobs {
    int healthPoints = 10; 
    int standartHealthPoints = 10;
    int coins = 5;
    std::vector<std::string> sprites;

    lightMobs(std::vector<std::string> sprites) {
        sprites = minotaur_1_stand;
    }

    int levelUp() {
        while (healthPoints < standartHealthPoints)
            healthPoints += 1;
        healthPoints += 10;
        standartHealthPoints += 10;
        coins += 5;
        return 0;
    }

    bool isNotAlive() {
        if (healthPoints <= 0)
            return true;
        else
            return false;
    }

    std::string getNextSprite(int n) {
        return sprites[n];
    }
};

struct boss {
    int healthPoints = 100;
    int coins = 100;
    int timeToLeave = 90;

    int levelUp() {
        healthPoints += 100;
        coins += 100;
    }
};

struct player {
    int damage = 1;
    int coins = 0;

    int swordUpgrade() {
        damage += 1;
    }
};