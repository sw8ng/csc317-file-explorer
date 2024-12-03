#ifndef FILE_H
#define FILE_H

#include "filesystemobject.h"

struct File : public FileSystemObject {
private:
	int size;
	std::string type;
public:
	File(std::string name = "file_name", int size = -1, std::string type = "unknown");
	File(const File& file);
	int getSize() const;
	void setSize(int size);
	std::string getType() const;
	void setType(std::string type);
	void print() const;
	bool operator==(const File& rhs) const;
};

#endif