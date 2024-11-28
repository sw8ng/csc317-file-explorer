#include "folder.h"
#include <iostream>

using namespace std;

Folder::Folder(string name){
    //to-do: initialize linkedlists
    (*this).name = name;
}

void Folder::addFile(File* file){

}

void Folder::deleteFile(File* file){

}

void Folder::addFolder(Folder* folder){

}

void Folder::deleteFolder(Folder* folder){

}

void Folder::moveFile(File* file){

}

void Folder::moveFolder(Folder* folder){
}

void Folder::getFiles(string name) const{
    cout << endl;
}

void Folder::getFolders(string name) const{
    cout << endl;
}

void search(string query){
    getFiles(query);
    getFolders(query);
}
