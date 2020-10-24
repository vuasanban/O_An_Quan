//
// Created by DELL on 10/23/2020.
//

#ifndef UNTITLED_DRAW_H
#define UNTITLED_DRAW_H
#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Draw {
private:
    vector < pair<float,float> > tiles_pos;
    vector <Texture> t_map_list;
    vector <Sprite> map_list;
    Texture t_cursor,t_background,t_soil,t_arrow;

    Sprite cursor,background,soil,arrow;
    RectangleShape picked_player;

    int mark = 4;
public:
    Draw();
    ~Draw();
    Draw(vector < pair<float,float> > tiles_pos, vector <Texture> t_map_list, vector <Sprite> map_list,
         Texture t_cursor, Texture t_background, Texture t_soil
         , Texture t_arrow, Sprite cursor, Sprite background, Sprite soil, Sprite arrow,
         RectangleShape picked_player, int mark);

    void setTilesPosition();
    vector < pair<float,float> > getTilesPosition();
    void loadThings();
    void drawFirstThings(RenderWindow &window);
    void drawFirstCursor(RenderWindow& window, int &index);
    Sprite getBackground();
    void drawCursor(RenderWindow &window, int &index);
    void adjustPickedPlayer();
    void drawPickedPlayer(RenderWindow& window, int &index);
    void drawArrow(RenderWindow& window, int &index);
    void drawWhiteTile(RenderWindow& window, int &index);

    void setup();
};


#endif //UNTITLED_DRAW_H
