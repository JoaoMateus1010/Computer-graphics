#include "mola.h"

Mola::Mola(float mola_constante){
    this->mola_constante=PI*mola_constante;
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
    GUI::drawOrigin(0.3);
}
float Mola::get_mola_constante(){
    return this->mola_constante;
}
void Mola::set_mola_constante(float mola_constante){
    this->mola_constante=mola_constante;
}
