//
// Created by DELL on 10/24/2020.
//

#include "GamePlay.h"

GamePlay::GamePlay() {}

GamePlay::~GamePlay() {}

GamePlay::GamePlay(Logic logic, Draw draw, Menu menu, vector <int> tiles_amt, vector <int> player_point) {
    this->logic = logic;
    this->draw = draw;
    this->menu = menu;
    this->tiles_amt = tiles_amt;
    this->player_point = player_point;
}

void GamePlay::setGamePlay(RenderWindow &window, int &index, bool &menudisplay, bool &check, bool &first_time_set, string &key) {
    player_point.resize(3);
    tiles_amt.resize(13);

    draw.setup();
    bool isPressed = false;
    int i = 1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
                isPressed = false;
        }

        window.clear();

        if (menudisplay){
            menu.menuSet(draw, window, isPressed, i, menudisplay);
        }
        else{
            draw.drawPlayerPoint(window, player_point);
            mark = draw.getMark();
            int tmp = index;
            if (first_time_set){
                logic.firstTimeSet();
                first_time_set = false;
            }
            draw.drawFirstThings(window);
            key = "";
            draw.drawPlayGround(window, tiles_amt);
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                check = true;
            }
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
            logic.setupTilesAmt(mark, tmp, key, tiles_amt, player_point);
            draw.drawPlayerPoint(window, player_point);
        }
        window.display();
    }
}