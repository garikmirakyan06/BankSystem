#include "AccountDetailsScreen.h"

void AccountDetailsScreen::display() const {
    clear_screen();
    std::cout << "\t========================================\n";
    std::cout << "\t   CHECK DETAILS OF EXISTING ACCOUNT\n";
    std::cout << "\t========================================\n\n";
}

std::shared_ptr<Screen> AccountDetailsScreen::interact() {
    // at first authenticate 
    try {
        Account& account = ScreenUtils::authenticate(bank);
        std::cout << "\nname: " << account.get_name() << '\n';
        std::cout << "\npassword: " << account.get_password() << '\n';
        std::cout << "\nbalance: " << account.get_balance() << '\n';
        std::cout << "\nid: " << account.get_id() << '\n';
        wait_for_enter();

    } catch(const std::runtime_error& e) { // auth not done

    }

    return std::make_shared<MenuScreen>(bank);
}