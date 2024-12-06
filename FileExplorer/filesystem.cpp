#include "FileSystem.h"
#include <iostream>

using namespace std;

FileSystem::FileSystem(){
    Folder * newFolder = new Folder("Home");
    Folder* documentsFolder = new Folder("Documents");
    Folder* downloadsFolder = new Folder("Downloads");
    newFolder->addFolder(documentsFolder);
    newFolder->addFolder(downloadsFolder);
    this->root = newFolder; 
}

FileSystem::FileSystem(Folder* folder){
    this->root = folder;
}

void FileSystem::setRoot(Folder* folder){
    this->root = folder;
}

Folder*  FileSystem::getRoot() const{
    return this->root;
}

