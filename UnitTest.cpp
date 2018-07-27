#include <iostream>
#include <cassert>
#include "Grid.h"
#include "Legend.h"

//template<typename Functor>
//bool outOfRangeVector(Functor x) {
//    try {
//        x();
//    } catch(std::out_of_range r) {
//        return true;
//    }
//    return false;
//}

bool testGridFunc() {
    Grid g(2,3);

    g.setCell(0, 0, DOT);
    g.setCell(0, 1, BLACK);
    assert(g.getCell(0,0) == DOT);
    assert(g.getCell(1,0) == BLANK);
    assert(g.getCell(0,1) == BLACK);

    g.setCell(1, 2, DOT);

    assert(g.getCell(1,2) == DOT);
    try {
        g.setCell(3, 4, BLACK);
    } catch (std::out_of_range r) {
     return true;
    }
    return false;
}

bool testLegend1(Legend l) {
    try {
        l.getLeftRowLength(3);
    } catch(std::out_of_range r) {
        try {
            l.getTopColLength(2);
        } catch(std::out_of_range r) {
            return true;
        }
    }
    return false;
}

bool testLegendSet() {
    Legend l(2,3);
    l.setLeftLegend(0, 20, 4);
    assert(l.getLeftRowLength(0) == 1);
    assert(l.getLeftClues(0).size() == 1 && l.getLeftClues(0).at(0) == 4);
    l.setLeftLegend(0,0,1);
    assert(l.getLeftRowLength(0) == 1);
    assert(l.getLeftClues(0).size() == 1 && l.getLeftClues(0).at(0) == 1);
    l.setLeftLegend(0, 12, 12);
    assert(l.getLeftRowLength(0) == 2);
    assert(l.getLeftClues(0).size() == 2 && l.getLeftClues(0).at(1) == 12);
return true;
}

bool testLegendPush() {
    Legend l(2, 3);
    l.pushTopLegend(1, 12);
    assert(l.getTopColLength(1) == 1);
    assert(l.getTopClues(1).at(0) == 12);
    l.pushTopLegend(1, 31);
    assert(l.getTopColLength(1) == 2);
    assert(l.getTopClues(1).at(0) == 12 && l.getTopClues(1).at(1) == 31);
return true;
}

bool testLegendInsert() {
    Legend l(2, 3);
    l.insertTopLegend(0,0,2);
    l.insertTopLegend(0,1,3);
    l.insertTopLegend(0,0,4);
    assert(l.getTopColLength(0) == 3);
    std::vector<unsigned int> a = l.getTopClues(0);
    assert(a.at(0) == 4);
    assert(a.at(1) == 2);
    assert(a.at(2) == 3);

    l.insertTopLegend(0,1,12);
    a = l.getTopClues(0);
    assert(a.at(0) == 4);
    assert(a.at(1) == 12);
    assert(a.at(2) == 2);
    assert(a.at(3) == 3);

    return true;
}

bool testLegendFunc() {
    Legend l(2, 3);
    assert(l.getLeftRowLength(2) == 0);
    assert(l.getTopColLength(1) == 0);
    assert(testLegend1(l));

    assert(testLegendSet());
    assert(testLegendPush());
    assert(testLegendInsert());

}

bool unitTest() {
    assert(testGridFunc());
    assert(testLegendFunc());
    return true;
}

int main() {
    if (!unitTest()) return -1;

    std::cout << "Tests Passed!" << std::endl;
    return 0;
}