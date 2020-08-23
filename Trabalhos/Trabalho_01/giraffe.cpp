#include "giraffe.h"
Giraffe::Giraffe(){

}
Giraffe::~Giraffe(){

}
void Giraffe::draw(){
    glPushMatrix();
        GUI::setColor(0.9,0.9,0.5);
        GUI::drawBox(0,0,0,0.25,0.5,0.25,false);
        glTranslatef(0,0,0.40);
        GUI::drawBox(0,0,0,0.25,0.5,0.25,false);
        glTranslatef(0.7,0,0);
        GUI::drawBox(0,0,0,0.25,0.5,0.25,false);
        glTranslatef(0,0,-0.40);
        GUI::drawBox(0,0,0,0.25,0.5,0.25,false);
    glPopMatrix();
    glPushMatrix();
        GUI::setColor(0.8,0.8,0.1);
        GUI::drawBox(-0.15,0.5,-0.15,1,1,0.8,false);
        GUI::drawBox(0.75,1,0.20,1,2,0.5,false);
        GUI::drawBox(0.75,2,0.15,1.35,2.3,0.55,false);
        GUI::drawBox(0.75,2,0.15,1.25,2.5,0.55,false);
    glPopMatrix();
    GUI::drawOrigin(0.3);    
}
