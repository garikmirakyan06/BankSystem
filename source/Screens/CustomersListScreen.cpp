#include "CustomersListScreen.h"


void CustomersListScreen::display() const {
    clear_screen();
    std::cout << "\t=========================\n";
    std::cout << "\t   VIEW CUSTOMER`S LIST\n";
    std::cout << "\t=========================\n\n";

    int index = 1;
    for(const auto& [_, account] : bank.get_accounts()) {
        std::cout << index << ") " << account.get_name();
        std::cout << ",  balance - " << account.get_balance() << '\n';
        index++;
    }

}

std::shared_ptr<Screen> CustomersListScreen::interact() {

    wait_for_enter();

    return std::make_shared<MenuScreen>(bank);
}