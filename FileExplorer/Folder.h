#ifndef FOLDER_H
#define FOLDER_H

#include "FileSystemObject.h"
#include "File.h"
#include "Searchable.h"
#include "LinkedList.h"

struct Folder : public FileSystemObject, public Searchable {
private:
	LinkedList<File*> files;
	LinkedList<Folder*> folders;
	Folder* parent;
	bool searchHelper(std::string query) const;
public:
	//initializes list of files and list of folders inside constructor
	Folder(std::string name = "folder_name", Folder* parent = nullptr);
	Folder(const Folder& folder);
	void addFile(File* file);
	void deleteFile(File* file);
	void addFolder(Folder* folder);
	void deleteFolder(Folder* folder);
	//moves file into a folder inside current folder (same level)
	void moveFile(const std::string& fileName, const std::string& dest);
	//moves folder into another folder inside current folder (same level)
	void moveFolder(const std::string& folderName, const std::string& dest);
	//prints all files with matching name
	File* getFile(std::string query);
	//prints all folders with matching name
	Folder* getFolder(std::string query);
	Folder* getParent() const;
	int getSize() const;
	void search(std::string query)const;
	void printHierachy() const;
	void print() const;
	Node<Folder*>* getFoldersHead() const;
	bool operator==(const Folder& rhs) const;
};
#endif
