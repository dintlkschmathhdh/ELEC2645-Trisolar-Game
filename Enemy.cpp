#include "Enemy.h"

Enemy::Enemy(int x, int y){}

void Enemy::init(int x, int y){
    int _rand_position = (rand() % 9 + 1)*3;
    _x = 83;
    _y = _rand_position;

    int _rand_velocity = (rand() % 3 + 2)*2;

    _velocity.x = _rand_velocity;
    _velocity.y = 0;

}

void Enemy::draw(N5110 &lcd){
    lcd. drawSprite(_x,_y,4,6,(int*)enemy);
}

void Enemy::update(){   
    _x -= _velocity.x;

    if (_x < 0) {

        _x = 84;
        
        int _rand_position = (rand() % 9 + 1) * 3;
        _y = _rand_position;
        
        int _rand_velocity = (rand() % 3 + 1)*2;
        _velocity.x = _rand_velocity;
    }
}

void Enemy::set_velocity(Position2D v){
    _velocity.x = v.x;
    _velocity.y = v.y;
}

void Enemy::set_pos(Position2D p) {
    _x = p.x;
    _y = p.y;
}

Position2D Enemy::get_velocity(){ return {_velocity.x,_velocity.y}; }

int Enemy::get_pos_x() const { return _x; }

int Enemy::get_pos_y() const { return _y; }
