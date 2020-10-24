//
// Created by DELL on 10/23/2020.
//

#include "Draw.h"

Draw::Draw() {}

Draw::~Draw() {}

Draw::Draw(vector < pair<float,float> > tiles_pos, vector <Texture> t_map_list, vector <Sprite> map_list,
           Texture t_cursor, Texture t_background, Texture t_soil
        , Texture t_arrow, Sprite cursor, Sprite background, Sprite soil, Sprite arrow,
           RectangleShape picked_player, int mark) {
    this->tiles_pos = tiles_pos;
    this->t_map_list = t_map_list;
    this->map_list = map_list;
    this->t_cursor = t_cursor;
    this->cursor = cursor;
    this->t_background = t_background;
    this->background = background;
    this->t_soil = t_soil;
    this->soil = soil;
    this->picked_player = picked_player;
    this->t_arrow = t_arrow;
    this->arrow = arrow;
    this->mark = mark;
}

void Draw::setTilesPosition() {
    pair <float,float> tmp;
    tmp.first = 150.0f;
    tmp.second = 150.0f;
    while (tmp.first <= 560){
        tiles_pos.push_back(tmp);
        tmp.first += 80.0f;
    }
}

vector < pair<float,float> > Draw::getTilesPosition() {

    return tiles_pos;
}

void Draw::loadThings() {
    t_cursor.loadFromFile("../img/cursor.png");
    t_background.loadFromFile("../img/background.png");
    t_soil.loadFromFile("../img/map/map/map5.png");
    t_arrow.loadFromFile("../img/arrow.png");
    t_map_list.resize(33);
    for (int i = 1; i <= 32; i++){
        
    }

    cursor.setTexture(t_cursor);
    background.setTexture(t_background);
    soil.setTexture(t_soil);
    arrow.setTexture(t_arrow);
}

void Draw::drawFirstThings(RenderWindow& window) {
    window.draw(background);
    for (int i = 0; i < tiles_pos.size()-1; i++){
        soil.setPosition(tiles_pos[i].first+10, tiles_pos[i].second+10);
        window.draw(soil);
        soil.setPosition(tiles_pos[i].first+10, tiles_pos[i].second+90);
        window.draw(soil);
    }
//    picked_player.setSize(Vector2f(280.0f, 62.0f));
//    picked_player.setOutlineThickness(3);
//    picked_player.setOutlineColor(Color::Red);
//    picked_player.setFillColor(Color::Transparent);
//    picked_player.setPosition(40.0f, 29.0f);
//    window.draw(picked_player);
}

void Draw::drawFirstCursor(RenderWindow& window, int &index) {
    if (index == 1) cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second);
    else cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second + 80.0f);

    window.draw(cursor);
}

Sprite Draw::getBackground() {
    return background;
}

void Draw::drawCursor(RenderWindow &window, int &index) {
    float tmp = 0;
    if (index == 2) tmp = 80.0f;
    if (Mouse::isButtonPressed(Mouse::Left)){
        Vector2i mousePos = Mouse::getPosition(window);
//        int mark = 4;
        for (int i = 0; i < tiles_pos.size(); i++) {
            if ((float) mousePos.x < tiles_pos[i].first) {
                cout << mousePos.x << "\n";
                mark = i - 1;
                if (mark == -1) mark = 0;
                break;
            }
        }
        cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second+tmp);
    }

    window.draw(cursor);
}

void Draw::adjustPickedPlayer() {
//    picked_player.setSize(Vector2f(292.0f, 62.0f));
//    picked_player.setOutlineThickness(3);
//    picked_player.setOutlineColor(Color::Red);
}

void Draw::drawPickedPlayer(RenderWindow& window, int &index) {
    picked_player.setSize(Vector2f(280.0f, 62.0f));
    picked_player.setOutlineThickness(3);
    picked_player.setOutlineColor(Color::Red);
    picked_player.setFillColor(Color::Transparent);
    if (index == 1) picked_player.setPosition(40.0f, 29.0f);
    else picked_player.setPosition(400.0f, 389.0f);
    window.draw(picked_player);
}

void Draw::drawArrow(RenderWindow& window, int &index) {
    if (index == 1) arrow.setPosition(tiles_pos[mark].first, tiles_pos[mark].second);
    else arrow.setPosition(tiles_pos[mark].first, tiles_pos[mark].second + 80.0f);
    window.draw(arrow);
}

void Draw::drawWhiteTile(RenderWindow &window, int &index) {
    RectangleShape white_tile;
    white_tile.setSize(Vector2f(80.0f, 80.0f));
 //   white_tile.setFillColor(Color::Transparent);
    if (index == 1) white_tile.setPosition(tiles_pos[mark].first, tiles_pos[mark].second);
    else white_tile.setPosition(tiles_pos[mark].first, tiles_pos[mark].second + 80.0f);

    window.draw(white_tile);
}

void Draw::setup() {
    setTilesPosition();
    loadThings();
}