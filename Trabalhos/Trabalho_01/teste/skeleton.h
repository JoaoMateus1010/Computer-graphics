#ifndef SKELETON_H
#define SKELETON_H
#include "generic.h"
#include "generic_3ds.h"

class Skeleton:public Generic,public Generic_3ds{
public:
    Skeleton();    
    Skeleton(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz);
    ~Skeleton();
    virtual void draw() override;
    virtual void correcao() override;
};

#endif // SKELETON_H
