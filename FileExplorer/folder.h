#ifndef FOLDER_H
#define FOLDER_H

#include "filesystemobject.h"
#include "file.h"
#include "searchable.h"
#include "linkedlist.h"

struct Folder: public FileSystemObject, punlic Searchable{
    private:
        LinkedList<File> files;
        LinkedList<Folder> folders;
    public:
        //initializes list of files and list of folders inside constructor
        Folder(std::string name = "folder_name");
        void addFile(File* file);
        void deleteFile(File* file);
        void addFolder(Folder* folder);
        void deleteFolder(Folder* folder);
        //moves file into a folder inside current folder (same level)
        void moveFile(File* file);
        //moves folder into another folder inside current folder (same level)
        void moveFolder(Folder* folder);
        //prints all files with matching name
        void getFiles(std::string query) const;
        //prints all folders with matching name
        void getFolders(std::string query) const;
};
#endif