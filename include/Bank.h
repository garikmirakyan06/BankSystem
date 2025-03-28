#pragma once

#include <iostream>
#include <map>

#include "Account.h"


class Bank {
private:
    std::unordered_map<std::string, Account> accounts; // unordered_map very optimal container in this case
    
public:
    // getters 
    const std::unordered_map<std::string, Account>& get_accounts() const {
        return accounts;
    }
    std::unordered_map<std::string, Account>& get_accounts() {
        return accounts;
    }

    void create_account(std::string name, std::string password, long long balance);
};
