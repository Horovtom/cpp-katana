#include <utility>

#include <iostream>
#include <graphics/GameArea.h>

GameArea::GameArea() {
}

GameArea::~GameArea() {
}

bool GameArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {

    Gtk::Allocation allocation = get_allocation();
    // Minus padding on the right:
    int width = allocation.get_width();
    int height = allocation.get_height();


    // Draw background
    cr->set_source_rgb(COLOR_WHITE);
    draw_rectangle(cr, 0, 0, width, height);

    cr->translate(SIDE_OFFSET, SIDE_OFFSET);
    width -= 2 * SIDE_OFFSET;
    height -= 2 * SIDE_OFFSET;

    // Draw top clues
    int leftOffset = leftMaxClues * (CELL_SIZE + CELL_PADDING);
    cr->translate(leftOffset, 0);
    drawTopClues(cr);
    // Draw left clues
    int topOffset = topMaxClues * (CELL_SIZE + CELL_PADDING);
    cr->translate(-leftOffset, topOffset);
    drawLeftClues(cr);
    // Draw grid
    cr->translate(leftOffset, 0);
    drawGrid(cr);


//
//    // Draw score text
//    cr->set_source_rgb(COLOR_BLACK);
//    draw_text(cr, 0, 0, "AHOJ");
    return true;
}

void GameArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr,
                              int x, int y, int width, int height) {
    cr->rectangle(x, y, width, height);
    cr->fill();
}

void GameArea::draw_text(const Cairo::RefPtr<Cairo::Context> &cr,
                         int x, int y, const std::string &t, int fontSize) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    if (fontSize != 0) {
        font.set_absolute_size(fontSize * Pango::SCALE);
    }

    auto layout = create_pango_layout(t);

    layout->set_font_description(font);


    // Position the text in the middle
    cr->move_to(x, y);

    layout->show_in_cairo_context(cr);
}

void GameArea::drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize,
                          bool centeredX = false, bool centeredY = false) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_absolute_size((maxSize / 2) * Pango::SCALE);

    auto layout = create_pango_layout(std::to_string(number));
    layout->set_font_description(font);

    //get the text dimensions (it updates the variables -- by reference)
    if (centeredX || centeredY) {
        int textWidth;
        int textHeight;

        layout->get_pixel_size(textWidth, textHeight);

        if (centeredX) x -= textWidth / 2;
        if (centeredY) y -= textHeight / 2;
        // Position the text in the middle
    }
    cr->move_to(x, y);
    layout->show_in_cairo_context(cr);
}

void GameArea::setGameData(const std::vector<std::vector<GridField>> &grid,
                           const std::vector<const std::vector<std::pair<int, bool>> *> &leftClues,
                           const std::vector<const std::vector<std::pair<int, bool>> *> &topClues) {
    this->gridReference = &grid;
    this->leftCluesReference = leftClues;
    this->topCluesReference = topClues;
    topMaxClues = 0;
    for (auto i : topClues) {
        if (topMaxClues < i->size()) topMaxClues = i->size();
    }
    leftMaxClues = 0;
    for (auto i : leftClues)
        if (leftMaxClues < i->size()) leftMaxClues = i->size();

}

void GameArea::drawTopClues(const Cairo::RefPtr<Cairo::Context> &cr) {
    for (int i = 0, x = 0; i < topCluesReference.size(); ++i, x += CELL_SIZE + CELL_PADDING) {
        for (int j = topCluesReference.at(i)->size() - 1, y = (topMaxClues - 1) * (CELL_SIZE + CELL_PADDING);
             j >= 0; --j, y -= CELL_SIZE + CELL_PADDING) {
            cr->set_source_rgba(EMPTY_TILE_COLOR);
            draw_rectangle(cr, x, y, CELL_SIZE, CELL_SIZE);
            cr->set_source_rgb(COLOR_BLACK);
            drawNumber(cr,
                       topCluesReference.at(i)->at(j).first,
                       x + CELL_PADDING, y + CELL_PADDING, CELL_SIZE);
            if (topCluesReference.at(i)->at(j).second) {
                // TODO: CROSS IT!
            }
        }
    }
}

void GameArea::drawLeftClues(const Cairo::RefPtr<Cairo::Context> &cr) {
    for (int i = 0, y = 0; i < leftCluesReference.size(); ++i, y += CELL_SIZE + CELL_PADDING) {
        for (int j = leftCluesReference.at(i)->size() - 1, x = (leftMaxClues - 1) * (CELL_SIZE + CELL_PADDING);
             j >= 0; --j, x -= CELL_SIZE + CELL_PADDING) {
            cr->set_source_rgba(EMPTY_TILE_COLOR);
            draw_rectangle(cr, x, y, CELL_SIZE, CELL_SIZE);
            cr->set_source_rgb(COLOR_BLACK);
            drawNumber(cr,
                       leftCluesReference.at(i)->at(j).first,
                       x + CELL_PADDING, y + CELL_PADDING, CELL_SIZE);
            if (leftCluesReference.at(i)->at(j).second) {
                // TODO: CROSS IT!
            }
        }
    }
}

void GameArea::drawGrid(const Cairo::RefPtr<Cairo::Context> &cr) {
    draw_rectangle(cr, 0, 0, 500, 500);
}
