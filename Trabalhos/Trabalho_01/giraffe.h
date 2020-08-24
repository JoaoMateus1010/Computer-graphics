#ifndef Giraffe_H
#define Giraffe_H
#include "generic.h"

class Giraffe:public Generic{
    public:
        Giraffe();
        Giraffe(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz);
        ~Giraffe();
        virtual void draw() override;
};
#endif // Giraffe_H
