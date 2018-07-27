//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LEGENDGRAPHICSOBJECT_H
#define KATANA_LEGENDGRAPHICSOBJECT_H


#include "LogicManager.h"
#include "ObjectManager.h"

class CluesGraphicsObject {
private:
    LogicManager *logicManager;
public:
    CluesGraphicsObject(int x, int y, LogicManager *l);

    void freeResources();

    ~CluesGraphicsObject();

    Coordinate getInnerPoint();

    void updateInput();

    void updateOutput();
};


#endif //KATANA_LEGENDGRAPHICSOBJECT_H
