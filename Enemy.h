#ifndef ENEMY_H
#define ENEMY_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"

class Enemy{
    public:
        Enemy(int x, int y);
        void init(int x, int y);
        void draw(N5110 &lcd);
        void update();

        void set_velocity(Position2D v);
        Position2D get_velocity();
        int get_pos_x() const;
        int get_pos_y() const;
        void set_pos(Position2D p);

    private:
        Position2D _velocity;
        mutable int _x;
        mutable int _y;
        const int enemy[4][6]{
           {0,0,0,1,0,0},
           {1,1,1,1,1,1},
           {1,1,1,1,1,0},
           {0,0,0,1,0,0},
        };
};

#endif
