#include <iostream>
#include <gui.h>
#include "generic.h"
#include "giraffe.h"
#include "house.h"
#include "mola.h"
#include "model3ds.h"
#include "generic_3ds.h"
#include "house_3ds.h"
#include "skeleton.h"

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

using namespace std;
Generic* g = new House();

Model3DS modelo3ds = Model3DS("/home/joao/Documentos/Faculdade/Semestre9/Computacao_Grafica/dropbox alunos/exemplos_sala/00_projeto inicial com camera/GLUTdoZero20201_mouse/3ds/cartest.3DS");

int main(){              
    cout << "Programa em execução" << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha,teclado);
    return 0;
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    //GUI::drawFloor();

    g->set_x_translate(g->get_x_translate()+glutGUI::dtx);
    g->set_y_translate(g->get_y_translate()+glutGUI::dty);
    g->set_z_translate(g->get_z_translate()+glutGUI::dtz);

    g->set_x_angle(g->get_x_angle()+glutGUI::dax);
    g->set_y_angle(g->get_y_angle()+glutGUI::day);
    g->set_z_angle(g->get_z_angle()+glutGUI::daz);

    g->set_x_scale(g->get_x_scale()+glutGUI::dsx);
    g->set_y_scale(g->get_y_scale()+glutGUI::dsy);
    g->set_z_scale(g->get_z_scale()+glutGUI::dsz);

    glPushMatrix();
    glTranslatef(g->get_x_translate(),g->get_y_translate(),g->get_z_translate());
    glRotatef(g->get_x_angle(),1,0,0);
    glRotatef(g->get_y_angle(),0,1,0);
    glRotatef(g->get_z_angle(),0,0,1);
    glScalef(g->get_x_scale(),g->get_y_scale(),g->get_z_scale());
    g->draw();
    glPopMatrix();

    glPushMatrix();
        glScalef(0,0,0);
        GUI::draw3ds(modelo3ds);
    glPopMatrix();
    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);
    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;    
    case 't':
        g->set_x_translate(g->get_x_translate()+1);
        break;
        default:
        break;
    }
}
