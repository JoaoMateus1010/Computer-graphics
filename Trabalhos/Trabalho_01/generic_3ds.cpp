#include "generic_3ds.h"

Generic_3ds::Generic_3ds(string path){
    this->path=path;
}
Generic_3ds::Generic_3ds(){

}
Generic_3ds::~Generic_3ds(){

}
void Generic_3ds::set_path(string path){
    this->path=path;
}
string Generic_3ds::get_path(){
    return this->path;
}
