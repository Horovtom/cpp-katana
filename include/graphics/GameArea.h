//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_GAMEAREA_H
#define KATANA_GAMEAREA_H


#include <gtkmm/drawingarea.h>

#define COLOR_WHITE 1.0, 1.0, 1.0
#define COLOR_BLACK 0.0, 0.0, 0.0
#define EMPTY_TILE_COLOR 0.0, 0.0, 0.0, 0.1

class GameArea : public Gtk::DrawingArea {
public:
    GameArea();

    virtual ~GameArea();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

private:
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height);

    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, const std::string &text, int fontSize = 0);

    const int SIDE_OFFSET = 5;
    const int TEXT_HEIGHT = 15;
    const int CELL_PADDING = 3;
    const float TILE_ALPHA = 0.7;

    void drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize);
};


#endif //KATANA_GAMEAREA_H
