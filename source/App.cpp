#include "App.h"

void App::run() {
    while(current_screen != nullptr) {
        current_screen->display();
        Screen* next_screen = current_screen->interact();
        delete current_screen;
        current_screen = next_screen;
        FileFunctions::update_file_data(path, bank);
    }
}