#include "folder.h"
#include <iostream>

using namespace std;

Folder::Folder(string name) {
	//LinkedList objects are automatically initialized
	this->name = name;
}

Folder::Folder(const Folder& folder) {
	this->name = folder.name;
	this->files = folder.files;
	this->folders = folder.folders;
}

void Folder::addFile(File* file) {
	this->files.push_back(file);
}

void Folder::deleteFile(File* file) {
	this->files.deleteData(file);
}

void Folder::addFolder(Folder* folder) {
	this->folders.push_back(folder);
}

void Folder::deleteFolder(Folder* folder) {
	this->folders.deleteData(folder);
}

void Folder::moveFile(const string& fileName, const string& dest) {
    Node<File*>* currFileNode = this->files.getHead();
    File* fileToMove = nullptr;

    while (currFileNode != nullptr) {
        if (currFileNode->getData()->getName() == fileName) {
            fileToMove = currFileNode->getData();
            break;
        }
        currFileNode = currFileNode->getNext();
    }

    if (fileToMove != nullptr) {
        Node<Folder*>* currFolderNode = this->folders.getHead();
        Folder* destFolder = nullptr;

        while (currFolderNode != nullptr) {
            if (currFolderNode->getData()->getName() == dest) {
                destFolder = currFolderNode->getData();
                break;
            }
            currFolderNode = currFolderNode->getNext();
        }

        if (destFolder != nullptr) {
            destFolder->addFile(fileToMove); 
            cout << "File added to folder: " << dest << endl;

            this->deleteFile(fileToMove);
            cout << "File removed from folder: " << this->getName() << endl;
        }
        else {
            cout << "Subfolder with name " << dest << " not found!" << endl;
        }
    }
    else {
        cout << "File with name " << fileName << " not found!" << endl;
    }
}

void Folder::moveFolder(const string& folderName, const string& dest) {
    Node<Folder*>* currFolderNode = this->folders.getHead();
    Folder* folderToMove = nullptr;

    while (currFolderNode != nullptr) {
        if (currFolderNode->getData()->getName() == folderName) {
            folderToMove = currFolderNode->getData();
            break;
        }
        currFolderNode = currFolderNode->getNext();
    }

    if (folderToMove != nullptr) {
        Node<Folder*>* currDestNode = this->folders.getHead();
        Folder* destFolder = nullptr;

        while (currDestNode != nullptr) {
            if (currDestNode->getData()->getName() == dest) {
                destFolder = currDestNode->getData();
                break;
            }
            currDestNode = currDestNode->getNext();
        }

        if (destFolder != nullptr) {
            destFolder->addFolder(folderToMove); 
            cout << "Folder moved to: " << dest << endl;

            this->deleteFolder(folderToMove);
            cout << "Folder removed from folder: " << this->getName() << endl;
        }
        else {
            cout << "Destination folder with name " << dest << " not found!" << endl;
        }
    }
    else {
        cout << "Folder with name " << folderName << " not found!" << endl;
    }
}


File* Folder::getFile(string name) {
	Node<File*>* fileNode = this->files.getHead();

	while (fileNode != nullptr) {
		if (fileNode->getData()->getName() == name) {
			return fileNode->getData(); 
		}
		fileNode = fileNode->getNext();
	}

	cout << "No file with name " << name << " found in folder " << this->getName() << "." << endl;
	return nullptr; 
}



Folder* Folder::getFolder(string name) {
	Node<Folder*>* folderNode = this->folders.getHead();

	while (folderNode != nullptr) {
		if (folderNode->getData()->getName() == name) {
			return folderNode->getData();
		}
		folderNode = folderNode->getNext();
	}

	cout << "No folder with name " << name << " found in folder " << this->getName() << "." << endl;
	return nullptr;
}


int Folder::getSize() const {
	int totalSize = 0;

	Node<File*>* fileNode = this->files.getHead();
	while (fileNode != nullptr) {
		totalSize += fileNode->getData()->getSize(); 
		fileNode = fileNode->getNext();
	}

	Node<Folder*>* folderNode = this->folders.getHead();
	while (folderNode != nullptr) {
		totalSize += folderNode->getData()->getSize();
		folderNode = folderNode->getNext();
	}

	return totalSize;
}

void Folder::search(string query) const {

}

void Folder::print() const {
	cout << "Folder: " << this->name << ", Size: " << this->getSize() << " bytes" << endl;

	cout << "    Files:" << endl;
	Node<File*>* fileNode = this->files.getHead();
	while (fileNode != nullptr) {
		cout << "        ";
		fileNode->getData()->print(); 
		fileNode = fileNode->getNext();
	}

	cout << "    Subfolders:" << endl;
	Node<Folder*>* folderNode = this->folders.getHead();
	while (folderNode != nullptr) {
		cout << "        " << folderNode->getData()->getName() << ", Size: " << folderNode->getData()->getSize() << " bytes" << endl;
		folderNode = folderNode->getNext();
	}
}


bool Folder::operator==(const Folder& rhs) const {
    //bool sameName = this->getName() == rhs.getName();
    //bool sameFiles = (this->files == rhs.files);
    //bool sameFolders = (this->folders == rhs.folders);
    //cout << sameName << " " << sameFiles << " " << sameFolders << endl;
	return this->getName() == rhs.getName() && this->files == rhs.files && this->folders == rhs.folders; 
}