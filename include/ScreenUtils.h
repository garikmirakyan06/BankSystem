#pragma once

#include "Bank.h"
#include "Account.h"
#include "Screen.h"
#include "AuthenticateScreen.h"

class ScreenUtils {
public:
    static Account* authenticate(Bank& bank);
};