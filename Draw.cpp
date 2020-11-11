//
// Created by DELL on 10/23/2020.
//

#include "Draw.h"

Draw::Draw() {}

Draw::~Draw() {}

Draw::Draw(vector < pair<float,float> > tiles_pos, vector <Texture> t_map_list, vector <Sprite> map_list,
           Texture t_cursor, Texture t_background, Texture t_soil
        , Texture t_arrow, Texture t_grass, Sprite cursor, Sprite background, Sprite soil, Sprite arrow, Sprite grass,
           RectangleShape picked_player, Font font, Text player1, Text player2, Text player1_point,
           Text player2_point, RectangleShape menubackground, Text header, Text play, Text about, Text out, int mark) {
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
    this->t_grass = t_grass;
    this->grass = grass;
    this->font = font;
    this->player1 = player1;
    this->player2 = player2;
    this->player1_point = player1_point;
    this->player2_point = player2_point;
    this->menubackground = menubackground;
    this->header = header;
    this->play = play;
    this->about = about;
    this->out = out;
    this->mark = mark;
}

void Draw::setTilesPosition() {
    pair <float,float> tmp;
//    tmp.first = 0;
//    tmp.second = 0;
//    tiles_pos.push_back(tmp);
    tmp.first = 150.0f;
    tmp.second = 150.0f;
    while (tmp.first <= 560){
        tiles_pos.push_back(tmp);
        tmp.first += 80.0f;
    }
}

void Draw::loadThings() {
    t_cursor.loadFromFile("../img/cursor.png");
    t_background.loadFromFile("../img/background.png");
    t_soil.loadFromFile("../img/map/map5.png");
    t_arrow.loadFromFile("../img/arrow.png");
    t_map_list.resize(33);
    t_grass.loadFromFile("../img/grass.png");
    t_map_list[1].loadFromFile("../img/map/map1.png");
    t_map_list[2].loadFromFile("../img/map/map2.png");
    t_map_list[3].loadFromFile("../img/map/map3.png");
    t_map_list[4].loadFromFile("../img/map/map4.png");
    t_map_list[5].loadFromFile("../img/map/map5.png");
    t_map_list[6].loadFromFile("../img/map/map6.png");
    t_map_list[7].loadFromFile("../img/map/map7.png");
    t_map_list[8].loadFromFile("../img/map/map8.png");
    t_map_list[9].loadFromFile("../img/map/map9.png");
    t_map_list[10].loadFromFile("../img/map/map10.png");
    t_map_list[11].loadFromFile("../img/map/map11.png");
    t_map_list[12].loadFromFile("../img/map/map12.png");
    t_map_list[13].loadFromFile("../img/map/map13.png");
    t_map_list[14].loadFromFile("../img/map/map14.png");
    t_map_list[15].loadFromFile("../img/map/map15.png");
    t_map_list[16].loadFromFile("../img/map/map16.png");
    t_map_list[17].loadFromFile("../img/map/map17.png");
    t_map_list[18].loadFromFile("../img/map/map18.png");
    t_map_list[19].loadFromFile("../img/map/map19.png");
    t_map_list[20].loadFromFile("../img/map/map20.png");
    t_map_list[21].loadFromFile("../img/map/map21.png");
    t_map_list[22].loadFromFile("../img/map/map22.png");
    t_map_list[23].loadFromFile("../img/map/map23.png");
    t_map_list[24].loadFromFile("../img/map/map24.png");
    t_map_list[25].loadFromFile("../img/map/map25.png");
    t_map_list[26].loadFromFile("../img/map/map26.png");
    t_map_list[27].loadFromFile("../img/map/map27.png");
    t_map_list[28].loadFromFile("../img/map/map28.png");
    t_map_list[29].loadFromFile("../img/map/map29.png");
    t_map_list[30].loadFromFile("../img/map/map30.png");
    t_map_list[31].loadFromFile("../img/map/map31.png");
    t_map_list[32].loadFromFile("../img/map/source.png");
    font.loadFromFile("../font/ARCADECLASSIC.TTF");

    cursor.setTexture(t_cursor);
    background.setTexture(t_background);
    soil.setTexture(t_soil);
    arrow.setTexture(t_arrow);
    grass.setTexture(t_grass);
    map_list.resize(33);
    for (int i = 1; i <= 32; i++){
        map_list[i].setTexture(t_map_list[i]);
    }

    player1.setFont(font);
    player2.setFont(font);
}

void Draw::drawFirstThings(RenderWindow& window) {
    window.draw(background);
}

void Draw::drawPlayGround(RenderWindow &window, vector <int> &tiles_amt) {
    for (int i = 1; i <= 12; i++) {
        drawSoil(window, tiles_amt[i], i);
//        cout << "Soi o: " << i << " " << tiles_amt[i] << "\n";
    }
}

void Draw::drawSoil(RenderWindow &window, int amt, int i) {
    if (i >= 1 && i <= 5){
        map_list[amt].setPosition(tiles_pos[i-1].first+10.0f, tiles_pos[i-1].second+10.0f);
        grass.setPosition(tiles_pos[i-1].first+10.0f, tiles_pos[i-1].second+10.0f);
    }
    else if (i >= 7 && i <= 11){
        map_list[amt].setPosition(tiles_pos[11-i].first+10.0f, tiles_pos[11-i].second+90.0f);
        grass.setPosition(tiles_pos[11-i].first+10.0f, tiles_pos[11-i].second+90.0f);
    }
    else if (i == 12){
        map_list[amt].setPosition(60.0f, 200.0f);
    }
    else{
        map_list[amt].setPosition(580.0f, 200.0f);
    }
//    window.draw(grass);
    window.draw(map_list[amt]);
}

