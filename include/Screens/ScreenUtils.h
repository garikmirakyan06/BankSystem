#pragma once

#include "Bank.h"
#include "Account.h"
#include "Screen.h"
#include "InputValidator.h"

class ScreenUtils {
public:
    static Account& authenticate(Bank& bank);
};