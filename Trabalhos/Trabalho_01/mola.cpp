#include "mola.h"

Mola::Mola(float mola_constante){
    this->mola_constante=PI*mola_constante;
}
Mola::Mola(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz){
    this->set_x_translate(dx);
    this->set_y_translate(dy);
    this->set_z_translate(dz);
    this->set_x_angle(ax);
    this->set_y_angle(ay);
    this->set_z_angle(az);
    this->set_x_scale(sx);
    this->set_y_scale(sy);
    this->set_z_scale(sz);
}
Mola::~Mola(){

}
void Mola::draw(){
    glPushMatrix();
        glBegin(GL_LINE_STRIP);
            glNormal3f(1,0,0);
            for(double i=0;i<this->mola_constante;i+=0.1){
                glVertex3f(sin(i)/2,i/this->mola_constante,cos(i)/2);
            }
        glEnd();        
    glPopMatrix();
    //GUI::drawOrigin(0.3);
}
float Mola::get_mola_constante(){
    return this->mola_constante;
}
void Mola::set_mola_constante(float mola_constante){
    this->mola_constante=mola_constante;
}
