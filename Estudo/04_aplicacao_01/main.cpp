#include <iostream>
#include <gui.h>
#include <math.h>

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

using namespace std;

Model3DS model3dsCar = Model3DS("../04_aplicacao_01/3ds/cartest.3DS");
Model3DS model3dsCity = Model3DS("../04_aplicacao_01/3ds/city.3DS");

struct generic_OBJ{
    float obj_x_init = 0.0;
    float obj_y_init = 0.0;
    float obj_z_init = 0.0;
    float obj_x_translate=0.0;
    float obj_y_translate=0.0;
    float obj_z_translate=0.0;
    float obj_x_angle=0.0;
    float obj_y_angle=0.0;
    float obj_z_angle=0.0;
    float obj_x_scale=1.0;
    float obj_y_scale=1.0;
    float obj_z_scale=1.0;
};

generic_OBJ car;
generic_OBJ city;

int main(){
    // City ajustes iniciais
    city.obj_x_scale = 60;
    city.obj_y_scale = 70;
    city.obj_z_scale = 40;
    city.obj_y_translate=-0.25;

    //Car ajustes iniciais
    car.obj_z_translate=2.5;
    car.obj_x_translate=-0.17;
    car.obj_y_angle = 180;
    car.obj_x_scale = 0.5;
    car.obj_y_scale = 0.5;
    car.obj_z_scale = 0.5;

    cout << "Programa em funcionamento..." << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha,teclado);
    return 0;
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    //GUI::drawFloor();
    //city    
    //transformações
    glPushMatrix();
    glTranslatef(city.obj_x_translate,city.obj_y_translate,city.obj_z_translate);
    glRotatef(city.obj_x_angle,1,0,0);
    glRotatef(city.obj_y_angle,0,1,0);
    glRotatef(city.obj_z_angle,0,0,1);
    glScalef(city.obj_x_scale,city.obj_y_scale,city.obj_z_scale);
    GUI::draw3ds(model3dsCity,city.obj_x_init,city.obj_y_init,city.obj_z_init);
    glPopMatrix();

    //car
    //Atualização de vlores
    car.obj_x_translate += glutGUI::dtx;
    car.obj_y_translate += glutGUI::dty;
    car.obj_z_translate += glutGUI::dtz;
    car.obj_x_angle += glutGUI::dax;
    car.obj_y_angle += glutGUI::day;
    car.obj_z_angle += glutGUI::daz;
    car.obj_x_scale += glutGUI::dsx;
    car.obj_y_scale += glutGUI::dsy;
    car.obj_z_scale += glutGUI::dsz;
    //ajustes iniciais    
    //transformações
    glPushMatrix();        
    glTranslatef(car.obj_x_translate,car.obj_y_translate,car.obj_z_translate);
    glRotatef(car.obj_x_angle,1,0,0);
    glRotatef(car.obj_y_angle,0,1,0);
    glRotatef(car.obj_z_angle,0,0,1);        
    glScalef(car.obj_x_scale,car.obj_y_scale,car.obj_z_scale);
    GUI::drawOrigin(1);
    GUI::draw3ds(model3dsCar,car.obj_x_init,car.obj_y_init,car.obj_z_init);
    glPopMatrix();
    GUI::displayEnd();
}

void ahead(){
    car.obj_z_translate -= 0.1;
}
void back(){
    car.obj_z_translate += 0.1;
}
void left_v1(){
    car.obj_x_translate -=0.1;
}
void right_v1(){
    car.obj_x_translate +=0.1;
}
void left_v2(){
    ahead();
    car.obj_y_angle += 10;
}
void right_v2(){
    ahead();
    car.obj_y_angle -= 10;
}
void teclado(unsigned char tecla, int x, int y) {
    switch(tecla){
    case 'w':
        ahead();
    break;
    case 's':
        back();
    break;
    case 'a':
        left_v2();
    break;
    case 'd':
        right_v2();
    break;
    }
}
