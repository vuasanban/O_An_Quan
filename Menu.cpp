//
// Created by DELL on 11/11/2020.
//

#include "Menu.h"

Menu::Menu() {}

Menu::~Menu() {}


//Menu::Menu() {
//}

void Menu::menuSet(Draw &draw, RenderWindow& window, bool &isPressed, int &i, bool &menudisplay){
    if (mainmenu){
        if (Keyboard::isKeyPressed(Keyboard::Down) && !isPressed){
            isPressed = true;
            if (i < 3) i++;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up) && !isPressed){
            isPressed = true;
            if (i > 1) i--;
        }
        draw.drawMenu(window, i);
        if (Keyboard::isKeyPressed(Keyboard::Return) && !isPressed && i == 1){
            menudisplay = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Return) && !isPressed && i == 2){
            mainmenu = false;
            about = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Return) && !isPressed && i == 3){
            window.close();
        }
    }
    else if (about){
        draw.drawAbout(window);
        if (Keyboard::isKeyPressed(Keyboard::Escape) && !isPressed){
            mainmenu = true;
            about = false;
        }
    }
}
