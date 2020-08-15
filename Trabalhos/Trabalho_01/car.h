#ifndef CAR_H
#define CAR_H
#include "generic.h"
#include "generic_3ds.h"

class Car:public Generic,public Generic_3ds{
public:
    Car();
    Car(string path);
    ~Car();
    virtual void draw() override;
    virtual void correcao() override;
};

#endif // CAR_H
