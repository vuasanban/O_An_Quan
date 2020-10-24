//
// Created by DELL on 10/24/2020.
//

#include "GamePlay.h"

GamePlay::GamePlay() {}

GamePlay::~GamePlay() {}

GamePlay::GamePlay(Draw draw) {
    this->draw = draw;
}

void GamePlay::setGamePlay(RenderWindow& window, int &index, bool &check) {
    draw.setup();
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        check = true;
    }
    if (check){
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            if (index == 1) index = 2;
            else index = 1;
            check = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            if (index == 1) index = 2;
            else index = 1;
            check = false;
        }
    }

    if (check == true){
        draw.drawWhiteTile(window, index);
        draw.drawArrow(window, index);
    }
    if (check == false) {
        draw.drawFirstCursor(window, index);
        draw.drawCursor(window, index);
    }
    draw.drawPickedPlayer(window, index);
}