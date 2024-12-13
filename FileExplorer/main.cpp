#include <iostream>
#include <string>
#include <sstream> 
#include "FileSystem.h"
#include "LinkedList.h"

using namespace std;

enum Actions {QUIT, ADD, REMOVE, MOVE, COPY, BACK, OPEN, SEARCH, SORT_SIZE, SORT_NAME};

const int min_menu = 1;
const int max_menu = SEARCH;

int getMenuChoice();
Folder* getStartingFolder(FileSystem* fileSystem);
Folder* openSubFolder(Folder* currentFolder);
void addFileOrFolder(Folder* currentFolder);
void deleteFileOrFolder(Folder* currentFolder);
void moveFileOrFolder(Folder* currentFolder);
void copyFileOrFolder(Folder* currentFolder);

int main() {
	int choice;
	string folderName, type = "";
	Folder* currentFolder = new Folder;
	FileSystem* fileSystem = new FileSystem;
	cout << "Folder Structure: \n" << endl;
	fileSystem->getRoot()->printHierachy();
	
	currentFolder = getStartingFolder(fileSystem);

	do
	{
		cout << endl;
		currentFolder->print();
		choice = getMenuChoice();

		string query;
		switch (choice)
		{
			case QUIT:
				cout << "Thank you for using File Explorer!" << endl;
				break;
			case ADD:
				addFileOrFolder(currentFolder);
				break;
			case REMOVE:
				deleteFileOrFolder(currentFolder);
				break;
			case MOVE:
				moveFileOrFolder(currentFolder);
				break;
			case COPY:
				copyFileOrFolder(currentFolder);
				break;
			case BACK:
				if (currentFolder->getParent() == nullptr) {
					cout << "You are already at the root folder." << endl;
				}else {
					currentFolder = currentFolder->getParent();
					cout << "\nYou're now exploring the " << currentFolder->getName() << " folder." << endl;
				}
				break;
			case OPEN:
				currentFolder = openSubFolder(currentFolder);
				break;
			case SEARCH:
				cout << "Please enter search query: ";
				cin >> query;
				cout << endl;

				currentFolder->search(query);
				break;
			case SORT_SIZE:
			case SORT_NAME:
				cout << "Coming soon!" << endl;
				break;
		}
	}
	while (choice != QUIT);

	return 0;
}

int getMenuChoice(){
	bool validChoice = false;
	int choice;
	while (!validChoice) {
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "OPTIONS MENU: " << endl;
		cout << " (" << ADD << ") Add a file or subfolder to current folder" << endl;
		cout << " (" << REMOVE << ") Remove a file or subfolder in current folder" << endl;
		cout << " (" << MOVE << ") Move file or subfolder into a folder in current folder" << endl;
		cout << " (" << COPY << ") Copy file or subfolder in current folder" << endl;
		cout << " (" << BACK << ") Go to parent folder of current folder (if at root does nothing)" << endl;
		cout << " (" << OPEN << ") Open a subfolder in current folder" << endl;
		cout << " (" << SEARCH << ") Search for files and folders by name" << endl;
		cout << " (" << SORT_SIZE << ") Sort files inside current folder by size" << endl;
		cout << " (" << SORT_NAME << ") Sort files inside current folder by name" << endl;
		cout << "Enter a number from " << min_menu << " to " << max_menu << ", or 0 to exit: " << endl;

		cin >> choice;
		cout << endl;

		if (!(choice < min_menu) || !(choice > max_menu)) {
			validChoice = true;
		}else {
			cout << "ERROR! Input must be a number from " << min_menu << " to " << max_menu << ", or 0 to exit." << endl;
		}
	}
	   return choice;
}

Folder* getStartingFolder(FileSystem* fileSystem) {
	string folderName = "";
	Folder* currentFolder = nullptr;
	bool validName = false;
	cout << "\nWhere would you like to start exploring? Please enter the folder name: " << endl;

	while (!validName) {
		getline(cin, folderName);

		currentFolder = fileSystem->getFolder(fileSystem->getRoot(), folderName);

		if (currentFolder != nullptr) {
			cout << "\nYou're now exploring the " << folderName << " folder." << endl;
			validName = true;
		}
		else {
			cout << "Folder \"" << folderName << "\" not found. Please enter a valid folder name : " << endl;
		}
	}
	return currentFolder;
}

