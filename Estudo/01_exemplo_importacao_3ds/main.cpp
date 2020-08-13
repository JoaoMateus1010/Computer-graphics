#include <iostream>
#include <gui.h>

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

using namespace std;

Model3DS m3ds1 = Model3DS("../01_exemplo_importacao_3ds/3ds/city.3DS");

int main(){
    cout << "Programa executando..." << endl;
    GUI gui = GUI(WIDTH,HIGH,desenha,teclado);
    return 0;
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,0,2,0, true, false);
    GUI::drawOrigin(0.5);
    GUI::setColor(1,0,0);
    GUI::drawFloor();
    GUI::draw3ds(m3ds1,0,0,0);
    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);
}
