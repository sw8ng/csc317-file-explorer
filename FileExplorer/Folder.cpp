#include "Folder.h"
#include <iostream>

using namespace std;

Folder::Folder(string name, Folder* parent) {
	//LinkedList objects are automatically initialized
	this->name = name;
    this->parent = parent;
}

Folder::Folder(const Folder& folder) {
    this->name = folder.name;
    this->parent = folder.parent;

    Node<File*>* fileNode = folder.files.getHead();
    while (fileNode != nullptr) {
        File* newFile = new File(*fileNode->getData());
        this->files.push_back(newFile);  
        fileNode = fileNode->getNext();
    }

    Node<Folder*>* folderNode = folder.folders.getHead();
    while (folderNode != nullptr) {
        Folder* newFolder = new Folder(*folderNode->getData());
        this->folders.push_back(newFolder); 
        folderNode = folderNode->getNext();
    }
}


void Folder::addFile(File* file) {
	this->files.push_back(file);
}

void Folder::deleteFile(File* file) {
	this->files.deleteData(file);
}

void Folder::addFolder(Folder* folder) {
	this->folders.push_back(folder);
    folder->parent = this;
}

void Folder::deleteFolder(Folder* folder) {
    folder->parent = nullptr;
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

Folder* Folder::getParent() const {
    return this->parent;
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
    if (this->searchHelper(query) == false) cout << "Search query not found" << endl;
}
bool Folder::searchHelper(string query) const {
    bool foundMatch = false;

    Node<File*>* currFile = this->files.getHead();
    while (currFile != NULL) {
        if (currFile->getData()->getName() == query) {
            cout << currFile->getData()->getName() << " in folder " << this->getName() << endl;
            foundMatch = true;
        }
    }

    if (this->getName() == query) {
        if (this->getParent() != NULL) cout << this->getName() << " in folder " << this->getParent()->getName() << endl;
        else cout << this->getName() << " is the highest folder" << endl;
        foundMatch = true;
    }

    Node<Folder*>* currFolder = this->folders.getHead();
    while (currFolder != NULL) {
        if (currFolder->getData()->searchHelper(query) == true) foundMatch = true;
        currFolder = currFolder->getNext();
    }

    return foundMatch;
}

void Folder::printHierachy() const {
    static int indentLevel = 0;

    for (int i = 0; i < indentLevel; ++i) {
        cout << "    ";
    }
    cout << "-" << this->name << endl;

    ++indentLevel;

    Node<Folder*>* folderNode = this->folders.getHead();
    while (folderNode != nullptr) {
        folderNode->getData()->printHierachy();
        folderNode = folderNode->getNext();
    }

    --indentLevel;

}

void Folder::print() const {
	cout << "Folder: " << this->name << ", Size: " << this->getSize() << " KB" << endl;

	cout << "    Files:" << endl;
	Node<File*>* fileNode = this->files.getHead();
	while (fileNode != nullptr) {
		cout << "        -";
		fileNode->getData()->print(); 
		fileNode = fileNode->getNext();
	}

	cout << "    Subfolders:" << endl;
	Node<Folder*>* folderNode = this->folders.getHead();
	while (folderNode != nullptr) {
		cout << "        -" << folderNode->getData()->getName() << ", Size: " << folderNode->getData()->getSize() << " KB" << endl;
		folderNode = folderNode->getNext();
	}
}

Node<Folder*>* Folder::getFoldersHead() const {
    return this->folders.getHead(); 
}


bool Folder::operator==(const Folder& rhs) const {
    //debug
    //bool sameName = this->getName() == rhs.getName();
    //bool sameFiles = (this->files == rhs.files);
    //bool sameFolders = (this->folders == rhs.folders);
    //cout << sameName << " " << sameFiles << " " << sameFolders << endl;
	return this->getName() == rhs.getName() && this->files == rhs.files && this->folders == rhs.folders; 
}
