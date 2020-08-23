#include "skeleton.h"
Skeleton::Skeleton(){

}
Skeleton::Skeleton(string path){
    this->set_path(path);
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
