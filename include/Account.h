#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Account {
private:
    std::string name;            
    std::string password;
    long long balance;
    int id;


    friend class Bank;

public:
    Account() : name(), password(), balance(0), id(-1) {}
    Account(std::string name, std::string password, long long balance) 
    : name(name), password(password), balance(balance), id(-1) {

    }

    // getters 
    const std::string& get_name() const {
        return name;
    }
    std::string get_password() const {
        return password;
    }
    long long get_balance() const {
        return balance;
    }
    int get_id() const {
        return id;
    }

    // setters 
    
    
    void set_name(const std::string& new_name) {
        name = new_name;
    }
    void set_password(std::string new_password) {
        password = new_password;
    }
    void set_balance(long long new_balance) {
        balance = new_balance;
    }
    void set_id(int new_id) {
        id = new_id;
    }


    // from Account object create json object  
    json to_json();
    
    // from json object create an object of type Account
    static Account from_json(const json& json_object);


};
    

