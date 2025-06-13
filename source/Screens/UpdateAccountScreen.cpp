#include "UpdateAccountScreen.h"


void UpdateAccountScreen::display() const {
    clear_screen();
    std::cout << "\t============================================\n";
    std::cout << "\t   UPDATE INFORMATION OF EXISTING ACCOUNT\n";
    std::cout << "\t============================================\n";
}


std::shared_ptr<Screen> UpdateAccountScreen::interact() {
    // at first need to authenticate 
    try {
        Account& account = ScreenUtils::authenticate(bank);
                
        std::cout << "Write new name, or press Enter: ";
        std::string new_name = account.get_name();
        std::cin.ignore(INT_MAX, '\n');
        std::getline(std::cin, new_name);
        if(new_name.empty()) {
            new_name = account.get_name();
        }

        std::cout << "Write new password, or press Enter: ";
        std::string new_password = InputValidator::choose_valid_password();
            
        account.set_name(new_name);
        account.set_password(new_password);

    } catch(const std::runtime_error& e) { // auth not done
    
    }

    return std::make_shared<MenuScreen>(bank);
}