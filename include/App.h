#ifndef APP_H
#define APP_H

#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "FileFunctions.h"


class App {
private:
    Bank bank;
    std::shared_ptr<Screen> current_screen = nullptr;
    std::string path = DATA_PATH;


public:
    App() : current_screen(std::make_shared<MenuScreen>(bank)) {
        FileFunctions::initialize_data(path, bank);
    }

    void run();

};


#endif