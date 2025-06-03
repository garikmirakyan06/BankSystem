#include "../include/InputValidator.h"


// checking if account with such name alredy exist 
std::string InputValidator::choose_valid_name(const Bank& bank) {
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


std::string InputValidator::choose_valid_password() {
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


double InputValidator::choose_valid_balance() {
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