#include "File.h"
#include <iostream>

using namespace std;


File::File(string name, int size, string type, FileSystemObject* parent) {
	this->name = name;
	this->size = size;
	this->type = type;
	this->parent = parent;
}

File::File(const File& file) {
	this->name = file.name;
	this->size = file.size;
	this->type = file.type;
	this->parent = file.parent;
}

int File::getSize() const {
	return this->size;
}

void File::setSize(int size) {
	this->size = size;
}

string File::getType() const {
	return this->type;
}

void File::setType(string type) {
	this->type = type;
}

FileSystemObject* File::getParent() const {
	return this->parent;
}

void File::setParent(FileSystemObject* parent) {
	this->parent = parent;
}

void File::print() const {
	cout << name << ", Size: " << size << " KB, Type: " << type << endl;
}

bool File::operator==(const File& rhs) const {
	return (this->name == rhs.getName()) && (this->size == rhs.getSize()) && (this->type == rhs.getType());
}

