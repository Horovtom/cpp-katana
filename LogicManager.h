//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LOGICMANAGER_H
#define KATANA_LOGICMANAGER_H


class LogicManager {
private:


public:
    LogicManager() = default;
    LogicManager(int w, int h);

    bool Update();

    void update();
};


#endif //KATANA_LOGICMANAGER_H
