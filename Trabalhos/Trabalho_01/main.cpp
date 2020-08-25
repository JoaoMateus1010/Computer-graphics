#include <iostream>
#include <gui.h>
#include <ctime>
#include <vector>

#include "extra.h"
#include "gui.h"

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

#define CONST_MOLA  (20)

#define TRANSLATE_CONST (0.1)
#define ANGLE_CONST     (2)
#define SCALE_CONST     (0.05)

#define TRUE    (true)
#define FALSE   (false)

#define EIXO_X (0)
#define EIXO_Y (1)
#define EIXO_Z (2)

#define TRANSLATE   (0)
#define ANGLE       (1)
#define SCALE      (2)

using namespace std;
// --------------------  System ------------

std::vector<Generic*> Generic_List_OBJ;
int it_Generic_List_OBJ;

bool draw_local_xyz = FALSE;

void desenha();
void teclado(unsigned char tecla, int x, int y);
void mouse(int button, int state, int x, int y);

Generic* Add_Generic_List_OBJ(int obj_type);
void Remove_Generic_List_OBJ();
void Next_Generic_List_OBJ();
void Previous_Generic_List_OBJ();

void draw_list_OBJ();
void update_values_list_OBJ();

void cena_01();

int EIXO_TRANSLATE_SELECTED = EIXO_X;
int EIXO_ANGLE_SELECTED = EIXO_X;
int EIXO_SCALE_SELECTED = EIXO_X;
int last_pick = TRANSLATE;

ifstream in;
ofstream out;

//---------- Cameras --------------
float eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ;
void setup_camera_1();
void setup_camera_2();
void setup_camera_3();
void setup_camera_4();
void setup_camera_5();
void setup_camera_6();
void setup_camera_7();
void setup_camera_0();

Model3DS modelo3ds = Model3DS("../Trabalho_01/3ds/Cottage_FREE.3DS");
Generic* tem = new Generic();

