//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LOGICMANAGER_H
#define KATANA_LOGICMANAGER_H


#include "Legend.h"
#include "Grid.h"

class LogicManager {
private:
    Legend *legend;
    Grid *grid;

public:
    LogicManager();

    bool Update();

    void update();

    Legend *getCluesRef();

    Grid *getGridRef();

    ~LogicManager();

    void createSampleLegend();

    void createSampleGrid();
};


#endif //KATANA_LOGICMANAGER_H
