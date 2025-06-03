#include "AccountDetailsScreen.h"

void AccountDetailsScreen::display() const {
    clear_screen();
    std::cout << "\t========================================\n";
    std::cout << "\t   CHECK DETAILS OF EXISTING ACCOUNT\n";
    std::cout << "\t========================================\n\n";
}

Screen* AccountDetailsScreen::interact() {
    // at first authenticate 
    Account* accountPtr = ScreenUtils::authenticate(bank);
    if(accountPtr == nullptr) { // auth not done
        return new MenuScreen(bank);
    }
    const Account& account = *accountPtr;
    std::cout << "\nname: " << account.get_name() << '\n';
    std::cout << "\npassword: " << account.get_password() << '\n';
    std::cout << "\nbalance: " << account.get_balance() << '\n';
    std::cout << "\nid: " << account.get_id() << '\n';
    wait_for_enter();
    return new MenuScreen(bank);
}