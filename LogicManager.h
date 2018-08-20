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

    /**
     * This will switch celltype on specified coorinates
     */
    void cycleCellType(int x, int y);

    /**
     * This will switch topLegendDone on specified cell
     * @param col Column number numbered from left to right
     * @param row Row number numbered from bottom to top
     */
    void switchTopClueDoneInverse(int col, int row);

    /**
     * This will switch leftLegendDone on specified cell
     * @param row Row number numbered from right to left
     * @param col Column number numbered from top to bottom
     */
    void switchLeftClueDoneInverse(int col, int row);
};


#endif //KATANA_LOGICMANAGER_H
