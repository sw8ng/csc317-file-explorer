#include "file.h"
#include <iostream>

using namespace std;


File::File(string name, int size, string type) {
	this->name = name;
	this->size = size;
	this->type = type;
}

File::File(const File& file) {
	this->name = file.name;
	this->size = file.size;
	this->type = file.type;
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

void File::print() const {
	cout << name << ", Size: " << size << " bytes, Type: " << type << endl;
}

bool File::operator==(const File& rhs) const {
	return (this->name == rhs.getName()) && (this->size == rhs.getSize()) && (this->type == rhs.getType());
}

