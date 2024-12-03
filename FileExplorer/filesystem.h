#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "folder.h"

struct FileSystem {
private:
	Folder* root;
public:
	void setRoot(Folder* folder);
	Folder getRoot() const;
};
#endif