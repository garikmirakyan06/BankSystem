#include "ScreenUtils.h"

Account& ScreenUtils::authenticate(Bank& bank) {
    std::string name{};
    std::string password{};
    bool auth_done = true;
    do {
        std::cout << "\nWrite your account name: ";
        std::cin >> name;
        std::cout << "\nWrite your password: ";
        password = InputValidator::choose_valid_password();
        if(bank.has_account_named(name)) {
            if(bank.get_accounts()[name].get_password() == password) {
                break;
            }
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
    if(!auth_done) {
        throw std::runtime_error("Authenticate not done.\n");
    }
    return bank.get_accounts()[name];
}


