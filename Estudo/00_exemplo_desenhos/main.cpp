#include <iostream>
#include <gui.h>
#include <math.h>

#define WIDTH 800
#define HIGH 600

void desenha();
void teclado(unsigned char tecla, int x, int y);
void draw_obj_GL_LINES();
void draw_obj_GL_STRIP();
void draw_obj_GL_TRIANGLES();
void draw_obj_GL_TRIANGLE_STRIP();
void draw_obj_GL_QUADS();
void draw_obj_GL_QUAD_STRIP();
void draw_obj_GL_POLYGON();

void show_function_sin(int x);

using namespace std;

int main(){
    cout << "Programa em funcionamento..." << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha,teclado);
    return 0;
}

void desenha() {
    GUI::displayInit();

    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    GUI::drawFloor();
    show_function_sin(20*PI);
    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

}

void draw_obj_GL_LINES(){//Pares do ponto A->B
    glBegin(GL_LINES);
        glNormal3f(1,0,0);
        glVertex3f(0,0,0);//A
        glVertex3f(0.5,0.5,0.5);//B
        glVertex3f(1,1,1);
        glVertex3f(1.5,1.5,1.5);
    glEnd();
}
void draw_obj_GL_STRIP(){//Ligação entre os pontos na ordem de declaração
    glBegin(GL_LINE_STRIP);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(1.5,0,0);
        glVertex3f(1.5,1.5,0);
        glVertex3f(1.5,1.5,1.5);
    glEnd();
}

void draw_obj_GL_TRIANGLES(){
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(1.5,0,0);
        glVertex3f(1.5,1.5,0);
        glVertex3f(1.5,1.5,1.5);
        glVertex3f(0,1.5,1.5);
        glVertex3f(0,0,1.5);
    glEnd();
}

void draw_obj_GL_TRIANGLE_STRIP(){
    glBegin(GL_TRIANGLE_STRIP);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(1.5,0,0);
        glVertex3f(1.5,1.5,0);
        glVertex3f(1.5,1.5,1.5);
        glVertex3f(0,1.5,1.5);
        glVertex3f(0,0,1.5);
    glEnd();
}
void draw_obj_GL_QUADS(){
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0.5,0.5,0.5);
    glEnd();
}
void draw_obj_GL_QUAD_STRIP(){
    glBegin(GL_QUAD_STRIP);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0.5,0.5,0.5);
    glEnd();
}
void draw_obj_GL_POLYGON(){
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(1.5,0,0);
        glVertex3f(1.5,1.5,0);
        glVertex3f(1.5,1.5,1.5);
    glEnd();
}
void show_function_sin(int x){
    glBegin(GL_LINE_STRIP);
    glNormal3f(1,0,0);
    for(double i=0;i<x;i+=0.1){
        glVertex3f(sin(i)/2,i/x,cos(i)/2);
    }        
    glEnd();    

}
