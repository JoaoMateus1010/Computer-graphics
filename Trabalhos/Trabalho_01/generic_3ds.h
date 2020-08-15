#ifndef GENERIC_3DS_H
#define GENERIC_3DS_H

#include "generic.h"

class Generic_3ds{
private:
    string path;
public:
    Generic_3ds(string path);
    Generic_3ds();
    ~Generic_3ds();
    virtual void correcao()=0;
    void set_path(string path);
    string get_path();
};

#endif // GENERIC_3DS_H
