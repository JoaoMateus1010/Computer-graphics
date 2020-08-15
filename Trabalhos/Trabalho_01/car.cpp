#include "car.h"
Car::Car(){

}
Car::Car(string path){
    this->set_path(path);
}
Car::~Car(){

}
void Car::draw(){
    std::cout<<"Print pelo Carro"<<endl;
    std::cout<<this->get_path()<<endl;
}
void Car::correcao(){
    std::cout<<"Correção do Carro"<<endl;
}
