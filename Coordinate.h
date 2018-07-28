//
// Created by hermes235 on 28.7.18.
//

#ifndef KATANA_COORDINATE_H
#define KATANA_COORDINATE_H


class Coordinate {
public:
    Coordinate() = default;

    Coordinate(int x, int y) : x(x), y(y) {}

    int x = 0;
    int y = 0;
};


#endif //KATANA_COORDINATE_H