void Draw::drawFirstCursor(RenderWindow& window, int &index) {
    if (index == 1) cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second);
    else cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second + 80.0f);

    window.draw(cursor);
}

void Draw::drawCursor(RenderWindow &window, int &index) {
    float tmp = 0;
    if (index == 2) tmp = 80.0f;
    if (Mouse::isButtonPressed(Mouse::Left)){
        Vector2i mousePos = Mouse::getPosition(window);
        for (int i = 0; i < tiles_pos.size(); i++) {
            if ((float) mousePos.x < tiles_pos[i].first) {
                mark = i-1;
                if (mark == -1) mark = 0;
                break;
            }
        }
        cursor.setPosition(tiles_pos[mark].first, tiles_pos[mark].second+tmp);
    }
    window.draw(cursor);
}

void Draw::adjustPickedPlayer() {
    picked_player.setSize(Vector2f(280.0f, 62.0f));
    picked_player.setOutlineThickness(3);
    picked_player.setOutlineColor(Color::Red);
    picked_player.setFillColor(Color::Transparent);
}

void Draw::setUpFont(Text &text) {
    text.setFont(font);
    text.setFillColor(Color::Black);
}

string Draw::changeNumToString(int num) {
    string s = "";
    if (num == 0) return "0";
    while (num > 0){
        char c = num % 10 + '0';
        s = c + s;
        num /= 10;
    }

    return s;
}

void Draw::drawPickedPlayer(RenderWindow& window, int &index) {
    adjustPickedPlayer();
    if (index == 1) picked_player.setPosition(40.0f, 29.0f);
    else picked_player.setPosition(400.0f, 389.0f);
    window.draw(picked_player);
}

void Draw::drawPlayerPoint(RenderWindow &window, vector <int> &player_point) {
    player1.setFillColor(Color::Red);
    player1.setPosition(50.0f, 40.0f);
    player1.setString("Player 1");
    window.draw(player1);

    player2.setFillColor(Color::Red);
    player2.setPosition(540.0f, 400.0f);
    player2.setString("Player 2");
    window.draw(player2);

    setUpFont(player1_point);
    player1_point.setPosition(250.0f, 40.0f);
    player1_point.setString(changeNumToString(player_point[1]));
    window.draw(player1_point);

    setUpFont(player2_point);
    player2_point.setPosition(410.0f, 400.0f);
    player2_point.setString(changeNumToString(player_point[2]));
    window.draw(player2_point);
}

void Draw::drawArrow(RenderWindow& window, int &index) {
    if (index == 1) arrow.setPosition(tiles_pos[mark].first, tiles_pos[mark].second);
    else arrow.setPosition(tiles_pos[mark].first, tiles_pos[mark].second + 80.0f);
    window.draw(arrow);
}

void Draw::drawWhiteTile(RenderWindow &window, int &index) {
    RectangleShape white_tile;
    white_tile.setSize(Vector2f(80.0f, 80.0f));
    if (index == 1) white_tile.setPosition(tiles_pos[mark].first+10.0f, tiles_pos[mark].second + 10.0f);
    else white_tile.setPosition(tiles_pos[mark].first+10.0f, tiles_pos[mark].second + 90.0f);

    window.draw(white_tile);
}

void Draw::setup() {
    setTilesPosition();
    loadThings();
}

int Draw::getMark() {
    return mark;
}

void Draw::drawMenu(RenderWindow &window, int i) {
    menubackground.setFillColor(Color::White);
    menubackground.setSize(Vector2f (720.0f, 480.0f));
    menubackground.setPosition(0.0f, 0.0f);
    window.draw(menubackground);

    setUpFont(header);
    header.setFillColor(Color(0, 153, 0));
    header.setString("O   An   Quan");
    header.setCharacterSize(90);
    header.setPosition(150.0f, 50.0f);
    window.draw(header);

    setUpFont(play);
    if (i == 1) play.setFillColor(Color::Red);
    else play.setFillColor(Color::Black);
    play.setString("Play");
    play.setPosition(500.0f, 200.0f);
    window.draw(play);

    setUpFont(about);
    if (i == 2) about.setFillColor(Color::Red);
    else about.setFillColor(Color::Black);
    about.setString("About");
    about.setPosition(500.0f, 230.0f);
    window.draw(about);

    setUpFont(out);
    if (i == 3) out.setFillColor(Color::Red);
    else out.setFillColor(Color::Black);
    out.setString("Exit");
    out.setPosition(500.0f, 260.0f);
    window.draw(out);
}

void Draw::drawAbout(RenderWindow &window) {
    window.draw(menubackground);
    about.setFillColor(Color(255, 80, 80));
    about.setString("From    Minh    Xuan    Le    with    Luv");
    about.setPosition(130.0f, 200.0f);
    window.draw(about);

    about.setFillColor(Color::Black);
    about.setString("Nhan    ESC    de    tro    ve    Menu");
    about.setPosition(400.0f, 400.0f);
    window.draw(about);
}