#include "RemoveAccountScreen.h"


void RemoveAccountScreen::display() const {
    clear_screen();
    std::cout << "\t===============================\n";
    std::cout << "\t   REMOVING EXISTING ACCOUNT\n";
    std::cout << "\t===============================\n\n";

}

std::shared_ptr<Screen> RemoveAccountScreen::interact() {
    // at first authenticate
    try {
        Account& account = ScreenUtils::authenticate(bank);
        bank.remove_account(account);
        return std::make_shared<MenuScreen>(bank);
    } catch(const std::runtime_error& e) { // auth not done
    
    }
    return std::make_shared<MenuScreen>(bank);
}