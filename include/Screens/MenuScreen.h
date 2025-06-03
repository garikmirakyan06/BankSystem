#pragma once


#include <iostream>
#include <vector>

#include "Bank.h"
#include "Screen.h"
#include "CreateAccountScreen.h"
#include "UpdateAccountScreen.h"
#include "CustomersListScreen.h"
#include "TransactionsScreen.h"
#include "AccountDetailsScreen.h"
#include "RemoveAccountScreen.h"



class MenuScreen : public Screen {
private:
    std::vector<std::string> options;
    Bank& bank;    

    void init_options();
    Screen* handle_choice(int) const;
    int choose() const;
public:
    MenuScreen(Bank& _bank) : bank(_bank) {
        init_options();
    }

    void display() const override;
    Screen* interact() override;   
};


