#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Account {
private:
    std::string name;            
    std::string password;
    double balance;
    int id;


    friend class Bank;

public:
    Account() : name(), password(), balance(0), id(-1) {}
    Account(const std::string& name, const std::string& password, double balance) 
    : name(name), password(password), balance(balance), id(-1) {

    }

    // getters 
    const std::string& get_name() const {
        return name;
    }
    const std::string& get_password() const {
        return password;
    }
    double get_balance() const {
        return balance;
    }
    int get_id() const {
        return id;
    }

    // setters 
    
    
    void set_name(const std::string& new_name) {
        name = new_name;
    }
    void set_password(const std::string& new_password) {
        password = new_password;
    }
    void set_balance(double new_balance) {
        balance = new_balance;
    }
    void set_id(int new_id) {
        id = new_id;
    }


    // from Account object create json object  
    json to_json() const;
    
    // from json object create an object of type Account
    static Account from_json(const json& json_object);


};
    

