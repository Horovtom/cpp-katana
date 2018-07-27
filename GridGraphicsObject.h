//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_GRIDGRAPHICSOBJECT_H
#define KATANA_GRIDGRAPHICSOBJECT_H


#include "LogicManager.h"

class GridGraphicsObject {
private:

public:
    GridGraphicsObject(int x, int y, LogicManager *l);

    void freeResources();
    ~GridGraphicsObject();

    void updateInput();

    void updateOutput();
};


#endif //KATANA_GRIDGRAPHICSOBJECT_H
