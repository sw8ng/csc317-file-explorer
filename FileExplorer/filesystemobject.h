#ifndef FILESYSTEMOBJECT_H
#define FILESYSTEMOBJECT_H
#include <string>

struct FileSystemObject {
protected:
	std::string name;
public:
	virtual ~FileSystemObject() {};
	virtual void print() const = 0;
	std::string getName() const {
		return this->name;
	}
	void setName(std::string newName) {
		this->name = newName;
	}
};

#endif