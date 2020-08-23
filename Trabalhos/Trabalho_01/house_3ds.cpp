#include "house_3ds.h"
House_3DS::House_3DS(){

}
House_3DS::House_3DS(string path){
    this->set_path(path);
}
House_3DS::~House_3DS(){

}
void House_3DS::draw(){
    Model3DS m3ds = Model3DS("../Trabalho_01/3ds/Cottage_FREE.3DS");
    GUI::draw3ds(m3ds);
    GUI::drawOrigin(0.3);
}
void House_3DS::correcao(){
    std::cout<<"Correção da Casa 3ds"<<endl;
}
