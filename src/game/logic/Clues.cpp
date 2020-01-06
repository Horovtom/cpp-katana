//
// Created by lactosis on 6.1.20.
//

#include <game/logic/Clues.h>

Clues::Clues(const std::vector<int> &clues) {
    for (int clue : clues) {
        this->clues.emplace_back(std::make_pair(clue, false));
    }
}

int Clues::getClueAt(int index) const {
    return clues.at(index).first;
}

bool Clues::getClueCrossedAt(int index) const {
    return clues.at(index).second;
}

void Clues::setClueCrossedAt(int index, bool crossed) {
    clues.at(index).second = crossed;
}

void Clues::setClueAt(int index, int clue) {
    clues.at(index).first = clue;
}

int Clues::getClueCount() const {
    return clues.size();
}

void Clues::addClue(int clue) {
    clues.emplace_back(std::make_pair(clue, false));
}

const std::vector<std::pair<int, bool>> *Clues::getRef() const {
    return &clues;
}
