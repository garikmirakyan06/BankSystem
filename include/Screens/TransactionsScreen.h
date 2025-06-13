#pragma once

#include "Bank.h"
#include "Account.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenUtils.h"


class TransactionsScreen : public Screen {
private:
    Bank& bank;

public:
    TransactionsScreen(Bank& _bank) : bank(_bank) {
        
    }

    void display() const override;
    std::shared_ptr<Screen> interact() override;
};