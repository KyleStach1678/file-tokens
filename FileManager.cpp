#include "FileManager.h"
#include <iostream>

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

std::string FileManager::nextToken() {
	return tokenizer.nextToken();
}

std::string FileManager::nextLine() {
	if (currentMode == MODE_READ) {
		string line;
		getline(file, line);
		tokenizer.setString(line);
		return line;
	}
	else
	{
		std::cout << "Attempting to read while in write mode" << std::endl;
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

void FileManager::append(string toAppend) {
	if (currentMode == MODE_WRITE) {
		file << toAppend;	
	}
	else
	{
		std::cout << "Attempting to append while in read mode" << std::endl;
	}
}
	
void FileManager::appendLine(string line) {
	append(line);
	newLine();
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
}

bool FileManager::endOfLine() {
	return !tokenizer.hasMoreTokens();
}

bool FileManager::endOfFile() {
	return file.eof();
}