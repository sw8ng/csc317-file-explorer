#ifndef GETMENUCHOICE_H
#define GETMENUCHOICE_H

#include "FileSystem.h"

enum Actions {QUIT, ADD, REMOVE, MOVE, COPY, BACK, OPEN, SEARCH, SORT_SIZE, SORT_NAME};

const int min_menu = 1;
const int max_menu = SEARCH;

int getMenuChoice();
Folder* getStartingFolder(FileSystem* fileSystem);
Folder* openSubFolder(Folder* currentFolder);
void addFileOrFolder(Folder* currentFolder);
void deleteFileOrFolder(Folder* currentFolder);
void moveFileOrFolder(Folder* currentFolder);
void copyFileOrFolder(Folder* currentFolder);
void fileSystemStart();

#endif 