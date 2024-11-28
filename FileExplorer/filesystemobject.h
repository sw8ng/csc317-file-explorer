#ifndef FILESYSTEMOBJECT_H
#define FILESYSTEMOBJECT_H
#include <string>

struct FileSystemObject{
    protected:
        std::string name;
    public:
        virtual ~FileSystemObject();
        //pure virtual function
        virtual void print() const = 0; 
        std::string getName() const{
            return name;
        }
        void setName(std::string newName){
            name = newName;
        }
};

#endif