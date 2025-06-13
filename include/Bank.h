#pragma once

#include <iostream>
#include <unordered_map>

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
    

    void create_account(const std::string& name, const std::string& password, double balance);
	
	void remove_account(Account& account);

    bool has_account_named(const std::string& name) const;

    Account& authenticate_user(const std::string& name, const std::string& password);

};
