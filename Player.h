#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"

class Player{
    public:
        Player(int x, int y);
        void init(int x, int y);
        void draw(N5110 &lcd);
        void update(UserInput input);
        int get_pos_x();
        int get_pos_y();

    private:
        int _x;
        int _y;
    const int _player[6][6]= {
    { 0,0,1,0,0,0, },
    { 1,0,1,1,0,0, },
    { 1,1,1,1,1,0, },
    { 1,1,1,1,1,1, },
    { 1,0,1,1,0,0, },
    { 0,0,1,0,0,0, },
    };
   
};

#endif
