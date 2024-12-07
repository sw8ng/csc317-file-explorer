#include "FileSystem.h"
#include <iostream>

using namespace std;

FileSystem::FileSystem(){
    Folder * newFolder = new Folder("Home");
    Folder* desktopFolder = new Folder("Desktop");
    Folder* downloadsFolder = new Folder("Downloads");
    Folder* documentsFolder = new Folder("Documents");
    Folder* picturesFolder = new Folder("Pictures");
    Folder* musicFolder = new Folder("Music");
    Folder* videosFolder = new Folder("Videos");

    newFolder->addFolder(desktopFolder);
    newFolder->addFolder(downloadsFolder);
    newFolder->addFolder(documentsFolder);
    newFolder->addFolder(picturesFolder);
    newFolder->addFolder(musicFolder);
    newFolder->addFolder(videosFolder);

    Folder* reportsFolder = new Folder("Reports");
    Folder* slidesFolder = new Folder("Slides");
    documentsFolder->addFolder(reportsFolder);
    documentsFolder->addFolder(slidesFolder);
    this->root = newFolder; 
}

FileSystem::FileSystem(Folder* folder){
    this->root = folder;
}

Folder* FileSystem::getFolder(Folder* currentFolder, const string& name) const {
    if (currentFolder->getName() == name) {
        return currentFolder;
    }

    Node<Folder*>* folderNode = currentFolder->getFoldersHead();
    while (folderNode != nullptr) {
        Folder* foundFolder = getFolder(folderNode->getData(), name);
        if (foundFolder != nullptr) {
            return foundFolder;
        }
        folderNode = folderNode->getNext();
    }
    return nullptr;
}

void FileSystem::setRoot(Folder* folder){
    this->root = folder;
}

Folder*  FileSystem::getRoot() const{
    return this->root;
}

void FileSystem::search(std::string query)const {

}