#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "GamePlay.h"

using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");
    window.setFramerateLimit(10);
    float deltaTime = 1.0f/60;

    Draw draw;
    GamePlay gameplay;

    draw.setup();
//    draw.drawFirstCursor();
    bool check = false;
    int index = 1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered)
                if (event.text.unicode < 128){
                    cout << event.text.unicode;
                }
            if (event.type == sf::Event::MouseButtonReleased){
                cout << "Released\n";
            }
        }


        window.clear();
        draw.drawFirstThings(window);
  //      draw.drawPickedPlayer(window, 1);
        gameplay.setGamePlay(window, index, check);
//        draw.drawCursor(window, index);
//        draw.drawArrow(window);
        window.display();
    }

    return 0;
}