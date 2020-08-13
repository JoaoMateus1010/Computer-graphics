#include <iostream>
#include <gui.h>

#define WIDTH 1366
#define HIGH 768

void desenha();
void teclado(unsigned char tecla, int x, int y);

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
    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

}
