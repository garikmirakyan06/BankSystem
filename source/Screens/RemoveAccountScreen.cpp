#include "RemoveAccountScreen.h"


void RemoveAccountScreen::display() const {
    clear_screen();
    std::cout << "\t===============================\n";
    std::cout << "\t   REMOVING EXISTING ACCOUNT\n";
    std::cout << "\t===============================\n\n";

}

Screen* RemoveAccountScreen::interact() {
    // at first authenticate
    Account* accountPtr = ScreenUtils::authenticate(bank);
    if(accountPtr == nullptr) { // auth not done
        return new MenuScreen(bank);
    }
    
    Account& account = *accountPtr;
    bank.remove_account(account);
    return new MenuScreen(bank);
}