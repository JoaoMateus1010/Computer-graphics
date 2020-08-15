#ifndef HOUSE_H
#define HOUSE_H

#include "generic.h"

class House:public Generic{
public:    
    House();
    ~House();
    virtual void draw() override;
};

#endif // HOUSE_H