int main(){            
    GUI gui =  GUI(WIDTH,HIGH,desenha,teclado,mouse);
    cout << "Programa em execução" << endl;
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
void mouse(int button, int state, int x, int y){
    GUI::mouseButtonInit(button,state,x,y);
    glutGUI::mouseMove(x,y);
    //cout << "("<<glutGUI::last_x/(WIDTH/5)<<","<<glutGUI::last_y/(HIGH/5)<<")" << endl;
    bool flag_time_double_click = false;
    if(button==0){
        if(state==0){
            if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                EIXO_TRANSLATE_SELECTED=EIXO_Y;
            }else if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                EIXO_TRANSLATE_SELECTED=EIXO_Z;
            }else{
                EIXO_TRANSLATE_SELECTED=EIXO_X;
            }
            last_pick = TRANSLATE;
            //cout<<"press ON left" <<endl;
        }
    }
    if(button==2){
        if(state==0){
            if(EIXO_ANGLE_SELECTED==EIXO_X){
                EIXO_ANGLE_SELECTED=EIXO_Y;
            }else if(EIXO_ANGLE_SELECTED==EIXO_Y){
                EIXO_ANGLE_SELECTED=EIXO_Z;
            }else{
                EIXO_ANGLE_SELECTED=EIXO_X;
            }
            last_pick = ANGLE;
            cout << EIXO_ANGLE_SELECTED <<endl;
            cout<<"press ON b right" <<endl;
        }
    }
    if(button==1){
        if(state==0){
            if(EIXO_SCALE_SELECTED==EIXO_X){
                EIXO_SCALE_SELECTED=EIXO_Y;
            }else if(EIXO_SCALE_SELECTED==EIXO_Y){
                EIXO_SCALE_SELECTED=EIXO_Z;
            }else{
                EIXO_SCALE_SELECTED=EIXO_X;
            }
            last_pick = SCALE;
            //cout<<"press ON b middle" <<endl;
        }
    }
    if(button==3){
        if(state==0){
            switch (last_pick) {
            case TRANSLATE:
                if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_translate()+TRANSLATE_CONST);
                }
                if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_translate()+TRANSLATE_CONST);
                }
                if(EIXO_TRANSLATE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_translate()+TRANSLATE_CONST);
                }
                break;
            case ANGLE:
                if(EIXO_ANGLE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_angle()+ANGLE_CONST);
                }
                if(EIXO_ANGLE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_angle()+ANGLE_CONST);
                }
                if(EIXO_ANGLE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_angle()+ANGLE_CONST);
                }
                break;
            case SCALE:
                if(EIXO_SCALE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_scale()+SCALE_CONST);
                }
                if(EIXO_SCALE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_scale()+SCALE_CONST);
                }
                if(EIXO_SCALE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_scale()+SCALE_CONST);
                }
                break;
            }
            //cout<<"scroll up ON" <<endl;
        }
    }
    if(button==4){
        if(state==0){
            switch (last_pick) {
            case TRANSLATE:
                if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_translate()-TRANSLATE_CONST);
                }
                if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_translate()-TRANSLATE_CONST);
                }
                if(EIXO_TRANSLATE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_translate(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_translate()-TRANSLATE_CONST);
                }
                break;
            case ANGLE:
                if(EIXO_ANGLE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_angle()-ANGLE_CONST);
                }
                if(EIXO_ANGLE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_angle()-ANGLE_CONST);
                }
                if(EIXO_ANGLE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_angle(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_angle()-ANGLE_CONST);
                }
                break;
            case SCALE:
                if(EIXO_SCALE_SELECTED==EIXO_X){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_x_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_x_scale()-SCALE_CONST);
                }
                if(EIXO_SCALE_SELECTED==EIXO_Y){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_y_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_y_scale()-SCALE_CONST);
                }
                if(EIXO_SCALE_SELECTED==EIXO_Z){
                    if (!Generic_List_OBJ.empty()) Generic_List_OBJ[it_Generic_List_OBJ]->set_z_scale(Generic_List_OBJ[it_Generic_List_OBJ]->get_z_scale()-SCALE_CONST);
                }
                break;
            }
            //cout<<"scroll down ON" <<endl;
        }
    }
    //cout<<button<<endl;
    //cout<<state<<endl;
}
void teclado(unsigned char tecla, int x, int y) {           
    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;    
    case 'H':
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
    case '1':
        setup_camera_1();
        break;
    case '2':
        setup_camera_2();
        break;
    case '3':
        setup_camera_3();
        break;
    case '4':
        setup_camera_4();
        break;
    case '5':
        setup_camera_5();
        break;
    case '6':
        setup_camera_6();
        break;
    case '7':
        setup_camera_7();
        break;
    case '0':
        setup_camera_0();
        break;
    case '8': //SALVAR
        std::cout << "SALVAR"<<endl;
        if(!Generic_List_OBJ.empty()){
            out.open("Generic_List_OBJ",ios::app);
            for(int i=0;i<Generic_List_OBJ.size();i++){
                out<<*Generic_List_OBJ[i];
                cout<<endl<<typeid(Generic_List_OBJ[i]).name()<<endl;
            }
            out.close();
        }
        break;
    case '9'://LOAD

        break;
    case '>'://Carrega modelos
        if(!Generic_List_OBJ.empty()) Generic_List_OBJ.clear();
        cena_01();
        break;
    case '<'://limpa tudo
        Generic_List_OBJ.clear();
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
        add = new House_3DS();
        break;
    case SKELETON:
        add = new Skeleton();
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
void cena_01(){
    Generic* house1 =  new House(-6.1,-1.49012e-09,2.5,0,90,0,1,1,1);
    Generic* house2 =  new House(0,0,-6.6,0,0,0,1,1,1);
    Generic* house3 =  new House(5.9,0,0,2,-88,2,1,1,1);
    Generic* house4 =  new House(-3.7,0,-7.3,0,0,0,1,1,1);
    Generic* house5 =  new House(3.1,0,-6.9,0,0,0,1,1,1);
    Generic* house6 =  new House(-6.6,0,-7.4,0,0,0,1,1,1);
    Generic* house7 =  new House(-6.7,0.1,-0.0999999,-2,90,0,1,1.3,1.05);
    Generic* house8 =  new House(6,1.3411e-08,-3.4,-2,-88,-2,1.05,1.25,1.15);

    Generic_List_OBJ.push_back(house1);
    Generic_List_OBJ.push_back(house2);
    Generic_List_OBJ.push_back(house3);
    Generic_List_OBJ.push_back(house4);
    Generic_List_OBJ.push_back(house5);
    Generic_List_OBJ.push_back(house6);
    Generic_List_OBJ.push_back(house7);
    Generic_List_OBJ.push_back(house8);

    Generic* giraffe1 = new Giraffe(-0.7,0.2,-5.5,0,-90,-2,1.05,1.3,-1.1);
    Generic* giraffe2 = new Giraffe(-4.7,0,-3,0,0,24,1,1,1);

    Generic_List_OBJ.push_back(giraffe1);
    Generic_List_OBJ.push_back(giraffe2);

    Generic* house_3ds1 = new House_3DS(2.1,0.2,4.1,0,0,0,1.75,2.1,1.5);

    Generic_List_OBJ.push_back(house_3ds1);

}
void setup_camera_1(){
    glutGUI::cam->e.x = 15;
    glutGUI::cam->e.y = 15;
    glutGUI::cam->e.z = 15;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_2(){
    glutGUI::cam->e.x = 1;
    glutGUI::cam->e.y = 25;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_3(){
    glutGUI::cam->e.x = 25;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_4(){
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 25;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_5(){
    glutGUI::cam->e.x = -25;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = -25;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_6(){
    glutGUI::cam->e.x = 30;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_7(){
    glutGUI::cam->e.x = 1;
    glutGUI::cam->e.y = -20;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void setup_camera_0(){
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 10;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 1;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
