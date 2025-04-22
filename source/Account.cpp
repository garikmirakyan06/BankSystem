#include "Account.h"


// from Account object create json object  
json Account::to_json() const {
    return json({{"name", name}, {"password", password}, {"balance", balance}, {"id", id}});
}

// from json object create an object of type Account
Account Account::from_json(const json& json_object) {
    Account account;
    if(!json_object["name"].empty()) {
        account.name = json_object["name"];
    }
    if(!json_object["password"].empty()) {
        account.password = json_object["password"];
    } 
    if(!json_object["balance"].empty()) {
        account.balance = json_object["balance"];
    } 
    if(!json_object["id"].empty()) {
        account.id = json_object["id"];
    } 

    return account;
}
