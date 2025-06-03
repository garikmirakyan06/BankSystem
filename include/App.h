#ifndef APP_H
#define APP_H

#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "FileFunctions.h"


class App {
private:
    Bank bank;
    Screen* current_screen = nullptr;
    std::string path = DATA_PATH;


public:
    App() : current_screen(new MenuScreen(bank)) {
        FileFunctions::initialize_data(path, bank);
    }

    ~App() {
        delete current_screen;
    }

    void run();

};


#endif