#pragma once

#include "Bank.h"
#include "Account.h"
#include "InputValidator.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "AuthenticateScreen.h"
#include "ScreenUtils.h"


class UpdateAccountScreen : public Screen {
private:
    Bank& bank;

public:
    UpdateAccountScreen(Bank& _bank) : bank(_bank) {

    }

    void display() const override;
    Screen* interact() override;
};