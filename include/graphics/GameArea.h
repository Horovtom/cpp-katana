//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_GAMEAREA_H
#define KATANA_GAMEAREA_H


#include <game/GridField.h>
#include <gtkmm/drawingarea.h>

#define COLOR_WHITE 1.0, 1.0, 1.0
#define COLOR_BLACK 0.0, 0.0, 0.0
#define EMPTY_TILE_COLOR 0.0, 0.0, 0.0, 0.1

class GameArea : public Gtk::DrawingArea {
public:
    GameArea();

    virtual ~GameArea();

    void setGameData(const std::vector<std::vector<GridField>> &grid,
                     const std::vector<const std::vector<std::pair<int, bool>> *> &leftClues,
                     const std::vector<const std::vector<std::pair<int, bool>> *> &topClues);

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

private:
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height);

    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, const std::string &text, int fontSize = 0);

    const int SIDE_OFFSET = 5;
    const int TEXT_HEIGHT = 15;
    const int CELL_SIZE = 26;
    const int CELL_PADDING = 3;
    const float TILE_ALPHA = 0.7;

    /**
     * Draws a number to selected coordinates
     * @param x Top left corner of the number
     * @param y Top left corner of the number
     * @param maxSize Maximal size of the square this number has to be drawn into
     * @param centeredX Whether the passed-in X coordinate is the center of the square
     * @param centeredY Whether the passed-in Y coordinate is the center of the square
     */
    void drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize, bool centeredX,
                    bool centeredY);

    const std::vector<std::vector<GridField>> *gridReference{};
    std::vector<const std::vector<std::pair<int, bool>> *> leftCluesReference, topCluesReference;

    void drawTopClues(const Cairo::RefPtr<Cairo::Context> &ptr);

    void drawLeftClues(const Cairo::RefPtr<Cairo::Context> &cr);

    void drawGrid(const Cairo::RefPtr<Cairo::Context> &cr);

    int leftMaxClues, topMaxClues;
};


#endif //KATANA_GAMEAREA_H
