#include "ScreenUtils.h"

Account* ScreenUtils::authenticate(Bank& bank) {
    AuthenticateScreen* authScreen = new AuthenticateScreen(bank);
    authScreen->display();
    Screen* checkPtr = authScreen->interact();
    if(checkPtr == nullptr) { // authenticate not done 
        delete authScreen;
        return nullptr;
    }
    return authScreen->get_account();
}