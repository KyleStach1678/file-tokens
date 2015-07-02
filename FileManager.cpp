#include "FileManager.h"




////////////////////////////////////////////////////////
// CONSTRUCTORS
////////////////////////////////////////////////////////

FileManager::FileManager(string filename, string delim) {
	file.open(filename, ios::out | ios::in | ios::app);
	tokenizer.setDelimiter(delim);
	delimiter = delim;
	tokensOnLine = 0;
	currentMode = 2;
	this->filename = filename;
}

FileManager::~FileManager() {
	file.close();
}

//////////////////////////////////////////////////
// PUBLIC METHODS 
//////////////////////////////////////////////////

/* TOKEN METHODS */

string FileManager::nextToken() {
	return tokenizer.nextToken();
}
string FileManager::previousToken() {
	return tokenizer.prevToken();
}
string FileManager::currentToken() {
	return tokenizer.currToken();
}


void FileManager::appendToken(string token) {
	file.clear();
	if (tokensOnLine > 0)
	{
		append(delimiter);
	}
	append(token);
	tokensOnLine++;
	file.clear();
}
void FileManager::appendTokens(vector<string> tokens) {
	for (string s : tokens)
	{
		appendToken(s);
	}
}
void FileManager::setCurrentTokenPosition(int pos) {
	tokenizer.setcurrPos(pos);
}
void FileManager::setDelimiter(string delim) {
	delimiter = delim;
}

/********************************************************/


/* Line Methods */

 int FileManager::countLines() {
 	int count = 0;
 	while(!endOfFile()) {
 		count++;
 		nextLine();
 	}
 	return count;
 }

 int FileManager::getCurrentLineIndex() {
	return currentLineIndex;
}


string FileManager::getLineAtIndex(int index) {
	if (currentMode == MODE_READ && index > 1) {
	setLineIndex(index - 1);
	return nextLine();
	}
	else if (index = 1) {
		return getFirstLine();
	}
	else {
		cout << "Attempting to read while in write mode" << endl;
	}
}
string FileManager::getPreviousLine() {
	if (currentMode != MODE_READ) {
		cout << "Attempting to read while in write mode" << endl;
	}
	else if (currentLineIndex > 1) {
		return getLineAtIndex(currentLineIndex -1);
	} else {
		return getLineAtIndex(1);
	}
}
string FileManager::nextLine() {
	if (currentMode == MODE_READ) {
		string line;
		getline(file, line);
		tokenizer.setString(line);
		currentln = line;
		currentLineIndex++;
		return line;
	}
	else
	{
		cout << "Attempting to read while in write mode" << endl;
		return "";
	}
}
string FileManager::currentLine() {
	if(currentMode == MODE_READ) {
		if(currentLine() == "") {
			nextLine();
		}
		return currentln;
	} else {
		cout << "Attempting to read while in write mode" << endl;
	}
}


void FileManager::setMode(int mode) {
	if (mode != currentMode) {
		file.clear();
		file.close();
		file.open(filename, ios::app | (mode == MODE_WRITE ? ios::out : ios::in));
	}
	currentMode = mode;
}
void FileManager::appendLine(string line) {
	append(line);
	newLine();
}
void FileManager::write(string stringToWrite) {
	erase();
	append(stringToWrite);
}
void FileManager::writeln(string lineToWrite) {
	if (currentMode == MODE_WRITE) {
		append(lineToWrite);
		newLine();
	}
}
void FileManager::newLine() {
	append("\n");
	tokensOnLine = 0;
	currentLineIndex++;
}
void FileManager::erase() {
	if (currentMode == MODE_WRITE) {
		file.close();
	file.open(filename, std::fstream::out | std::fstream::trunc);
	file.close();
	} else {
		cout << "Attempting to write while in read mode" << endl;
	}
}
void FileManager::setLineIndex(int index) {
	file.clear();
	file.close();
	file.open(filename, ios::out | ios::in | ios::app);
	int lineCounter = 1;
	while(hasMoreLines()) {
		nextLine();
		
		if (lineCounter == index) {
			break;
		}
		lineCounter++;
		
	}
	currentLineIndex = index;
}






 bool FileManager::hasMoreLines() {
 	if(endOfFile()){
 		return false;
 	}else{
 		return true;
 	}

 }
 	





bool FileManager::beginningOfLine() {
	if(tokenizer.getCurrentMode() == 1) {
		if(tokenizer.nextToken() == "") {
			return true;
		}
		else {
			return false;
		}
	} else {
		if(tokenizer.prevToken() == "") {
			return true;
		}
		else {
			return false;
		}
	}
}








void FileManager::append(string toAppend) {
	if (currentMode == MODE_WRITE) {
		file << toAppend;	
	}
	else
	{
		cout << "Attempting to append while in read mode" << endl;
	}
}
	












bool FileManager::endOfLine() {
	return !tokenizer.hasMoreTokens();
}

bool FileManager::endOfFile() {
	return file.eof();
}





string FileManager::getFirstLine() {
	file.clear();
	file.close();
	file.open(filename, ios::out | ios::in | ios::app);
	return nextLine();
}