Folder* openSubFolder(Folder* currentFolder) {
	string folderName = "";
	Folder* temp = nullptr;

	if (currentFolder->getFoldersHead() == nullptr) {
		cout << "The current folder has no subfolders." << endl;
		return currentFolder;
	}

	cout << "Enter the name of the subfolder to open: " << endl;
	cin.ignore();
	getline(cin, folderName);

	temp = currentFolder->getFolder(folderName);

	if (temp != nullptr) {
		cout << "\nYou're now exploring the " << folderName << " folder." << endl;
		return temp;
	}
	else {
		cout << "Subfolder not found. Returning to the current folder." << endl;
		return currentFolder;
	}
}

void addFileOrFolder(Folder* currentFolder) {
	string type;

	cout << "Enter the type of item you want to add: (File/Folder): " << endl;
	cin >> type;

	if (type == "File" || type == "file") {
		string fileName;
		int fileSize;
		string fileType = "Unknown";

		cout << "\nEnter the file name (e.g., example.txt): " << endl;
		cin >> fileName;
		cout << "\nEnter the file size (in KB): " << endl;
		cin >> fileSize;

		size_t dotPos = fileName.find_last_of(".");
		if(dotPos != string::npos) {
			string extension = fileName.substr(dotPos + 1);
			if (extension == "txt") {
				fileType = "Text";
			}
			else if (extension == "h") {
				fileType = "Header";
			}
			else if (extension == "cpp") {
				fileType = "Source Code";
			}
			else if (extension == "mp3") {
				fileType = "Audio";
			}
			else if (extension == "jpg" || extension == "png") {
				fileType = "Image";
			}
			else if (extension == "css") {
				fileType = "CSS Stylesheet";
			}
			else if (extension == "js") {
				fileType = "JavaScript";
			}
			else if (extension == "html" || extension == "htm") {
				fileType = "HTML";
			}
			else if (extension == "csv") {
				fileType = "CSV (Comma Separated Values)";
			}
			else if (extension == "pdf") {
				fileType = "PDF Document";
			}
			else if (extension == "zip") {
				fileType = "ZIP Archive";
			}
			else if (extension == "gif") {
				fileType = "GIF Image";
			}

		}

		File* newFile = new File(fileName, fileSize, fileType);
		currentFolder->addFile(newFile);

		cout << "File \"" << fileName << "\" of type \"" << fileType << "\" and size "
			<< fileSize << " KB added successfully." << endl;
	}else if (type == "Folder" || type == "folder") {
		string folderName;
		cout << "\nEnter the name of the new folder: " << endl;
		cin.ignore();
		getline(cin, folderName);

		Folder* newFolder = new Folder(folderName, currentFolder);
		currentFolder->addFolder(newFolder);

		cout << "Folder \"" << folderName << "\" added successfully." << endl;
	}else {
		cout << "\nInvalid input. Please enter 'File' or 'Folder'." << endl;
	}
}

void deleteFileOrFolder(Folder* currentFolder) {
	string type;

	cout << "Enter the type of item you want to delete: (File/Folder): " << endl;
	cin >> type;

	if (type == "File" || type == "file") {
		string fileName;
		cout << "\nEnter the file name to delete: " << endl;
		cin >> fileName;

		File* fileToDelete = currentFolder->getFile(fileName);

		if (fileToDelete != nullptr) {
			currentFolder->deleteFile(fileToDelete);
			cout << "File \"" << fileName << "\" deleted successfully." << endl;
		}else {
			cout << "File \"" << fileName << "\" not found in this folder." << endl;
		}
	}else if (type == "Folder" || type == "folder") {
		string folderName;
		cout << "\nEnter the folder name to delete: " << endl;
		cin.ignore();
		getline(cin, folderName);

		Folder* folderToDelete = currentFolder->getFolder(folderName);

		if (folderToDelete != nullptr) {
			currentFolder->deleteFolder(folderToDelete);
			cout << "Folder \"" << folderName << "\" deleted successfully." << endl;
		}else {
			cout << "Folder \"" << folderName << "\" not found in this folder." << endl;
		}
	}else {
		cout << "\nInvalid input. Please enter 'File' or 'Folder'." << endl;
	}
}

