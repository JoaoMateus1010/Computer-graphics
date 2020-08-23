#include <iostream>
#include <gui.h>
#include <vector>

#include "generic.h"
#include "giraffe.h"
#include "house.h"
#include "mola.h"
#include "model3ds.h"
#include "generic_3ds.h"
#include "house_3ds.h"
#include "skeleton.h"

#define WIDTH   (800)
#define HIGH    (600)

#define HOUSE       (0)
#define MOLA        (1)
#define GIRAFFE     (2)
#define HOUSE_3DS   (3)
#define SKELETON    (4)

#define CONST_MOLA  (10)

#define TRANSLATE_CONST (0.1)
#define ANGLE_CONST     (1)
#define SCALE_CONST     (0.5)

#define TRUE    (true)
#define FALSE   (false)

using namespace std;
// --------------------  Systema ------------

//Generic* Generic_List_OBJ[SIZE_VET];
std::vector<Generic*> Generic_List_OBJ;
int it_Generic_List_OBJ;

bool draw_local_xyz = FALSE;

void desenha();
void teclado(unsigned char tecla, int x, int y);

Generic* Add_Generic_List_OBJ(int obj_type);
void Remove_Generic_List_OBJ();
void Next_Generic_List_OBJ();
void Previous_Generic_List_OBJ();

void draw_list_OBJ();
void update_values_list_OBJ();


//-----------------------------------------
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
    glPushMatrix();
        GUI::drawOrigin(0.5);
        GUI::setColor(1,0,0);
        GUI::drawFloor();
    glPopMatrix();
    if(!Generic_List_OBJ.empty()){        
        update_values_list_OBJ();
        draw_list_OBJ();
    }    
    glPushMatrix();
        glScalef(0,0,0);
        GUI::draw3ds(modelo3ds);
    glPopMatrix();
    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y) {
    //GUI::keyInit(tecla,x,y);    
    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;    
    case 'H'://AddCasa
        Add_Generic_List_OBJ(HOUSE);
        break;
    case 'M':
        Add_Generic_List_OBJ(MOLA);
        break;
    case 'X':
        Add_Generic_List_OBJ(GIRAFFE);
        break;
    case 'Z':
        Add_Generic_List_OBJ(HOUSE_3DS);
        break;
    case 'S':
        Add_Generic_List_OBJ(SKELETON);
        break;
    case 'n':
        Next_Generic_List_OBJ();
        break;
    case 'p':
        Previous_Generic_List_OBJ();
        break;
    case 'o':
        draw_local_xyz = !draw_local_xyz;
        break;
        // Translate
    case 'w':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_translate()-TRANSLATE_CONST);
        break;
    case 's':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_translate()+TRANSLATE_CONST);
        break;
    case 'a':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_translate()-TRANSLATE_CONST);
        break;
    case 'd':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_translate()+TRANSLATE_CONST);
        break;
    case 'q':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_translate()-TRANSLATE_CONST);
        break;
    case 'e':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_translate()+TRANSLATE_CONST);
        break;
        //Rotate
    case 'r':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_angle()-ANGLE_CONST);
        break;
    case 't':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_angle()+ANGLE_CONST);
        break;
    case 'f':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_angle()-ANGLE_CONST);
        break;
    case 'g':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_angle()+ANGLE_CONST);
        break;
    case 'v':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_angle()-ANGLE_CONST);
        break;
    case 'b':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_angle()+ANGLE_CONST);
        break;
        //Scale
    case 'R':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_scale()-SCALE_CONST);
        break;
    case 'T':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_scale()+SCALE_CONST);
        break;
    case 'F':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_scale()-SCALE_CONST);
        break;
    case 'G':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_scale()+SCALE_CONST);
        break;
    case 'V':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_scale()-SCALE_CONST);
        break;
    case 'B':
        if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_scale()+SCALE_CONST);
        break;
    case 'z':
        Remove_Generic_List_OBJ();
        break;
    }
    cout << "TAM:" << Generic_List_OBJ.size() << endl;
    cout << "IT:" << it_Generic_List_OBJ << endl;
}

Generic* Add_Generic_List_OBJ(int obj_type){
    Generic* add;
    switch (obj_type) {
    case HOUSE://AddCasa
        add = new House();
        break;
    case MOLA:
        add = new Mola(CONST_MOLA);
        break;
    case GIRAFFE:
        add = new Giraffe();
        break;
    case HOUSE_3DS:
        cout << "CASA 3DS DRAW" << endl;
        add = new House_3DS("");
        break;
    case SKELETON:
        add = new Skeleton("");
        break;
    }
    Generic_List_OBJ.push_back(add);
    it_Generic_List_OBJ = Generic_List_OBJ.size()-1;
    return add;
}
void Remove_Generic_List_OBJ(){
    if(!Generic_List_OBJ.empty()) Generic_List_OBJ.erase(Generic_List_OBJ.begin()+it_Generic_List_OBJ);
    Next_Generic_List_OBJ();
}
void Next_Generic_List_OBJ(){
    it_Generic_List_OBJ = it_Generic_List_OBJ>=Generic_List_OBJ.size()-1?0:it_Generic_List_OBJ+1;        
}
void Previous_Generic_List_OBJ(){
    it_Generic_List_OBJ = it_Generic_List_OBJ<=0?Generic_List_OBJ.size()-1:it_Generic_List_OBJ-1;
}

void draw_list_OBJ(){    
    for(int i=0;i<Generic_List_OBJ.size();i++){        
        glPushMatrix();        
        glTranslatef(Generic_List_OBJ[i]->get_x_translate(),Generic_List_OBJ[i]->get_y_translate(),Generic_List_OBJ[i]->get_z_translate());
        glRotatef(Generic_List_OBJ[i]->get_x_angle(),1,0,0);
        glRotatef(Generic_List_OBJ[i]->get_y_angle(),0,1,0);
        glRotatef(Generic_List_OBJ[i]->get_z_angle(),0,0,1);
        glScalef(Generic_List_OBJ[i]->get_x_scale(),Generic_List_OBJ[i]->get_y_scale(),Generic_List_OBJ[i]->get_z_scale());                
        if(i==it_Generic_List_OBJ){
            //Não consegui sobrepor a cor, então fiz outra alternativa para destacar o objeto selecionado
            glScalef(Generic_List_OBJ[i]->get_x_scale()+0.2,Generic_List_OBJ[i]->get_y_scale()+0.2,Generic_List_OBJ[i]->get_z_scale()+0.2);
        }
        if(draw_local_xyz) GUI::drawOrigin(0.3);
        Generic_List_OBJ[i]->draw();
        glPopMatrix();
    }
}

void update_values_list_OBJ(){
    Generic_List_OBJ[it_Generic_List_OBJ]->set_x_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_translate()+glutGUI::dtx);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_y_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_translate()+glutGUI::dty);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_z_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_translate()+glutGUI::dtz);

    Generic_List_OBJ[it_Generic_List_OBJ]->set_x_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_angle()+glutGUI::dax);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_y_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_angle()+glutGUI::day);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_z_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_angle()+glutGUI::daz);

    Generic_List_OBJ[it_Generic_List_OBJ]->set_x_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_scale()+glutGUI::dsx);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_y_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_scale()+glutGUI::dsy);
    Generic_List_OBJ[it_Generic_List_OBJ]->set_z_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_scale()+glutGUI::dsz);
}
