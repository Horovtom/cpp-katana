//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_GAME_H
#define KATANA_GAME_H

#include <string>
#include <game/logic/Clues.h>
#include "Grid.h"

class Game {
public:
    /**
     * Constructor that loads a <b>new</b> game from image file
     * @param file Path to a file with saved Katana image.
     */
    explicit Game(std::string file);

    // TODO:
//    /**
//     * Constructor that is used for creating new images
//     * @param width Width of the grid
//     * @param height Height of the grid
//     */
//    Game(int width, int height);

    // TODO: Consider adding saved-game-state constructor.

    ~Game();


    int getWidth();

    int getHeight();

    const std::vector<const std::vector<std::pair<int, bool>> *> getLeftCluesReference() const;

    const std::vector<const std::vector<std::pair<int, bool>> *> getTopCluesReference() const;

    const std::vector<std::vector<GridField>> &getGridReference() const;

    void addClue();

private:
    std::vector<Clues> leftClues, topClues;
    Grid *grid;
    int width, height;

};

#endif //KATANA_GAME_H
