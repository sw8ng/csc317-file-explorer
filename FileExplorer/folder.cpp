#include "folder.h"
#include <iostream>

using namespace std;

Folder::Folder(string name){
    //LinkedList objects are automatically initialized
    this->name = name;
}

void Folder::addFile(File file){
    this->files.push_back(file);
}

void Folder::deleteFile(File file){
    this->files.deleteData(file);
}

void Folder::addFolder(Folder folder){
    this->folders.push_back(folder);
}

void Folder::deleteFolder(Folder folder){
    this->folders.deleteData(folder);
}

void Folder::moveFile(File file){

}

void Folder::moveFolder(Folder folder){
}

void Folder::getFiles(string name) const{
    cout << endl;
}

void Folder::getFolders(string name) const{
    cout << endl;
}

void Folder::search(string query) const{
    this->getFiles(query);
    this->getFolders(query);
}

void Folder::print() const {
    cout << "Folder: " << this->name << endl;
}