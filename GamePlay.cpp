//
// Created by DELL on 10/24/2020.
//

#include "GamePlay.h"

GamePlay::GamePlay() {}

GamePlay::~GamePlay() {}

GamePlay::GamePlay(Logic logic, Draw draw, vector <int> tiles_amt) {
    this->logic = logic;
    this->draw = draw;
    this->tiles_amt = tiles_amt;
}

void GamePlay::updateTilesAmount(vector<int> &tiles_amt, int mark, int index, string key) {
    tiles_amt = logic.getTilesAmount(mark, index, key);
}

void GamePlay::setGamePlay(RenderWindow& window, int &index, bool &check, bool &first_time_set, string &key) {

//    int mark = draw.getMark();
    draw.setup();
//    if (first_time_set){
//        logic.firstTimeSet();
//        first_time_set = false;
//        updateTilesAmount(tiles_amt, mark, index, key);
//    }
//    draw.drawFirstThings(window);
//    key = "";
    draw.drawPlayerPoint(window, player_point);
//    draw.drawPlayGround(window, tiles_amt);
//    if (Keyboard::isKeyPressed(Keyboard::Space)) {
//        check = true;
//    }
//    int tmp = index;
//    if (check){
//        if (Keyboard::isKeyPressed(Keyboard::Right)){
//            if (index == 1) index = 2;
//            else index = 1;
//            check = false;
//            key = "right";
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Left)){
//            if (index == 1) index = 2;
//            else index = 1;
//            check = false;
//            key = "left";
//        }
//    }
//
//    if (check == true){
//        draw.drawWhiteTile(window, index);
//        draw.drawArrow(window, index);
//    }
//    if (check == false) {
//        draw.drawFirstCursor(window, index);
//        draw.drawCursor(window, index);
//    }
//
//
//    draw.drawPickedPlayer(window, index);
////    logic.getPlayerPoint(player_point);
//    updateTilesAmount(tiles_amt, mark, tmp, key);

}

void GamePlay::setGamePlayTest(RenderWindow &window, int &index, bool &check, bool &first_time_set, string &key, Draw draw, vector <int> &player_point, Logic &logic) {
    draw.setup();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered)
//                if (event.text.unicode < 128){
//                    cout << event.text.unicode;
//                }
            if (event.type == sf::Event::MouseButtonReleased){
//                cout << "Released\n";
            }
        }

        window.clear();
        draw.drawPlayerPoint(window, player_point);
        draw.getMark();
        if (first_time_set){
            logic.firstTimeSet();
            first_time_set = false;
            updateTilesAmount(tiles_amt, mark, index, key);
        }
        draw.drawFirstThings(window);
        key = "";
        draw.drawPlayGround(window, tiles_amt);
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            check = true;
        }
        int tmp = index;
        if (check){
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                if (index == 1) index = 2;
                else index = 1;
                check = false;
                key = "right";
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                if (index == 1) index = 2;
                else index = 1;
                check = false;
                key = "left";
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
        updateTilesAmount(tiles_amt, mark, tmp, key);
//        logic.getPlayerPoint(player_point);
        draw.drawPlayerPoint(window, player_point);
        window.display();
    }
}