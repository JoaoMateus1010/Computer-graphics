#include "mola.h"

Mola::Mola(float mola_constante){
    this->mola_constante=PI*mola_constante;
}
Mola::~Mola(){

}
void Mola::draw(){
    std::cout<<"print pela mola"<<endl;
}
float Mola::get_mola_constante(){
    return this->mola_constante;
}
void Mola::set_mola_constante(float mola_constante){
    this->mola_constante=mola_constante;
}
