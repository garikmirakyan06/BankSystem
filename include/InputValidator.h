#pragma once

#include <iostream>
#include <climits>
#include <regex>

#include "Bank.h"

class InputValidator {
public:
    static std::string choose_valid_name(const Bank&);
    static std::string choose_valid_password();
    static double choose_valid_balance();
}; 
