#ifndef GENERIC_H
#define GENERIC_H
#include <iostream>
using namespace std;
class Generic{
    private:
        float x_translate;
        float y_translate;
        float z_translate;
        float x_angle;
        float y_angle;
        float z_angle;
        float x_scale;
        float y_scale;
        float z_scale;
    public:
        Generic(float x_translate,float y_translate,float z_translate,float x_angle,float y_angle,float z_angle,float x_scale,float y_scale,float z_scale);
        ~Generic();
        Generic();
        virtual void draw()=0;

        void set_x_translate(float x_translate);
        void set_y_translate(float y_translate);
        void set_z_translate(float z_translate);
        void set_x_angle(float x_angle);
        void set_y_angle(float y_angle);
        void set_z_angle(float z_angle);
        void set_x_scale(float x_scale);
        void set_y_scale(float y_scale);
        void set_z_scale(float z_scale);

        float set_x_translate();
        float set_y_translate();
        float set_z_translate();
        float set_x_angle();
        float set_y_angle();
        float set_z_angle();
        float set_x_scale();
        float set_y_scale();
        float set_z_scale();
};

#endif // GENERIC_H
