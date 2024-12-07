#include <iostream>
#include <string>
#include "FileSystem.h"
#include "LinkedList.h"

using namespace std;

enum Actions {QUIT, ADD, REMOVE, MOVE, COPY, BACK, OPEN, SEARCH};

const int min_menu = 1;
const int max_menu = SEARCH;

int getMenuChoice();
Folder* getStartingFolder(FileSystem* fileSystem);
Folder* openSubFolder(Folder* currentFolder);

int main() {
	int choice;
	string folderName = "";
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

		switch (choice)
		{
			case QUIT:
				cout << "Thank you for using File Explorer!" << endl;
				break;
			case ADD:
				//break;
			case REMOVE:
				//break;
			case MOVE:
				//break;
			case COPY:
				cout << "Coming soon!";
				break;
			case BACK:
				if (currentFolder->getParent() == nullptr) {
					cout << "You are already at the root folder." << endl;
				}
				else {
					currentFolder = currentFolder->getParent();
					cout << "\nYou're now exploring the " << currentFolder->getName() << " folder." << endl;
				}
				break;
			case OPEN:
				currentFolder = openSubFolder(currentFolder);
				break;
			case SEARCH:
				cout << "Coming soon!";
				break;
		}
	}
	while (choice != QUIT);

	
	/*
		cout << "\n" << "Testing File class: " << endl;
	File* testFile1 = new File("test.txt", 100, "text");
	testFile1->print();

	File* testFile2 = new File(*testFile1);
	testFile2->print();
	if (*testFile1 == *testFile2) {
		cout << "Both files are the same." << endl;
	}
	else {
		cout << "Files are different." << endl;
	}


	testFile2->setName("test.h");
	testFile2->setSize(50);
	testFile2->setType("header");
	testFile2->print();
	if (*testFile1 == *testFile2) {
		cout << "Both files are the same." << endl;
	}
	else {
		cout << "Files are different." << endl;
	}

	cout << "\n" << "Testing Folder class:" << endl;
	Folder* testFolder = new Folder("Test Folder");
	testFolder->addFile(testFile1);
	testFolder->addFile(testFile2);
	testFolder->print();
	testFolder->deleteFile(testFile1);
	cout << endl;
	testFolder->print();

	Folder* testSubfolder = new Folder("Test Subfolder 1");
	testFolder->addFolder(testSubfolder);
	cout << endl;
	testFolder->print();

	Folder* testSubfolder2 = new Folder("Test Subfolder 2");
	testFolder->addFolder(testSubfolder2);
	cout << endl;
	testFolder->print();

	testFolder->addFile(testFile1);
	cout << endl;
	testFolder->print();

	File* file = testFolder->getFile("test.txt");

	if (file != nullptr) {
		file->setSize(1000);
		cout << file->getSize() << endl;
	}
	else {
		cout << "File not found!" << endl;
	}
	testFolder->print();

	testFolder->moveFile("test.txt", testSubfolder->getName());
	testFolder->print();
	cout << endl;
	testFolder->deleteFile(testFolder->getFile("test.txt"));
	cout << endl;
	testFolder->print();

	cout << endl;
	testFolder->moveFolder(testSubfolder->getName(), testSubfolder2->getName());
	testFolder->print();

	Folder * testFolder2 = new Folder("Test folder2");
	if (*testFolder == *testFolder2) {
		cout << "testFolder2 is the same as testFolder" << endl;
	}else {
		cout << "testFolder2 is not the same as testFolder" << endl;
	}

	Folder* testFolder3 = new Folder("Test folder3");
	File* audioFile = new File("audio.mp3", 1000, "MP3");
	testFolder2->addFile(audioFile);
	testFolder3->addFile(audioFile);
	testFolder2->print();

	testFolder3->setName("Test folder2");
	testFolder3->print();
	if (*testFolder2 == *testFolder3) {
		cout << "testFolder3 is the same as testFolder2" << endl;
	}
	else {
		cout << "testFolder3 is not the same as testFolder2" << endl;
	}

	testFolder2->deleteFile(testFolder2->getFile("audio.mp3"));
	testFolder2->print();
	if (*testFolder2 == *testFolder3) {
		cout << "testFolder3 is the same as testFolder2" << endl;
	}
	else {
		cout << "testFolder3 is not the same as testFolder2" << endl;
	}
*/

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
		cout << "Enter a number from " << min_menu << " to " << max_menu << ", or 0 to exit: " << endl;

		cin >> choice;
		cout << endl;

		if (!(choice < min_menu) || !(choice > max_menu)) {
			validChoice = true;
		}
		else {
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
		cin >> folderName;

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
	Folder* temp = new Folder;
	bool validName = false;
	if (currentFolder->getFoldersHead() == nullptr) {
		cout << "The current folder has no subfolders." << endl;
		return currentFolder;
	}
	cout << "Enter the name of the subfolder to open: " << endl;
	while (!validName) {
		cin >> folderName;
		temp = currentFolder->getFolder(folderName);
		if (temp != nullptr) {
			cout << "\n You're now exploring the " << folderName << " folder." << endl;
			validName = true;
		}else {
			cout << "Subfolder not found. Please enter a valid name: " << endl;
		}
	}
	return temp;
}

