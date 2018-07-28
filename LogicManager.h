//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LOGICMANAGER_H
#define KATANA_LOGICMANAGER_H


#include "Legend.h"

class LogicManager {
private:
    Legend *legend;

public:
    LogicManager();

    bool Update();

    void update();

    Legend *getCluesRef();

    ~LogicManager();
};


#endif //KATANA_LOGICMANAGER_H
