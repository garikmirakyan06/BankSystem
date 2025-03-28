#pragma once

#include <iostream>
#include <climits>

#include "Bank.h"
#include "Account.h"

class Menu {
private:
    std::vector<std::string> options;


    void initialize();

    // wainting the user to click Enter 
    void wait_for_enter();

    void clear_screen();

    // checking if account with such name already exist 
    std::string choose_valid_name(const Bank& bank);

    std::string choose_valid_password();

    Account& authenticate(Bank& bank);

    // Creating new account
    void handle_option_1(Bank& bank);

    // update information of existing account
    void handle_option_2(Bank& bank);

    // for transactions
    void handle_option_3(Bank& bank);

    // Check the details of existing account
    void handle_option_4(Bank& bank);

    // removing existing account
    void handle_option_5(Bank& bank);

    // view customer's list 
    void handle_option_6(const Bank& bank);



public:
    Menu() : options() {
        initialize();
    }

    // initial screen of Main Menu with options
    void display();

    // user is choosing the option (1-7)
    int choose();

    // handling the choice of user 
    void handle_choice(int choice, Bank& bank);
};
