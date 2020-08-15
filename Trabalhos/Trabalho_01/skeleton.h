#ifndef SKELETON_H
#define SKELETON_H
#include "generic.h"
#include "generic_3ds.h"

class Skeleton:public Generic,public Generic_3ds{
public:
    Skeleton();
    Skeleton(string path);
    ~Skeleton();
    virtual void draw() override;
    virtual void correcao() override;
};

#endif // SKELETON_H
