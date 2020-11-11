//
// Created by DELL on 11/11/2020.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Draw.h"

using namespace std;
using namespace sf;

class Menu {
private:
public:
    Menu();
    ~Menu();

    bool mainmenu = true;
    bool about = false;

    void menuSet(Draw &draw, RenderWindow& window, bool &isPressed, int &i, bool &menudisplay);
};


#endif //UNTITLED_MENU_H
