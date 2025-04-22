#include "Menu.h"

// private

void Menu::initialize() {
    options.resize(7);
    options[0] = "Create an Account.";
    options[1] = "Update information of existing account.";
    options[2] = "For transactions.";
    options[3] = "Check the details of existing account.";
    options[4] = "Removing existing account.";
    options[5] = "View customer's list.";
    options[6] = "Exit.";
}

void Menu::wait_for_enter() {
    std::cout << "\nClick Enter to continue...";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
}

void Menu::clear_screen() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else 
        system("clear"); // Linux, macOS
    #endif
}


// checking if account with such name alredy exist 
std::string Menu::choose_valid_name(const Bank& bank) {
    std::string name;
    const auto& accounts = bank.get_accounts();
    while(true) {
        std::cin >> name;
        if(accounts.find(name) != accounts.end()) {
            std::cout << "Account already exist. Choose another name: ";
        } else {
            break;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    return name;
}

std::string Menu::choose_valid_password() {
    std::string password;
	std::string pattern = "[0-9]{4}";
	std::regex regexRule(pattern);
    while(true) {
        std::cin >> password;
        if(!std::regex_match(password, regexRule)) {
            std::cout << "Invalid password. Try again: ";
        } else {
            break;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    };
    return password;
}

double Menu::choose_valid_balance() {
	double balance;
	while(true) {
		std::cin >> balance;
		if(std::cin.fail() || balance < 0) {
			std::cout << "Invalid balance. Try again: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		} else break;
	}
	return balance;
}

Account& Menu::authenticate(Bank& bank) {
    std::string name;
    std::string password; 
	auto& accounts = bank.get_accounts();
    do {
        std::cout << "Write your account name: ";
        std::cin >> name;
        std::cout << "Write your password: ";
        std::cin >> password;
        if(accounts.find(name) != accounts.end()
        && accounts.at(name).get_password() == password) {
            break;
        }
        std::cout << "\nAccount does not exists, or invalid password. Try again.\n\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    } while(true);
    std::cout << "\n";
    return accounts[name];
    
}

// Creating new account
void Menu::handle_option_1(Bank& bank) {
    clear_screen();
    std::string name;
    std::string password;
    double balance;

    std::cout << "\t======================\n";
    std::cout << "\t   CREATE AN ACCOUNT\n";
    std::cout << "\t======================\n\n";

    std::cout << "1) Choose name for your account: ";
    name = choose_valid_name(bank);
    
    std::cout << "\n2) Choose your password (4 digits): ";
    password = choose_valid_password();

    std::cout << "\n3) Choose your balance :) ";
    balance = choose_valid_balance();

    bank.create_account(name, password, balance);

    std::cout << "\nAccount created successfully\n";
    wait_for_enter();
}

// update information of existing account
void Menu::handle_option_2(Bank& bank) {
    clear_screen();
    std::cout << "\t============================================\n";
    std::cout << "\t   UPDATE INFORMATION OF EXISTING ACCOUNT\n";
    std::cout << "\t============================================\n";

    Account& account = authenticate(bank);

    std::cout << "Write new name, or press Enter: ";
    std::string new_name = account.get_name();
    std::cin.ignore(INT_MAX, '\n');
    std::getline(std::cin, new_name);
    if(new_name.empty()) {
        new_name = account.get_name();
    }

    std::cout << "Write new password, or press Enter: ";
    std::string new_password = choose_valid_password();
        
    account.set_name(new_name);
    account.set_password(new_password);
}

void Menu::handle_option_3(Bank& bank) {
    clear_screen();
    std::cout << "\t====================\n";
    std::cout << "\t  FOR TRANSACTIONS\n";
    std::cout << "\t====================\n";
    
    Account& sender = authenticate(bank);

    std::cout << "Write the name of account that you want to transact with: ";
    std::string name;
    const auto& accounts = bank.get_accounts();
    while(true) {
        std::cin >> name;
        if(accounts.find(name) == accounts.end()) {
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
        if(std::cin.fail() || money < 0 || sender.get_balance() < money) {
            std::cout << "Invalid input. Try again: ";
        } else break;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }

    sender.set_balance(sender.get_balance() - money);
    Account& receiver = bank.get_accounts()[name];
    receiver.set_balance(receiver.get_balance() + money);   
    
    std::cout << "\nTransaction completed successfully.\n";
    wait_for_enter();

}


// Check the details of existing account
void Menu::handle_option_4(Bank& bank) {
    clear_screen();
    std::cout << "\t========================================\n";
    std::cout << "\t   CHECK DETAILS OF EXISTING ACCOUNT\n";
    std::cout << "\t========================================\n\n";

    Account& account = authenticate(bank);
    std::cout << "\nname: " << account.get_name() << '\n';
    std::cout << "\npassword: " << account.get_password() << '\n';
    std::cout << "\nbalance: " << account.get_balance() << '\n';
    std::cout << "\nid: " << account.get_id() << '\n';
    wait_for_enter();
}

// removing existing account
void Menu::handle_option_5(Bank& bank) {
    clear_screen();
    std::cout << "\t===============================\n";
    std::cout << "\t   REMOVING EXISTING ACCOUNT\n";
    std::cout << "\t===============================\n\n";
    
    Account& account = authenticate(bank);
    bank.remove_account(account);
}

// view customer's list 
void Menu::handle_option_6(const Bank& bank) {
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

    wait_for_enter();
}



// public

// initial screen
void Menu::display() {
    clear_screen();
    std::cout << "\t==========================\n";
    std::cout << "\t  BANK MANAGEMENT SYSTEM\n";
    std::cout << "\t==========================\n";
    for(int index = 0; index < options.size(); index++) {
        std::cout << index+1 << ". " << options[index] << '\n';
    }
}

int Menu::choose() {
    int choice;
    std::cout << "Choose an option: ";
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

void Menu::handle_choice(int choice, Bank& bank) {
    switch (choice)
    {
    case 1:
        handle_option_1(bank);
        break;

    case 2:
        handle_option_2(bank);
        break;

    case 3:
        handle_option_3(bank);
        break;

    case 4:
        handle_option_4(bank);
        break;

    case 5:
        handle_option_5(bank);
        break;

    case 6:
        handle_option_6(bank);
        break;
    
    default:
        break;
    }
}
