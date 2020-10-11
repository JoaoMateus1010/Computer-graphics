#ifndef HOUSE_H
#define HOUSE_H

#include "generic.h"

class House:public Generic{
public:    
    House();
    House(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz);
    ~House();
    virtual void draw() override;
};

#endif // HOUSE_H
