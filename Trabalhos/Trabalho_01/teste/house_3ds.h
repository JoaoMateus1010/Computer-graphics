#ifndef CAR_H
#define CAR_H
#include "generic.h"
#include "generic_3ds.h"

class House_3DS:public Generic,public Generic_3ds{
public:
    House_3DS();
    House_3DS(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz);
    ~House_3DS();
    virtual void draw() override;
    virtual void correcao() override;
};

#endif // CAR_H
