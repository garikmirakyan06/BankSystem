#include "CreateAccountScreen.h"


void TransactionsScreen::display() const {
    clear_screen();
    std::cout << "\t====================\n";
    std::cout << "\t  FOR TRANSACTIONS\n";
    std::cout << "\t====================\n";

}

Screen* TransactionsScreen::interact() {
    // at first authenticate 
    Account* accountPtr = ScreenUtils::authenticate(bank);
    if(accountPtr == nullptr) { // auth not done
        return new MenuScreen(bank);
    }
    Account& sender = *accountPtr;

    std::cout << "Write the name of account that you want to transact with: ";
    std::string name;
    const auto& accounts = bank.get_accounts();
    while(true) {
        std::cin >> name;
        if(!bank.has_account_named(name)) {
            std::cout << "Account does not exist. Try again: ";
        } else {
            break;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    
    std::cout << "\nEnter the amount of money that you want to send: ";
    double money;
    while(true) {
        std::cin >> money;
        if(std::cin.fail() || money < 0) {
            std::cout << "Invalid input. Try again: ";
        } else if(sender.get_balance() < money) {
            std::cout << "You dont have enough money. Try again: ";
        } else break;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }

    sender.set_balance(sender.get_balance() - money);
    Account& receiver = bank.get_accounts()[name];
    receiver.set_balance(receiver.get_balance() + money);   
    
    std::cout << "\nTransaction completed successfully.\n";
    wait_for_enter();

    return new MenuScreen(bank);
}