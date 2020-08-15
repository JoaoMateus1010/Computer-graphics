#ifndef MOLA_H
#define MOLA_H

#include <generic.h>
#include <math.h>

#define PI 3.14159265359

class Mola:public Generic{
private:
    float mola_constante;
public:
    Mola(float mola_constante);
    ~Mola();
    virtual void draw() override;
    float get_mola_constante();
    void set_mola_constante(float mola_constante);

};

#endif // MOLA_H
