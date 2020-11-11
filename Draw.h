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

class Logic;

class Draw {
private:
    vector < pair<float,float> > tiles_pos;
    vector <Texture> t_map_list;
    vector <Sprite> map_list;

    Texture t_cursor,t_background,t_soil,t_arrow, t_grass;
    Sprite cursor,background,soil,arrow,grass;
    RectangleShape picked_player;

    Font font;
    Text player1, player2, player1_point, player2_point;

    RectangleShape menubackground;
    Text header, play, about, out;

    int mark = 4;
public:
    Draw();
    ~Draw();
    Draw(vector < pair<float,float> > tiles_pos, vector <Texture> t_map_list, vector <Sprite> map_list,
         Texture t_cursor, Texture t_background, Texture t_soil
         , Texture t_arrow, Texture t_grass, Sprite cursor, Sprite background, Sprite soil, Sprite arrow, Sprite grass,
         RectangleShape picked_player, Font font, Text player1, Text player2, Text player1_point,
         Text player2_point, RectangleShape menubackground, Text header, Text play, Text about, Text out, int mark);

    void setTilesPosition();
    void loadThings();
    void drawFirstThings(RenderWindow &window);
    void drawPlayGround(RenderWindow& window, vector <int> &tiles_amt);
    void drawSoil(RenderWindow& window, int amt, int i);
    void drawFirstCursor(RenderWindow& window, int &index);
    void drawCursor(RenderWindow &window, int &index);
    void adjustPickedPlayer();
    void drawPickedPlayer(RenderWindow& window, int &index);
    void setUpFont(Text &text);
    string changeNumToString(int num);
    void drawPlayerPoint(RenderWindow& window, vector <int> &player_point);
    void drawArrow(RenderWindow& window, int &index);
    void drawWhiteTile(RenderWindow& window, int &index);

    void drawMenu(RenderWindow& window, int i);
    void drawAbout(RenderWindow& window);

    int getMark();

    void setup();
};


#endif //UNTITLED_DRAW_H
