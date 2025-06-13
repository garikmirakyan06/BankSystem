#include "App.h"

void App::run() {
    while(current_screen != nullptr) {
        current_screen->display();
        std::shared_ptr<Screen> next_screen = current_screen->interact();
        current_screen = next_screen;
        FileFunctions::update_file_data(path, bank);
    }
}