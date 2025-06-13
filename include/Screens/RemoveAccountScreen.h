#pragma once

#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenUtils.h"


class RemoveAccountScreen : public Screen {
private:
    Bank& bank;

public:
    RemoveAccountScreen(Bank& _bank) : bank(_bank) {
        
    }

    void display() const override;
    std::shared_ptr<Screen> interact() override;
};