#ifndef DOG_H
#define DOG_H
#include "generic.h"

class Dog:public Generic{
    public:
        Dog();
        ~Dog();
        virtual void draw() override;
};
#endif // DOG_H
