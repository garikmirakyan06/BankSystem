#include "Screen.h"


void Screen::clear_screen() const {
    #ifdef _WIN32
        system("cls"); // Windows
    #else 
        system("clear"); // Linux, macOS
    #endif
}

void Screen::wait_for_enter() const {
    std::cout << "\nClick Enter to continue...";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
}
