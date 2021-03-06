//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_GAMEWINDOW_H
#define KATANA_GAMEWINDOW_H

#include <gtkmm.h>
#include <graphics/GameArea.h>
#include <game/GridField.h>

class Controller;

class GameWindow : public Gtk::Window {
public:

    GameWindow();

    virtual ~GameWindow();

    void registerController(Controller *controller);


    void setGameData(const std::vector<std::vector<GridField>> &grid,
                     const std::vector<const std::vector<std::pair<int, bool>> *> &leftClues,
                     const std::vector<const std::vector<std::pair<int, bool>> *> &topClues);

private:
    //Override default signal handler:
    bool on_key_press_event(GdkEventKey *event) override;


    Controller *controller = nullptr;
    GameArea area;
};

#endif //KATANA_GAMEWINDOW_H
