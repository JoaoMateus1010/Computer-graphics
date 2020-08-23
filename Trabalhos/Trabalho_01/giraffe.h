#ifndef Giraffe_H
#define Giraffe_H
#include "generic.h"

class Giraffe:public Generic{
    public:
        Giraffe();
        ~Giraffe();
        virtual void draw() override;
};
#endif // Giraffe_H
