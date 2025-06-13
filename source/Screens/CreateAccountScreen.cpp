#include "CreateAccountScreen.h"


void CreateAccountScreen::display() const {
    clear_screen();

    std::cout << "\t======================\n";
    std::cout << "\t   CREATE AN ACCOUNT\n";
    std::cout << "\t======================\n\n";

}

std::shared_ptr<Screen> CreateAccountScreen::interact() {
    std::string name;
    std::string password;
    double balance;

    std::cout << "1) Choose name for your account: ";
    name = InputValidator::choose_valid_name(bank);
    
    std::cout << "\n2) Choose your password (4 digits): ";
    password = InputValidator::choose_valid_password();

    std::cout << "\n3) Choose your balance :) ";
    balance = InputValidator::choose_valid_balance();

    bank.create_account(name, password, balance);

    std::cout << "\nAccount created successfully\n";

    wait_for_enter();

    return std::make_shared<MenuScreen>(bank);
}