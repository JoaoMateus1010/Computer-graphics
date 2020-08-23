#include <iostream>

using namespace std;

#include <gui.h>

float esferaX = -1;
float caixaX = 0;

float objtx = 0.0;
float objty = 0.0;
float objtz = 0.0;
float objax = 0.0;
float objay = 0.0;
float objaz = 0.0;
float objex = 1.0;
float objey = 1.0;
float objez = 1.0;

bool esfera = false;
bool caixa = false;

Model3DS modelo3ds = Model3DS("/home/joao/Documentos/Faculdade/Semestre9/Computacao_Grafica/dropbox alunos/exemplos_sala/00_projeto inicial com camera/GLUTdoZero20201_mouse/3ds/cartest.3DS");

void desenhaObjeto()
{
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,0,0);
    glEnd();
}

void desenha() {
    GUI::displayInit();

    //vetorObjetos[posSel].tx += glutGUI::dtx;
    objtx += glutGUI::dtx;
    objty += glutGUI::dty;
    objtz += glutGUI::dtz;
    objax += glutGUI::dax;
    objay += glutGUI::day;
    objaz += glutGUI::daz;
    objex += glutGUI::dsx;
    objey += glutGUI::dsy;
    objez += glutGUI::dsz;

    if (caixa) {
        caixaX += glutGUI::dtx;
    }
    if (esfera) {
        esferaX += glutGUI::dtx;
    }


    glPushMatrix();
        GUI::setColor(0,1,0);
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0.5,0,0.5);
            glVertex3f(0,0,0.5);
            glVertex3f(0,0,0);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(0.5,0,0);
            glVertex3f(0.5,0.75,0);
            glVertex3f(0.5,0.75,0.5);
            glVertex3f(0.5,0,0.5);
            glVertex3f(0,0,0);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(0,0.75,0);
            glVertex3f(0.5,0.75,0.5);
            glVertex3f(0.5,0,0.5);
            glVertex3f(0,0,0);
        glEnd();
    glPopMatrix();

    GUI::setLight(0, 0,2,0, true, false);

    //referencia (sistema de coordenadas global)
    GUI::drawOrigin(0.5);

    GUI::setColor(1,0,0);
    GUI::drawFloor();

    GUI::setColor(0,1,0, 0.5);
    GUI::drawSphere(esferaX,1,0, 0.3);

    GUI::setColor(0,0,1);
    GUI::drawBox(-5,-5,-2, 5,5,2, true);

    GUI::setColor(0,0,1);
    GUI::drawBox(caixaX+1,1,-2, caixaX+2,2,-1);

    //for( cada objeto ) {
        GUI::drawOrigin(0.5);
        desenhaObjeto();
        glPushMatrix();
            glTranslatef(objtx,objty,objtz);  //  p' = T.Rx.Ry.Rz.S. p
            glRotatef(objax,1,0,0);
            glRotatef(objay,0,1,0);
            glRotatef(objaz,0,0,1);
            glScalef(objex,objey,objez);

            GUI::drawOrigin(0.5);
            desenhaObjeto();
        glPopMatrix();
    //}

    glPushMatrix();
        glTranslatef(2,1,-1);
        GUI::setColor(0,0,1);
        GUI::draw3ds(modelo3ds,-1,0,1);
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
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'b':
        caixa = !caixa;
        break;
    case 'e':
        esfera = !esfera;
        break;

    case 'a':
        esferaX -= 0.1;
        break;
    case 'd':
        esferaX += 0.1;
        break;

    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//}
