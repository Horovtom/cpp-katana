//
// Created by lactosis on 26.7.18.
//

#include "ObjectManager.h"

ObjectManager::ObjectManager(LogicManager *l, SDL_Renderer *renderer) {
    this->logicManager = l;
    this->renderer = renderer;
    createGameObjects(5, 5);

    Coordinate c = clues->getLowerLeftCorner();
    createUIObjects(c.x, c.y + 10);
}

ObjectManager::~ObjectManager() {
    freeResources();
}

void ObjectManager::freeResources() {
    logicManager = nullptr;

    if (grid != nullptr) {
        //grid->freeResources();
        delete grid;
        grid = nullptr;
    }

    if (clues != nullptr) {
        //clues->freeResources();
        delete clues;
        clues = nullptr;
    }

    if (ui != nullptr) {
        //ui->freeResources();
        delete ui;
        ui = nullptr;
    }
}

void ObjectManager::createGameObjects(int x, int y) {
    clues = new CluesGraphicsObject(x, y, logicManager, renderer);
    innerPoint = clues->getInnerPoint();
    grid = new GridGraphicsObject(innerPoint.x, innerPoint.y, logicManager, renderer);
}

void ObjectManager::createUIObjects(int x, int y) {
    ui = new UIGraphicsObject(x, y, logicManager, renderer, 200);
}

void ObjectManager::update() {
    grid->updateInput();
    clues->updateInput();
    ui->updateInput();

    grid->updateOutput();
    clues->updateOutput();
    ui->updateOuptut();
}

void ObjectManager::mouseDown(int x, int y) {
    if (ui->mouseDown(x, y)) return;
    if (grid->mouseDown(x, y)) return;
    if (clues->mouseDown(x, y)) return;

}
