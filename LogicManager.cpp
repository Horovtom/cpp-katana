//
// Created by lactosis on 26.7.18.
//

#include "LogicManager.h"

void LogicManager::update() {
//TODO: IMPLEMENT
}

LogicManager::LogicManager() {
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
}
