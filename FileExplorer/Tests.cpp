#include "Tests.h"
#include "File.h"
#include "Folder.h"
#include "FileSystem.h"
#include <iostream>
#include <string>

using namespace std;

void test( bool runAll){
    if(runAll){
        cout << "Running all tests" << endl;
        testAddFile();
        testAddFolder();
        testDeleteFile();
        testDeleteFolder();
        testMoveFile();
        testMoveFolder();
        testCopyFile();
        testCopyFolder();
        testGoToParentFolder();
        testOpenSubFolder();
        testSearch();
    }
}

void testAddFile(){
    cout << "----------Running testAddFile----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    File* file = new File("testFile", 10, "txt", currentFolder);
    currentFolder->addFile(file);
    if(currentFolder->getFile("testFile") == file){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }

    delete file;
    delete fileSystem;
    cout << "----------Finished testAddFile----------" << endl;
}


void testAddFolder(){
  cout << "----------Running testAddFolder----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    Folder* folder = new Folder("testFolder", currentFolder);
    currentFolder->addFolder(folder);
    if(currentFolder->getFolder("testFolder") == folder){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    delete folder;
    delete fileSystem; 
    cout << "----------Finished testAddFolder----------" << endl;
}

void testDeleteFile(){
    cout << "----------Running testDeleteFile----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    File* file = new File("testFile", 10, "txt", currentFolder);
    currentFolder->addFile(file);
    currentFolder->deleteFile(file);
    if(currentFolder->getFile("testFile") == nullptr){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    delete file;
    delete fileSystem;
    cout << "----------Finished testDeleteFile----------" << endl;
}

void testDeleteFolder(){ 
    cout << "----------Running testDeleteFolder----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    Folder* folder = new Folder("testFolder", currentFolder);
    currentFolder->addFolder(folder);
    currentFolder->deleteFolder(folder);
    if(currentFolder->getFolder("testFolder") == nullptr){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    delete folder;
    delete fileSystem;
    cout << "----------Finished testDeleteFolder----------" << endl;
}

void testMoveFile(){
    // cout << "----------Running testMoveFile----------" << endl;
    // FileSystem* fileSystem = new FileSystem;
    // Folder* currentFolder = fileSystem->getRoot();
    // Folder* destFolder = new Folder("destFolder", currentFolder);
    // File* file = new File("testFile", 10, "txt", currentFolder);
    // currentFolder->addFile(file);
    // currentFolder->moveFile("testFile", "destFolder");
    // if(destFolder->getFile("testFile") == file){
    //     cout << "Test Passed" << endl;
    // }else{
    //     cout << "Test Failed" << endl;
    // }
    // delete file;
    // delete destFolder;
    // delete fileSystem;
    // cout << "----------Finished testMoveFile----------" << endl;
}

void testMoveFolder(){
    // cout << "----------Running testMoveFolder----------" << endl;
    // FileSystem* fileSystem = new FileSystem;
    // Folder* currentFolder = fileSystem->getRoot();
    // Folder* destFolder = new Folder("destFolder", currentFolder);
    // Folder* folder = new Folder("testFolder", currentFolder);
    // currentFolder->addFolder(folder);
    // currentFolder->moveFolder("testFolder", "destFolder");

    // if(destFolder->getFolder("testFolder") == folder){
    //     cout << "Test Passed" << endl;
    // }else{
    //     cout << "Test Failed" << endl;
    // }
    // delete folder;
    // delete destFolder;
    // delete fileSystem;
    // cout << "----------Finished testMoveFolder----------" << endl;
}

void testCopyFile(){}

void testCopyFolder(){}

void testGoToParentFolder(){
    cout << "----------Running testGoToParentFolder----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = new Folder;

    bool validName = false;
    string folderName = "Desktop";
    while (!validName) {
  		currentFolder = fileSystem->getFolder(fileSystem->getRoot(), folderName);
  		if (currentFolder != nullptr) {
		  	cout << "\nYou're now exploring the " << folderName << " folder." << endl;
			  validName = true;
		  }
	  }
    if(currentFolder->getParent()->getName() == "Home"){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    delete currentFolder;
    delete fileSystem;
    cout << "----------Finished testGoToParentFolder----------" << endl;
}

void testOpenSubFolder(){
    cout << "----------Running testOpenSubFolder----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    Folder* subFolder = new Folder("subFolder", currentFolder);
    currentFolder->addFolder(subFolder);
    Folder* openedFolder = currentFolder->getFolder("subFolder");
    if(openedFolder == subFolder){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    delete subFolder;
    delete fileSystem;
    cout << "----------Finished testOpenSubFolder----------" << endl;
}

void testSearch(){
    cout << "----------Running testSearch----------" << endl;
    FileSystem* fileSystem = new FileSystem;
    Folder* currentFolder = fileSystem->getRoot();
    File* file = new File("testFile", 10, "txt", currentFolder);
    currentFolder->addFile(file);
    currentFolder->search("testFile");
    delete file;
    delete fileSystem;
    cout << "----------Finished testSearch----------" << endl;
}

void testSortSize(){}

void testSortName(){}


