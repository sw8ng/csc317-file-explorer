#ifndef SEARCHABLE_H
#define SEARCHABLE_H

#include <string>

struct Searchable {
public:
	virtual ~Searchable() {};
	virtual void search(std::string query) const = 0;
};

#endif
