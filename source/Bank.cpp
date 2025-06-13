#include "Bank.h"


void Bank::create_account(const std::string& name, const std::string& password, double balance) {
    Account account(name, password, balance);
    account.set_id(accounts.size()+1);     
    accounts[name] = account;
}   

void Bank::remove_account(Account& account) {
	int remove_id = account.get_id();
	// iterate all accounts to change their id if id > remove_id 
	for(auto& [_, acc] : accounts) {
		int acc_id = acc.get_id();
		if(acc_id > remove_id) {
			acc.set_id(acc_id-1);
		}
	}	
	accounts.erase(account.get_name());
}

bool Bank::has_account_named(const std::string& name) const {
	return (accounts.find(name) != accounts.end());
}

Account& Bank::authenticate_user(const std::string& name, const std::string& password) {
	if(!has_account_named(name)) {
		throw std::invalid_argument("No account by name " + name);
	}
	if(accounts[name].get_password() != password) {
		throw std::invalid_argument("Incorrect password");
	}
	return accounts[name];
}
