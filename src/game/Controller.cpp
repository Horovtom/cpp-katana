//
// Created by lactosis on 6.1.20.
//

#include <game/Controller.h>
#include <iostream>

Controller::Controller(Game *g, GameWindow *w) {
    window = w;
    game = g;
    w->registerController(this);
    window->setGameData(game->getGridReference(), game->getLeftCluesReference(), game->getTopCluesReference());
}

void Controller::update() {
    // TODO:

}

void Controller::onUserAction() {
    // TODO:

}

void Controller::spacePressed() {
    // TODO:
    std::cout << "Space PRESSED" << std::endl;
    game->addClue();
}
