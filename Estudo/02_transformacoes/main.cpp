#include <iostream>
#include <gui.h>

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

using namespace std;
struct OBJ{
    float obj_x_translate=1.0;
    float obj_y_translate=1.0;
    float obj_z_translate=1.0;
    float obj_x_angle=45;
    float obj_y_angle=0.0;
    float obj_z_angle=0.0;
    float obj_x_scale=1.0;
    float obj_y_scale=1.0;
    float obj_z_scale=-2.0;
};
OBJ global_obj;
int main(){
    cout << "Programa em funcionamento..." << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha);
    return 0;
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    GUI::drawFloor();

    //Perguntar o motivo deste bloco ser necessário
    global_obj.obj_x_translate += glutGUI::dtx;
    global_obj.obj_y_translate += glutGUI::dty;
    global_obj.obj_z_translate += glutGUI::dtz;
    global_obj.obj_x_angle += glutGUI::dax;
    global_obj.obj_y_angle += glutGUI::day;
    global_obj.obj_z_angle += glutGUI::daz;
    global_obj.obj_x_scale += glutGUI::dsx;
    global_obj.obj_y_scale += glutGUI::dsy;
    global_obj.obj_z_scale += glutGUI::dsz;
    //-----

    glPushMatrix();//T*
        glTranslatef(global_obj.obj_x_translate,global_obj.obj_y_translate,global_obj.obj_z_translate);
        glRotatef(global_obj.obj_x_angle,1,0,0);
        glRotatef(global_obj.obj_y_angle,0,1,0);
        glRotatef(global_obj.obj_z_angle,0,0,1);
        glScalef(global_obj.obj_x_scale,global_obj.obj_y_scale,global_obj.obj_z_scale);
        GUI::drawOrigin(0.5);
        GUI::setColor(0,1,0);
        GUI::drawBox(0,0,0,1,1,1,false);
    glPopMatrix();

    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);
}
