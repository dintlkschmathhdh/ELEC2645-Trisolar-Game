#include "Player.h"

Player::Player(int x, int y){}

void Player::init(int x, int y){
    _x = 6;
    _y = 10;
}

void Player::draw(N5110 &lcd){
   lcd.drawSprite(_x,_y,6,6,(int*) _player);
}

void Player::update(UserInput input){
    if (input.d == N) { _y-=3; } 
    else if (input.d == E) { _x+=3; }
    else if (input.d == S) { _y+=3; } 
    else if (input.d == W) { _x-=3; }

    if (_y < 0) { _y = 0; }
    if (_y > 36 - 6) { _y = 28 - 6; }

    if (_x < 0) { _x = 0; }
    if (_x > 84 -6) { _x = 84 - 6; }
}

int Player::get_pos_x() { return _x; }

int Player::get_pos_y() { return _y; }
