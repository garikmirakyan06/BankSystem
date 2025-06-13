#pragma once

#include "Account.h"
#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenUtils.h"


class AccountDetailsScreen : public Screen {
private:
    Bank& bank;

public:
    AccountDetailsScreen(Bank& _bank) : bank(_bank) {

    }

    void display() const override;
    std::shared_ptr<Screen> interact() override;
};