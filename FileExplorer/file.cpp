#include "file.h"
#include <iostream>

using namespace std;

File::File(string name, int size, string type){
    (*this).name = name;
    (*this).size = size;
    (*this).type = type;
}

int File::getSize() const{
    return (*this).size;
}

void File::setSize(int size){
    (*this).size = size;
}

string File::getType() const{
    return (*this).type;
}

void File::setType(string type){
    (*this).type = type;
}

void File::print() const{
    cout << "File: " << name << ", Size: " << " bytes, Type: " << type << endl;
}
