//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_OBJECTMANAGER_H
#define KATANA_OBJECTMANAGER_H


#include "LogicManager.h"
#include "GridGraphicsObject.h"
#include "CluesGraphicsObject.h"
#include "UIGraphicsObject.h"

class ObjectManager {
private:
    LogicManager *logicManager;
    GridGraphicsObject *grid = nullptr;
    CluesGraphicsObject *clues = nullptr;
    UIGraphicsObject *ui = nullptr;
public:
    explicit ObjectManager(LogicManager *l);

    void createGameObjects(int x, int y);

    void createUIObjects(int x, int y);

    void update();

    void freeResources();

    ~ObjectManager();
};


#endif //KATANA_OBJECTMANAGER_H
