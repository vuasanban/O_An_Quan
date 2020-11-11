#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "GamePlay.h"

using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");
    window.setFramerateLimit(10);

    GamePlay gameplay;

    bool menudisplay = true;
    bool check = false;
    bool first_time_set = true;
    string key = "";
    int index = 1;

    gameplay.setGamePlay(window, index, menudisplay, check, first_time_set, key);

    return 0;
}