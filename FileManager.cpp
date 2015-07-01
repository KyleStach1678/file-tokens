#include "FileManager.h"


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

 int FileManager::countLines() {
 	int count = 0;
 	while(!endOfFile()) {
 		count++;
 		nextLine();
 	}
 	return count;
 }
 bool FileManager::hasMoreLines() {
 	if(endOfFile()){
 		return false;
 	}else{
 		return true;
 	}

 }
 	


string FileManager::nextToken() {
	return tokenizer.nextToken();
}
string FileManager::currentToken() {
	return tokenizer.currToken();
}
string FileManager::previousToken() {
	return tokenizer.prevToken();
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

void FileManager::setMode(int mode) {
	if (mode != currentMode) {
		file.clear();
		file.close();
		file.open(filename, ios::app | (mode == MODE_WRITE ? ios::out : ios::in));
	}
	currentMode = mode;
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


void FileManager::append(string toAppend) {
	if (currentMode == MODE_WRITE) {
		file << toAppend;	
	}
	else
	{
		cout << "Attempting to append while in read mode" << endl;
	}
}
	
void FileManager::appendLine(string line) {
	append(line);
	newLine();
}
void FileManager::setDelimiter(string delim) {
	delimiter = delim;
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

void FileManager::newLine() {
	append("\n");
	tokensOnLine = 0;
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

bool FileManager::endOfLine() {
	return !tokenizer.hasMoreTokens();
}

bool FileManager::endOfFile() {
	return file.eof();
}
void FileManager::setLineIndex(int index) {
	currentLineIndex = index;
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

}
void FileManager::setCurrentTokenPosition(int pos) {
	tokenizer.setcurrPos(pos);
}
int FileManager::getCurrentLineIndex() {
	return currentLineIndex;
}
