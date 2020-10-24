//
// Created by DELL on 10/24/2020.
//

#ifndef UNTITLED_GAMEPLAY_H
#define UNTITLED_GAMEPLAY_H

#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Draw.h"

using namespace std;
using namespace sf;

class GamePlay {
private:
    Draw draw;
public:
    GamePlay();
    ~GamePlay();

    GamePlay(Draw draw);

    void setGamePlay(RenderWindow& window, int &index, bool &check);
};


#endif //UNTITLED_GAMEPLAY_H
