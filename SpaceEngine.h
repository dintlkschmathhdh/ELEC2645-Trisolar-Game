#ifndef SPACEENGINE_H
#define SPACEENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class SpaceEngine{
    public:
        SpaceEngine();
        void init();
        int update(UserInput input);
        void draw(N5110 &lcd);
        void collision(); 
        
        int getLives() const;
        int getScores() const;
    private:
        Player _player;
        Enemy _enemy1;
        Enemy _enemy2;
        Enemy _enemy3;
        int _lives;
        int _scores;
        
};

#endif
