//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_UIGRAPHICSOBJECT_H
#define KATANA_UIGRAPHICSOBJECT_H


#include "LogicManager.h"

class UIGraphicsObject {
private:

public:
    UIGraphicsObject(int x, int y, LogicManager *l);

    void freeResources();
    ~UIGraphicsObject();

    void updateInput();

    void updateOuptut();
};


#endif //KATANA_UIGRAPHICSOBJECT_H
