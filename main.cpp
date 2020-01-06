

#include <game/logic/Game.h>
#include <gtkmm/application.h>
#include <graphics/GameWindow.h>
#include <game/Controller.h>

int runWithGraphics(int argc, char **argv, Game *game) {
    auto app = Gtk::Application::create(argc, argv, "com.github.horovtom.katana");
    GameWindow window;

    window.set_default_size(640, 640);
    window.set_title("Game: Katana");
    Controller controller(game, &window);

    return app->run(window);

}

int main(int argc, char **argv) {

    Game *g = new Game();
    int res = runWithGraphics(argc, argv, g);
    delete g;
    return res;

}