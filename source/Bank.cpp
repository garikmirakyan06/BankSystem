#include "Bank.h"


void Bank::create_account(std::string name, std::string password, long long balance) {
    Account account(name, password, balance);
    account.id = accounts.size()+1;     
    accounts[name] = account;
}   