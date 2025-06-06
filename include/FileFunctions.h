#pragma once

#include <fstream>
#include <exception>

#include <nlohmann/json.hpp>
#include "Account.h"
#include "Bank.h"

class FileFunctions {
public:
    // when we run the programm, at first we copy 
    // data in our program from json file.
    static void initialize_data(const std::string& path, Bank& bank);

    // calling function this each time after handling one 
    // option that enter user (only when some data changes) 
    static void update_file_data(const std::string& path, const Bank& bank);

    // deserialization, from given file it creates and returns json object 
    static json load_data(const std::string& path);


    // write json object in given file 
    static void write_in_file(const std::string& path, const json& data);

};
