//
// Created by lactosis on 26.7.18.
//

#include "ObjectManager.h"

ObjectManager::ObjectManager(LogicManager *l, SDL_Renderer *renderer) {
    this->logicManager = l;
    this->renderer = renderer;
    createGameObjects(5, 5);
}

ObjectManager::~ObjectManager() {
    freeResources();
}

void ObjectManager::freeResources() {
    logicManager = nullptr;

    if (grid != nullptr) {
        grid->freeResources();
        grid = nullptr;
    }

    if (clues != nullptr) {
        clues->freeResources();
        clues = nullptr;
    }

    if (ui != nullptr) {
        ui->freeResources();
        ui = nullptr;
    }
}

void ObjectManager::createGameObjects(int x, int y) {
    clues = new CluesGraphicsObject(x, y, logicManager, renderer);
    Coordinate innerPoint = clues->getInnerPoint();
    grid = new GridGraphicsObject(innerPoint.x, innerPoint.y, logicManager);
}

void ObjectManager::createUIObjects(int x, int y) {
    ui = new UIGraphicsObject(x,y,logicManager);
}

void ObjectManager::update() {
    grid->updateInput();
    clues->updateInput();
    ui->updateInput();

    grid->updateOutput();
    clues->updateOutput();
    ui->updateOuptut();
}
