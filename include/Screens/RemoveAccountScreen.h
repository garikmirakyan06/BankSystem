#pragma once

#include "Bank.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "AuthenticateScreen.h"
#include "ScreenUtils.h"


class RemoveAccountScreen : public Screen {
private:
    Bank& bank;

public:
    RemoveAccountScreen(Bank& _bank) : bank(_bank) {
        
    }

    void display() const override;
    Screen* interact() override;
};