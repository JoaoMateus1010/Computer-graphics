#include "house_3ds.h"
House_3DS::House_3DS(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz){
    this->set_x_translate(dx);
    this->set_y_translate(dy);
    this->set_z_translate(dz);
    this->set_x_angle(ax);
    this->set_y_angle(ay);
    this->set_z_angle(az);
    this->set_x_scale(sx);
    this->set_y_scale(sy);
    this->set_z_scale(sz);
}
House_3DS::House_3DS(){

}
House_3DS::~House_3DS(){

}
void House_3DS::draw(){    
    Model3DS m3ds = Model3DS("../Trabalho_01/3ds/Cottage_FREE.3DS");
    GUI::draw3ds(m3ds);
    //GUI::drawOrigin(0.3);
}
void House_3DS::correcao(){
    std::cout<<"Correção da Casa 3ds"<<endl;
}
