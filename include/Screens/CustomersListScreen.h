#pragma once

#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"


class CustomersListScreen : public Screen {
private:
    Bank& bank;

public:
    CustomersListScreen(Bank& _bank) : bank(_bank) {

    }

    void display() const override;
    std::shared_ptr<Screen> interact() override;
};