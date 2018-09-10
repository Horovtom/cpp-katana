//
// Created by lactosis on 10.9.18.
//

#include "Button.h"
#include "Utilities.h"


void Button::registerCallback(std::function<void(void)> cb) {
    this->callbacks.emplace_back(cb);
}

void Button::draw() {
    drawThickRectangle(renderer, x, y, size, size, 2, COLOR_BLACK);
    //TODO: CONTINUE
}
