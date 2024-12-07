#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "folder.h"

struct FileSystem : public Searchable{
private:
	Folder* root;
public:
	FileSystem();
	FileSystem(Folder* folder);
	void setRoot(Folder* folder);
	Folder* getRoot() const;
	Folder* getFolder(Folder* currentFolder, const std::string& name) const;
	void search(std::string query)const;
};
#endif