#include <iostream>
#include <gui.h>

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

using namespace std;

Model3DS m3ds = Model3DS("../Code/3ds/skeleton.3DS");
int main(){
    cout << system("pwd") << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha,teclado);
    return 0;
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    GUI::drawFloor();

    glPushMatrix();

    glTranslatef(1,2,0);
    glRotatef(45,0,0,1);
    glRotatef(-90,0,1,0);
    glScalef(1,1,2);

    glScalef(1,1,0.5);
    glRotatef(90,0,1,0);
    glRotatef(-45,0,0,1);
    glTranslatef(-1,-2,0);

    glTranslatef(2,1,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(1,0.5,1);

    //glScalef(1,2,1);
    //glRotatef(-90,1,0,0);
    //glRotatef(-90,0,1,0);
    //glTranslatef(-2,-1,0);

    glTranslatef(0,0.43,0);
    glScalef(20,20,20);
    glRotatef(90,1,0,0);

    GUI::draw3ds(m3ds,0,0,0);

    glPopMatrix();

    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

}
