#include <iostream>
#include <string>
#include "linkedList.h"
#include "folder.h"
#include "file.h"


using namespace std;

int main() {
	/*cout << "Testing Node class: " << endl;
	Node<string>* testNode = new Node<string>("Hello World!\n");
	cout << testNode->getData() << endl;
	delete testNode;

	cout << "\n" << "Testing LinkedList class:" << endl;
	LinkedList<char>* testList = new LinkedList<char>;
	testList->push_back('a');
	testList->push_back('b');
	testList->push_back('c');
	cout << testList->getHead()->getData() << ' ';
	cout << testList->getTail()->getData() << endl;

	testList->deleteData('a');
	cout << testList->getHead()->getData() << ' ';
	testList->deleteData('c');
	cout << testList->getTail()->getData() << endl;

	LinkedList<char>* bestList = new LinkedList<char>();
	bestList->push_back('a');

	*testList += *bestList;

	cout << testList->getHead()->getData() << ' ';
	cout << testList->getTail()->getData() << endl;

	delete bestList;
	delete testList;*/
	

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

	return 0;
}