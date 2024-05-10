#include "SpaceEngine.h"

SpaceEngine::SpaceEngine():_player(24,41),_enemy1(83,24),_enemy2(83,10),_enemy3(83,36){
    _lives = 3;
    _scores = 0; 
};

void SpaceEngine::init(){

    _player.init(24,24);

    _enemy1.init(83,6);
    _enemy2.init(83,10);
    _enemy3.init(83,26);

}

int SpaceEngine::update(UserInput input) {
    _player.update(input);
    _enemy1.update();
    _enemy2.update();
    _enemy3.update();

    collision();


    _scores += 1; 

    if (_scores >= 400) {
        return 1; // Win condition
    }

    if (_lives <= 0) {
        return -1; // Lose condition
    }

    return 0; // Game continues
}


void SpaceEngine::draw(N5110 &lcd){
    _player.draw(lcd);
    _enemy2.draw(lcd);
    _enemy3.draw(lcd);
}
void SpaceEngine::collision() {
    // Check collisions between player and each enemy
    if (_player.get_pos_x() >= _enemy1.get_pos_x() && _player.get_pos_x() <= _enemy1.get_pos_x()+4 && _player.get_pos_y() >= _enemy1.get_pos_y()&& _player.get_pos_y() <= _enemy1.get_pos_y()+2) {
        _lives--;
    }
    if (_player.get_pos_x() >= _enemy2.get_pos_x() && _player.get_pos_x() <= _enemy2.get_pos_x()+4 && _player.get_pos_y() >= _enemy2.get_pos_y()&& _player.get_pos_y() <= _enemy2.get_pos_y()+2) {
        _lives--;
    }
    if (_player.get_pos_x() >= _enemy3.get_pos_x() && _player.get_pos_x() <= _enemy3.get_pos_x()+4 && _player.get_pos_y() >= _enemy3.get_pos_y()&& _player.get_pos_y() <= _enemy3.get_pos_y()+2) {
        _lives--;
    }
}

int SpaceEngine::getLives() const {
    return _lives;
}

int SpaceEngine::getScores() const {
    return _scores;
}
