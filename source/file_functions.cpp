#include "file_functions.h"

// when we run the programm, at first we copy 
// data in our program from json file.
void initialize_data(const std::string& path, Bank& bank) {
    json data = load_data(path);
    if(data.empty()) {
        return;
    }
    for(const auto& account_json : data) {
        Account account = Account::from_json(account_json);
        bank.get_accounts()[account.get_name()] = account;
    }

}

// calling function this each time after handling one 
// option that enter user (only when some data changes) 
void update_file_data(const std::string& path, const Bank& bank) {
    json data;
    const auto& accounts = bank.get_accounts();
    for(const auto& [name, account] : accounts) {
        data[name] = account.to_json();
    }
    write_in_file(path, data);
}


// deserialization, from given file it creates and returns json object 
json load_data(const std::string& path) {
    std::cout << "load_data\n";
    std::ifstream file(path);
    if(!file.is_open()) {
        throw std::runtime_error("Could not open file to get data\n");
    }
    json data;
    if(file.peek() == std::ifstream::traits_type::eof()) { // check if file is empty 
        file.close();
        return data;
    }
    try { // check for invalid json data in file  
        file >> data;
    } catch(json::parse_error& e) {
        file.close();
        throw std::runtime_error("Invalid file, cant read data.");
    }
    file.close();
    return data;
}


// write json object in given file 
void write_in_file(const std::string& path, const json& data) {
    std::ofstream file(path);
    if(!file.is_open()) {
        throw std::runtime_error("Could not open file to write\n");
    }
    file << data.dump(4);
    file.close();
}
