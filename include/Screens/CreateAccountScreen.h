#ifndef CREATEACCOUNTSCREEN_H
#define CREATEACCOUNTSCREEN_H

#include "Screen.h"
#include "Bank.h"
#include "MenuScreen.h"
#include "InputValidator.h"


class CreateAccountScreen : public Screen {
private:
    Bank& bank;

public:
    CreateAccountScreen(Bank& _bank) : bank(_bank) {

    }


    void display() const override;
    std::shared_ptr<Screen> interact() override;


};

#endif