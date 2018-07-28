//
// Created by lactosis on 24.7.18.
//

#include "Legend.h"
#include <cmath>

Legend::Legend(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    for (int i = 0; i < width; ++i) {
        std::vector<unsigned  int> col;
        topLegend.emplace_back(col);
        std::vector<bool> colDone;
        topLegendDone.emplace_back(colDone);
    }

    for (int j = 0; j < height; ++j) {
        std::vector<unsigned int> row;
        leftLegend.emplace_back(row);
        std::vector<bool> rowDone;
        leftLegendDone.emplace_back(rowDone);
    }
}

void Legend::setTopLegend(unsigned int col, unsigned int rowInCol, unsigned int val) {
    std::vector<unsigned int> *clues = &topLegend.at(col);
    if ((*clues).size() <= rowInCol) {
        (*clues).emplace_back(val);
        updateTopMax((*clues).size());
    } else {
        (*clues).at(rowInCol) = val;
    }
}

void Legend::setLeftLegend(unsigned int row, unsigned int colInRow, unsigned int val) {
    std::vector<unsigned int> *clues = &leftLegend.at(row);
    if ((*clues).size() <= colInRow) {
        (*clues).emplace_back(val);
        updateLeftMax((*clues).size());
    } else {
        (*clues).at(colInRow) = val;
    }

}

void Legend::pushTopLegend(unsigned int col, unsigned int val) {
    topLegend.at(col).emplace_back(val);
    updateTopMax(topLegend.at(col).size());
}

void Legend::pushLeftLegend(unsigned int row, unsigned int val) {
    leftLegend.at(row).emplace_back(val);
    updateLeftMax(leftLegend.at(row).size());
}

unsigned int Legend::getTopColLength(unsigned int col) {
    return static_cast<unsigned int>(topLegend.at(col).size());
}

unsigned int Legend::getLeftRowLength(unsigned int row) {
    return static_cast<unsigned int>(leftLegend.at(row).size());
}

void Legend::insertTopLegend(unsigned int col, unsigned int rowInCol, unsigned int val) {
    auto it = topLegend.at(col).begin();
    it += rowInCol;

    topLegend.at(col).emplace(it, val);
    updateTopMax(topLegend.at(col).size());
}

void Legend::insertLeftLegend(unsigned int row, unsigned int colInRow, unsigned int val) {
    auto it = leftLegend.at(row).begin();
    it += colInRow;

    leftLegend.at(row).emplace(it, val);
    updateLeftMax(leftLegend.at(row).size());
}

const std::vector<unsigned int> Legend::getTopClues(unsigned int column) {
    return topLegend.at(column);
}

const std::vector<unsigned int> Legend::getLeftClues(unsigned int row) {
    return leftLegend.at(row);
}

unsigned int Legend::getTopHeight() {
    return topMaxHeight;
}

unsigned int Legend::getLeftWidth() {
    return leftMaxWidth;
}

void Legend::updateTopMax(unsigned long size) {
    if (topMaxHeight < size) topMaxHeight = static_cast<unsigned int>(size);
}

void Legend::updateLeftMax(unsigned long size) {
    if (leftMaxWidth < size) leftMaxWidth = static_cast<unsigned int>(size);
}

unsigned int Legend::getLeftHeight() {
    return height;
}

unsigned int Legend::getTopWidth() {
    return width;
}

std::vector<bool> Legend::getTopCluesDone(unsigned int col) {
    return topLegendDone.at(col);
}

std::vector<bool> Legend::getLeftCluesDone(unsigned int row) {
    return leftLegendDone.at(row);
}


