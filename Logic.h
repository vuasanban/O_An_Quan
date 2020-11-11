//
// Created by DELL on 10/25/2020.
//

#ifndef UNTITLED_LOGIC_H
#define UNTITLED_LOGIC_H

#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


using namespace std;
using namespace sf;

class Logic {
private:
    vector <int> tiles_amt;
    vector <int> player_point;

public:
    Logic();
    ~Logic();

    Logic(vector <int> tiles_amt, vector <int> player_point);
    bool first_time_resize = true;
    void firstTimeSet();
    void setupTilesAmt(int mark, int index, string key, vector <int> &a, vector <int> &b);
    int resetTilesAmt(int mark, int index);
    void pickAndDropAndTake(int mark, string key, int index);
    void checkEmpty(int index);
};


#endif //UNTITLED_LOGIC_H
