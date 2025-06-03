#include "AuthenticateScreen.h"

void AuthenticateScreen::display() const {

}

Screen* AuthenticateScreen::interact() {
    std::string name;
    std::string password; 
    bool auth_done = true;
    do {
        std::cout << "\nWrite your account name: ";
        std::cin >> name;
        std::cout << "\nWrite your password: ";
        password = InputValidator::choose_valid_password();
        accountPtr = bank.authenticate_user(name, password);
        if(accountPtr != nullptr) {
            break;
        }
        std::cout << "\nAccount does not exists, or invalid password. Try again.\n\n";
        std::cout << "If you want to continue, press (y); otherwise, press (n): ";
        char char_ans = 'n';
        std::cin >> char_ans;
        if(char_ans == 'n') {
            auth_done = false;
            break;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    } while(true);
    std::cout << "\n";
    if(auth_done) {
        return this;
    }
    return nullptr;
}

Account* AuthenticateScreen::get_account() const {
    return accountPtr;
}
