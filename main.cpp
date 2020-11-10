#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "GamePlay.h"

using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");
    window.setFramerateLimit(10);

    // Test field
    //

    Draw draw;
    GamePlay gameplay;
    Logic logic;

    vector <int> player_point(3,0);


    bool check = false;
    bool first_time_set = true;
    string key = "";
    int index = 1;

    gameplay.setGamePlayTest(window, index, check, first_time_set, key, draw, player_point, logic);
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if (event.type == sf::Event::TextEntered)
////                if (event.text.unicode < 128){
////                    cout << event.text.unicode;
////                }
//            if (event.type == sf::Event::MouseButtonReleased){
////                cout << "Released\n";
//            }
//        }
//
//        window.clear();
//        gameplay.setGamePlay(window, index, check, first_time_set, key);
////        logic.getPlayerPoint(player_point);
////        draw.drawPlayerPoint(window, player_point);
////        cout << "\nDIEM NGUOI 1 NGOAI MAIN: " << player_point[1] << "\nDIEM NGUOI 2 NGOAI MAIN: " << player_point[2];
//        window.display();
//    }

    return 0;
}