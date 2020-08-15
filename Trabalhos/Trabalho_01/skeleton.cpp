#include "skeleton.h"
Skeleton::Skeleton(){

}
Skeleton::Skeleton(string path){
    this->set_path(path);
}
Skeleton::~Skeleton(){

}
void Skeleton::draw(){
    std::cout<<"Print pelo Skeletonro"<<endl;
    std::cout<<this->get_path()<<endl;
}
void Skeleton::correcao(){
    std::cout<<"Correção do Skeletonro"<<endl;
}
