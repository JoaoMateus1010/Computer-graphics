#include "generic.h"
Generic::Generic(float x_translate,float y_translate,float z_translate,float x_angle,float y_angle,float z_angle,float x_scale,float y_scale,float z_scale){
    this->x_translate = x_translate;
    this->y_translate = y_translate;
    this->z_translate = z_translate;
    this->x_angle = x_angle;
    this->y_angle = y_angle;
    this->z_angle = z_angle;
    this->x_scale = x_scale;
    this->y_scale = y_scale;
    this->z_scale = z_scale;
}
Generic::Generic(){
    this->x_translate = 0.0;
    this->y_translate = 0.0;
    this->z_translate = 0.0;
    this->x_angle = 0.0;
    this->y_angle = 0.0;
    this->z_angle = 0.0;
    this->x_scale = 1.0;
    this->y_scale = 1.0;
    this->z_scale = 1.0;
}
Generic::~Generic(){

}
void Generic::draw(){
    std::cout<<"Print pelo Generico"<<endl;
}
void Generic::set_x_translate(float x_translate){
    this->x_translate=x_translate;
}
void Generic::set_y_translate(float y_translate){
    this->y_translate=y_translate;
}
void Generic::set_z_translate(float z_translate){
    this->z_translate=z_translate;
}
void Generic::set_x_angle(float x_angle){
    this->x_angle=x_angle;
}
void Generic::set_y_angle(float y_angle){
    this->y_angle=y_angle;
}
void Generic::set_z_angle(float z_angle){
    this->z_angle=z_angle;
}
void Generic::set_x_scale(float x_scale){
    this->x_scale=x_scale;
}
void Generic::set_y_scale(float y_scale){
    this->y_scale=y_scale;
}
void Generic::set_z_scale(float z_scale){
    this->z_scale=z_scale;
}

float Generic::get_x_translate(){
    return this->x_translate;
}
float Generic::get_y_translate(){
    return this->y_translate;
}
float Generic::get_z_translate(){
    return this->z_translate;
}
float Generic::get_x_angle(){
    return this->x_angle;
}
float Generic::get_y_angle(){
    return this->y_angle;
}
float Generic::get_z_angle(){
    return this->z_angle;
}
float Generic::get_x_scale(){
    return this->x_scale;
}
float Generic::get_y_scale(){
    return this->y_scale;
}
float Generic::get_z_scale(){
    return this->z_scale;
}
string float_to_string(float number){
    ostringstream ss;
    ss<<number;
    string s = ss.str();
    return s;
}
istream& operator >> (istream& is,Generic& obj){
    is>>obj.x_translate;
    is>>obj.y_translate;
    is>>obj.z_translate;
    is>>obj.x_angle;
    is>>obj.y_angle;
    is>>obj.z_angle;
    is>>obj.x_scale;
    is>>obj.y_scale;
    is>>obj.z_scale;
    return is;
}
ostream& operator << (ostream& os, const Generic& obj){
    os << obj.x_translate << " " <<  obj.y_translate << " " <<  obj.z_translate << " " <<  obj.x_angle << " " << obj.y_angle << " " <<  obj.z_angle << " " <<  obj.x_scale << " " <<  obj.y_scale << " " <<  obj.z_scale<<"\n";
    return os;
}
void Generic::saveInFile(){

}
Generic* loadFromFile(){

}

