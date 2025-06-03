#include "MenuScreen.h"

void MenuScreen::init_options() {
    options.resize(7);
    options[0] = "Create an Account.";
    options[1] = "Update information of existing account.";
    options[2] = "For transactions.";
    options[3] = "Check the details of existing account.";
    options[4] = "Removing existing account.";
    options[5] = "View customer's list.";
    options[6] = "Exit.";
}

void MenuScreen::display() const {
    clear_screen();
    std::cout << "\t==========================\n";
    std::cout << "\t  BANK MANAGEMENT SYSTEM\n";
    std::cout << "\t==========================\n\n";
    for(int index = 0; index < options.size(); index++) {
        std::cout << index+1 << ". " << options[index] << '\n';
    }
}

int MenuScreen::choose() const {
    int choice;
    std::cout << "\nChoose an option: ";
    do {
        std::cin >> choice;
        if(std::cin.fail() || choice <= 0 || choice >= 8) {
            std::cout << "Wrong option. Try again: ";
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n');
        }
        else {
            break;
        }
    } while(true);
    return choice;
}



Screen* MenuScreen::handle_choice(int choice) const {
    switch (choice)
    {
    case 1:
        return new CreateAccountScreen(bank);
        break;

    case 2:
        return new UpdateAccountScreen(bank);
        break;

    case 3:
        return new TransactionsScreen(bank);
        break;

    case 4:
        return new AccountDetailsScreen(bank);
        break;

    case 5:
        return new RemoveAccountScreen(bank);
        break;

    case 6:
        return new CustomersListScreen(bank);
        break;

    case 7:
        return nullptr;
        break;
    
    default:
        break;
    }

    return nullptr;
}


Screen* MenuScreen::interact() {
    int choice = choose();
    Screen* next_screen = handle_choice(choice);
    return next_screen;
}

