#include <utility>

#include <utility>

#include <iostream>
#include "graphics/GameArea.h"

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

    // Draw score text
    cr->set_source_rgb(COLOR_BLACK);
    draw_text(cr, 0, 0, "AHOJ");

    // Move to the location of the grid
    cr->translate(0, SIDE_OFFSET + TEXT_HEIGHT);
    height -= SIDE_OFFSET + TEXT_HEIGHT;

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

void GameArea::drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_absolute_size(maxSize / 4 * Pango::SCALE);

    auto layout = create_pango_layout(std::to_string(number));
    layout->set_font_description(font);

    int textWidth;
    int textHeight;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(textWidth, textHeight);

    x -= textWidth / 2;
    y -= textHeight / 2;
    // Position the text in the middle
    cr->move_to(x, y);

    layout->show_in_cairo_context(cr);
}
