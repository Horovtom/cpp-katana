//
// Created by lactosis on 6.1.20.
//

#include <game/logic/Game.h>
#include <fstream>
#include <iostream>
#include <sstream>

Game::Game(std::string file) {
    std::ifstream istr(file);

    if (!istr.is_open()) {
        std::cerr << "File " << file << " could not be loaded!" << std::endl;
        exit(-2);
    }

    std::string line;
    int curr;
    std::getline(istr, line);

    {
        std::istringstream ss(line);
        ss >> width >> height;
    }
    leftClues.resize(height);
    topClues.resize(width);

    for (int i = 0; i < height; ++i) {
        std::getline(istr, line);
        std::istringstream ss(line);
        while (!ss.eof()) {
            ss >> curr;
            leftClues.at(i).addClue(curr);
        }
    }

    for (int i = 0; i < width; ++i) {
        std::getline(istr, line);
        std::istringstream ss(line);
        while (!ss.eof()) {
            ss >> curr;
            topClues.at(i).addClue(curr);
        }
    }

    grid = new Grid(width, height);

    std::cout << "Loaded successfully!" << std::endl;
}

int Game::getWidth() {
    return width;
}

int Game::getHeight() {
    return height;
}

Game::~Game() {
    delete grid;
}

const std::vector<const std::vector<std::pair<int, bool>> *> Game::getTopCluesReference() const {
    std::vector<const std::vector<std::pair<int, bool>> *> ref;
    ref.reserve(width);

    for (const Clues &c: topClues) {
        ref.emplace_back(c.getRef());
    }

    return ref;
}

const std::vector<const std::vector<std::pair<int, bool>> *> Game::getLeftCluesReference() const {
    std::vector<const std::vector<std::pair<int, bool>> *> ref;
    ref.reserve(width);

    for (const Clues &c: leftClues) {
        ref.emplace_back(c.getRef());
    }

    return ref;
}

const std::vector<std::vector<GridField>> &Game::getGridReference() const {
    return grid->getRef();
}

void Game::addClue() {
    // TODO: JUST FOR TESTING!
    leftClues.at(1).addClue(12);
}

