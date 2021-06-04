#include "algorithm"
//random_shuffle(arr[0],arr[3]);

class lightMobs {
    int healthPoints = 10;    
    int coins = 5;

    int levelUp() {
        healthPoints += 10;
        coins += 5;
    }
};

class boss {
    int healthPoints = 100;
    int coins = 100;
    int timeToLeave = 90;

    int levelUp() {
        healthPoints += 100;
        coins += 100;
    }
};

class player {
    int damage = 1;

    int swordUpgrade() {
        damage += 1;
    }
};