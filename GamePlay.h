//
// Created by DELL on 10/24/2020.
//

#ifndef UNTITLED_GAMEPLAY_H
#define UNTITLED_GAMEPLAY_H

#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Draw.h"
#include "Logic.h"
#include "Menu.h"

using namespace std;
using namespace sf;

class GamePlay {
private:
    Draw draw;
    Logic logic;
    Menu menu;
    vector <int> tiles_amt;
    vector <int> player_point;
public:
    GamePlay();
    ~GamePlay();

    int mark = draw.getMark();
    GamePlay(Logic logic, Draw draw, Menu menu, vector <int> tiles_amt, vector <int> player_point);
    void setGamePlay(RenderWindow& window, int &index, bool &menudisplay, bool &check, bool &first_time_set, string &key);
};


#endif //UNTITLED_GAMEPLAY_H
