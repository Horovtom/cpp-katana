//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_CONTROLLER_H
#define KATANA_CONTROLLER_H

#include <game/logic/Game.h>
#include <graphics/GameWindow.h>

class Controller {
public:
    Controller(Game *pGame, GameWindow *pWindow);

    void onUserAction();

    void update();

    void restartPressed();

    void spacePressed();

private:
    Game *game;
    GameWindow *window;

    void updateTopClues();
};


#endif //KATANA_CONTROLLER_H
