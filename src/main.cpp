#include "file_functions.h"
#include "Menu.h"
#include "Bank.h"


std::string path = DATA_PATH;

int main() {
    Menu menu;
    Bank bank;
    initialize_data(path, bank); 
    
    int choice;
    while(true) {
        menu.display();
        choice = menu.choose();
        if(choice == 7) break;
        menu.handle_choice(choice, bank);
        if(choice != 6 && choice != 4) update_file_data(path, bank); // what data we add or change, write in file 
    }   


    return 0;
}
