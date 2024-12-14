#ifndef FILE_H
#define FILE_H

#include "FileSystemObject.h"

struct File : public FileSystemObject {
private:
	int size;
	FileSystemObject *parent;
	std::string type;
public:
	File(std::string name = "file_name", int size = -1, std::string type = "unknown", FileSystemObject *parent = nullptr);
	File(const File& file);
	int getSize() const;
	void setSize(int size);
	std::string getType() const;
	void setType(std::string type);
	FileSystemObject* getParent() const;
	void setParent(FileSystemObject* parent);
	void print() const;
	bool operator==(const File& rhs) const;
};

#endif
