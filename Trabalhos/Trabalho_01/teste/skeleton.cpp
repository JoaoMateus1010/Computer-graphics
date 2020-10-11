#include "skeleton.h"
Skeleton::Skeleton(float dx,float dy,float dz,float ax,float ay,float az,float sx,float sy,float sz){
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
Skeleton::Skeleton(){

}
Skeleton::~Skeleton(){

}
void Skeleton::draw(){
    //std::cout<<"Print pelo Skeletonro"<<endl;
    Model3DS m3ds = Model3DS("../Trabalho_01/3ds/skeleton.3DS");
    //GUI::drawOrigin(0.3);
    correcao();    
    GUI::draw3ds(m3ds);    

}
void Skeleton::correcao(){
    glTranslatef(0,0.42,0);
    glRotatef(90,1,0,0);
    glScalef(20,20,20);
}
