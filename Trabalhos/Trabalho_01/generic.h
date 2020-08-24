#ifndef GENERIC_H
#define GENERIC_H
#include <iostream>
#include <gui.h>
#include <fstream>
#include <sstream>

using namespace std;
class Generic{
    private:

    public:
    float x_translate;
    float y_translate;
    float z_translate;
    float x_angle;
    float y_angle;
    float z_angle;
    float x_scale;
    float y_scale;
    float z_scale;

        Generic(float x_translate,float y_translate,float z_translate,float x_angle,float y_angle,float z_angle,float x_scale,float y_scale,float z_scale);
        ~Generic();
        Generic();
        virtual void draw();

        void set_x_translate(float x_translate);
        void set_y_translate(float y_translate);
        void set_z_translate(float z_translate);
        void set_x_angle(float x_angle);
        void set_y_angle(float y_angle);
        void set_z_angle(float z_angle);
        void set_x_scale(float x_scale);
        void set_y_scale(float y_scale);
        void set_z_scale(float z_scale);

        float get_x_translate();
        float get_y_translate();
        float get_z_translate();
        float get_x_angle();
        float get_y_angle();
        float get_z_angle();
        float get_x_scale();
        float get_y_scale();
        float get_z_scale();

        void saveInFile();
        Generic* loadFromFile();

};
istream& operator >> (istream& is,Generic& obj);
ostream& operator << (ostream& os, const Generic& obj);
string float_to_string(float number);
#endif // GENERIC_H
