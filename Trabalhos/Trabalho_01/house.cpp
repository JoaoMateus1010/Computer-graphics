#include "house.h"

House::House(){

}

House::~House(){

}
void House::draw(){
    //cout << "Print pela casa"<< endl;
    float largura = 2;
    float altura = 1;
    float centro = largura/2;
    float juncao = altura/2;
    glPushMatrix();
        GUI::setColor(1,0,0);
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(0+largura,0,0);
            glVertex3f(0+largura,0,0+largura);
            glVertex3f(0,0,0+largura);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(0+largura,0,0);
            glVertex3f(0+largura,0+altura,0);
            glVertex3f(0+largura,0+altura,0+largura);
            glVertex3f(0+largura,0,0+largura);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(0,0+altura,0);
            glVertex3f(0,0+altura,0+largura);
            glVertex3f(0,0,0+largura);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,0+largura);
            glVertex3f(0,0+altura,0+largura);
            glVertex3f(0+largura,0+altura,0+largura);
            glVertex3f(0+largura,0,0+largura);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,0+altura,0);
            glVertex3f(0+largura,0+altura,0);
            glVertex3f(0+largura,0,0);
        glEnd();
        GUI::setColor(0,1,0);
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(centro/2,0,largura+0.001);
            glVertex3f(centro/2,altura/2,largura+0.001);
            glVertex3f(centro,altura/2,largura+0.001);
            glVertex3f(centro,0,largura+0.001);
        glEnd();
        glBegin(GL_QUADS);
            glVertex3f(centro+0.1,altura/2+0.1,largura+0.001);
            glVertex3f(centro+0.1,altura/4+0.1,largura+0.001);
            glVertex3f(centro+altura/4+0.1,altura/4+0.1,largura+0.001);
            glVertex3f(centro+altura/4+0.1,altura/2+0.1,largura+0.001);
        glEnd();
        GUI::setColor(0,1,0);
        glBegin(GL_TRIANGLE_FAN);
            glNormal3f(0.5,0.5,0);
            glVertex3f(centro,altura+juncao,centro);
            glVertex3f(largura,altura,largura);
            glVertex3f(largura,altura,0);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            glNormal3f(0,0.5,0.5);
            glVertex3f(centro,altura+juncao,centro);
            glVertex3f(largura,altura,largura);
            glVertex3f(0,altura,largura);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            glNormal3f(-0.5,0.5,0);
            glVertex3f(centro,altura+juncao,centro);
            glVertex3f(0,altura,largura);
            glVertex3f(0,altura,0);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            glNormal3f(0,0.5,-0.5);
            glVertex3f(centro,altura+juncao,centro);
            glVertex3f(0,altura,0);
            glVertex3f(largura,altura,0);
        glEnd();
        GUI::drawOrigin(0.3);
    glPopMatrix();
    //GUI::drawBox(0,0,0,1,1,1,true);        
}