void moveFileOrFolder(Folder* currentFolder) {
	string type, name, destName;
	Folder* destinationFolder = nullptr;
	cout << "Enter the type of item to move (File/Folder): " << endl;
	cin >> type;

	if (type == "File" || type == "file") {
		cout << "\nEnter the name of the file to move: " << endl;
		cin.ignore();
		getline(cin, name);

		File* fileToMove = currentFolder->getFile(name);
		if (fileToMove != nullptr) {
			cout << "\nEnter the destination folder to move the file to (or type 'parent' to move to the parent folder): " << endl;
			getline(cin, destName);

			if (destName == "parent" || destName == "Parent") {
				destinationFolder = currentFolder->getParent();
			}
			else {
				destinationFolder = currentFolder->getFolder(destName);
			}

			if (destinationFolder != nullptr) {
				destinationFolder->addFile(fileToMove);
				currentFolder->deleteFile(fileToMove);
				cout << "File \"" << name << "\" moved successfully to \"" << destinationFolder->getName() << "\"." << endl;
			}
			else {
				cout << "Destination folder not found." << endl;
			}
		}
		else {
			cout << "File not found." << endl;
		}
	}
	else if (type == "Folder" || type == "folder") {
		cout << "\nEnter the name of the folder to move: " << endl;
		cin.ignore();
		getline(cin, name);

		Folder* folderToMove = currentFolder->getFolder(name);
		if (folderToMove != nullptr) {
			cout << "\nEnter the destination folder to move the folder to (or type 'parent' to move to the parent folder): " << endl;
			getline(cin, destName);

			if (destName == "parent" || destName == "Parent") {
				destinationFolder = currentFolder->getParent(); 
			}
			else {
				destinationFolder = currentFolder->getFolder(destName);
			}

			if (destinationFolder != nullptr) {
				destinationFolder->addFolder(folderToMove);
				currentFolder->deleteFolder(folderToMove);
				cout << "Folder \"" << name << "\" moved successfully to \"" << destinationFolder->getName() << "\"." << endl;
			}
			else {
				cout << "Destination folder not found." << endl;
			}
		}
		else {
			cout << "Folder not found." << endl;
		}
	}
	else {
		cout << "Invalid input. Please enter 'File' or 'Folder'." << endl;
	}
}


void copyFileOrFolder(Folder* currentFolder) {
	string type, name, destName;
	Folder* destinationFolder = nullptr;
	cout << "Enter the type of item inside current folder to copy (File/Folder): " << endl;
	cin >> type;

	if (type == "File" || type == "file") {
		cout << "\nEnter the name of the file to copy: " << endl;
		cin.ignore();
		getline(cin, name);

		File* fileToCopy = currentFolder->getFile(name);
		if (fileToCopy != nullptr) {
			cout << "\nEnter the destination folder to copy the file to (Enter current folder name or here for the current folder):" << endl;
			getline(cin, destName);
			if (destName == currentFolder->getName() || destName == "here" || destName == "Here") {
				destinationFolder = currentFolder;
			}else {
				destinationFolder = currentFolder->getFolder(destName);
			}

			if (destinationFolder != nullptr) {
				File* newFile = new File(fileToCopy->getName() + "_copy", fileToCopy->getSize(), fileToCopy->getType());
				destinationFolder->addFile(newFile);
				cout << "File \"" << name << "\" copied successfully to \"" << destinationFolder->getName() << "\"." << endl;
			}else {
				cout << "Destination folder not found." << endl;
			}
		}else {
			cout << "File not found." << endl;
		}
	}else if (type == "Folder" || type == "folder") {
		cout << "\nEnter the name of the folder to copy: " << endl;
		cin.ignore();
		getline(cin, name);

		Folder* folderToCopy = currentFolder->getFolder(name);
		if (folderToCopy != nullptr) {
			cout << "\nEnter the destination folder to copy the folder to (Enter current folder name or here for the current folder): " << endl;
			getline(cin, destName);

			if (destName == "here" || destName == currentFolder->getName()) {
				destinationFolder = currentFolder;
			}
			else {
				destinationFolder = currentFolder->getFolder(destName);
			}

			if (destinationFolder != nullptr) {
				Folder* newFolder = new Folder(*folderToCopy);
				newFolder->setName(newFolder->getName() + "_copy");
				destinationFolder->addFolder(newFolder);
				cout << "Folder \"" << name << "\" copied successfully to \"" << destinationFolder->getName() << "\"." << endl;
			}
			else {
				cout << "Destination folder not found." << endl;
			}
		}
		else {
			cout << "Folder not found." << endl;
		}
	}
	else {
		cout << "Invalid input. Please enter 'File' or 'Folder'." << endl;
	}
}