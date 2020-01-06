//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_CLUES_H
#define KATANA_CLUES_H

#include <vector>

/**
 * A class that holds information about clues. It holds them in the inwards direction, meaning that for a
 * row clue, index 0 is the clue that is the most left and for the column clue index 0 is the clue that is at the top.
 *
 * This object also holds information about the crossed-state of each clue.
 */
class Clues {
public:
    /**
     * @param clues A vector of clues from outside to the inside. For example in a row clue the clues are in the order from left to right
     */
    explicit Clues(const std::vector<int> &clues);

    inline Clues() = default;

    int getClueAt(int index) const;

    bool getClueCrossedAt(int index) const;

    void setClueCrossedAt(int index, bool crossed);

    void setClueAt(int index, int clue);

    int getClueCount() const;

    const std::vector<std::pair<int, bool>> * getRef() const;

    /**
     * Adds clue to the right of the clues array
     */
    void addClue(int clue);

    // TODO: Implement serialization/deserialization for the saving/loading

private:
    std::vector<std::pair<int, bool>> clues;
};

#endif //KATANA_CLUES_H
