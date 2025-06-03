#pragma once

#include "Screen.h"
#include "Bank.h"
#include "InputValidator.h"

class AuthenticateScreen : public Screen {
private:
    Bank& bank;
    Account* accountPtr;

public:
    AuthenticateScreen(Bank& _bank) : bank(_bank), accountPtr(nullptr) {
        
    }

    void display() const override;
    Screen* interact() override;
    Account* get_account() const;
};