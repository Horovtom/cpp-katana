//
// Created by lactosis on 24.7.18.
//

#ifndef KATANA_LEGEND_H
#define KATANA_LEGEND_H


#include <vector>

class Legend {
private:

    unsigned int width, height, topMaxHeight = 0, leftMaxWidth = 0;
    /**
     * Ordered from left to right, from top to bottom
     */
    std::vector<std::vector<unsigned int>> topLegend;

    /**
     * Ordered from top to bottom, from left to right
     */
    std::vector<std::vector<unsigned int>> leftLegend;

    /**
     * Ordered from left to right, from top to bottom
     */
    std::vector<std::vector<bool>> topLegendDone;

    /**
     * Ordered from top to bottom, from left to right
     */
    std::vector<std::vector<bool>> leftLegendDone;

    /**
     * Updates the topMaxHeight value by parameter value
     * @param size New height of column to be considered as maximum
     */
    void updateTopMax(unsigned long size);

    /**
     * Updates the leftMaxWidth value by parameter value
     * @param size  New width of row to be considered as maximum
     */
    void updateLeftMax(unsigned long size);

public:
    Legend(unsigned int width, unsigned int height);

    /**
     * This will set (overwrite) specified clue in column to value. It will trim the Legend to the right place.
     */
    void setTopLegend(unsigned int col, unsigned int rowInCol, unsigned int val);

    /**
     * This will set (overwrite) specified clue in row to specified value. It will trim the Legend to the right place.
     */
    void setLeftLegend(unsigned int row, unsigned int colInRow, unsigned int val);

    /**
     * This will push value into specified column in top legend. This means the value will be at the most bottom place in the column.
     */
    void pushTopLegend(unsigned int col, unsigned int val);

    /**
     * This will push value into specified row in left legend. This means the value will be at the most right place in the row.
     */
    void pushLeftLegend(unsigned int row, unsigned int val);

    /**
     * This will insert a value at specified position (not overwriting), shifting values so that it fits.
     */
    void insertTopLegend(unsigned int col, unsigned int rowInCol, unsigned int val);

    /**
     * This will insert a value at specified position (not overwriting), shifting values so that it fits.
     */
    void insertLeftLegend(unsigned int row, unsigned int colInRow, unsigned int val);

    unsigned int getWidth() { return width; }

    unsigned int getHeight() { return height; }

    /**
     * This will return number of clues in specified col.
     */
    unsigned int getTopColLength(unsigned int col);

    /**
     * This will return number of clues in specified row.
     */
    unsigned int getLeftRowLength(unsigned int row);

    const std::vector<unsigned int> getTopClues(unsigned int column);
    const std::vector<unsigned int> getLeftClues(unsigned int row);

    unsigned int getTopHeight();

    unsigned int getLeftHeight();

    unsigned int getTopWidth();

    unsigned int getLeftWidth();

    std::vector<bool> getTopCluesDone(unsigned int col);

    std::vector<bool> getLeftCluesDone(unsigned int row);

    void setTopClueDone(unsigned int row, unsigned int col, bool value);

    void setLeftClueDone(unsigned int row, unsigned int col, bool value);

    /**
     * This will switch topLegendDone on specified cell
     * @param x Column number numbered from left to right
     * @param y Row number numbered from bottom to top
     */
    void switchTopClueDoneInverse(unsigned int row, unsigned int col);

    /**
     * This will switch leftLegendDone on specified cell
     * @param x Row number numbered from right to left
     * @param y Column number numbered from top to bottom
     */
    void switchLeftClueDoneInverse(unsigned int row, unsigned int col);
};


#endif //KATANA_LEGEND_H
