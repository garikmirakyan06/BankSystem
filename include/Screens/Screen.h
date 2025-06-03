#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <climits>



class Screen {
public:
    virtual void display() const = 0;
    virtual Screen* interact() = 0;

    void clear_screen() const;
    void wait_for_enter() const;    
    virtual ~Screen() = default;
};



#endif