//
// Created by lactosis on 26.7.18.
//

#include "LogicManager.h"

void LogicManager::update() {
//TODO: IMPLEMENT
}

LogicManager::LogicManager() {
    createSampleLegend();
    createSampleGrid();


    //TODO: IMPLEMENT
}

bool LogicManager::Update() {
    //TODO: IMPLEMENT
    return true;
}

Legend *LogicManager::getCluesRef() {
    return legend;
}

LogicManager::~LogicManager() {
    delete legend;
    delete grid;
}

Grid *LogicManager::getGridRef() {
    return grid;
}

void LogicManager::createSampleLegend() {
    legend = new Legend(2, 3);
    legend->pushTopLegend(0, 2);
    legend->pushTopLegend(0, 4);
    legend->pushTopLegend(0, 3);

    legend->pushTopLegend(1, 5);
    legend->pushTopLegend(1, 1);

    legend->pushLeftLegend(0, 3);
    legend->pushLeftLegend(0, 1);
    legend->pushLeftLegend(0, 2);
    legend->pushLeftLegend(0, 4);

    legend->pushLeftLegend(2, 9);
    legend->pushLeftLegend(2, 13);
}

void LogicManager::createSampleGrid() {
    grid = new Grid(2, 3);

    grid->setCell(0, 0, BLACK);
    grid->setCell(0, 1, BLACK);
    grid->setCell(0, 2, CROSS);
    grid->setCell(1, 1, DOT);
}

void LogicManager::cycleCellType(int x, int y) {
    grid->cycleCell(x, y);
}

void LogicManager::switchTopClueDoneInverse(int col, int row) {
    legend->switchTopClueDoneInverse(row, col);
}

void LogicManager::switchLeftClueDoneInverse(int col, int row) {
    legend->switchLeftClueDoneInverse(row, col);
}
