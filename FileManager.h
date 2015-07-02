#ifndef TOKENFILEREADER_H
#define TOKENFILEREADER_H

#include <fstream>
#include <vector>
#include <list>
#include "Tokenizer.h"
#include <iostream>
#include <fstream>
#include <limits>


const int MODE_WRITE = 0;
const int MODE_READ = 1;

class FileManager {
	typedef vector<string> Line;
public:
	FileManager(string filename, string delim = " ");
	~FileManager();
	
	 int countLines();

	 //Lines are 1-indexed
	 int getCurrentLineIndex();

	string nextLine();
	string nextToken();
	string currentLine();
	string previousToken();
	string currentToken();
	string getLineAtIndex(int index);
	string getPreviousLine();

	void setCurrentTokenPosition(int pos);

	void setDelimiter(string delimiter);
	void setMode(int mode);
	void appendLine(string line);
	void write(string stringToWrite);
	void appendToken(string token);
	void appendTokens(vector<string> tokens);
	void newLine();
	void writeln(string lineToWrite);
	void erase();
	void setLineIndex(int index);

	bool hasMoreLines();
	bool endOfLine();
	bool endOfFile();
	bool beginningOfLine();


	

private:

	
	int tokensOnLine;
	int currentMode;
	int currentLineIndex = 1;

	fstream file;

	Tokenizer tokenizer;

	string getFirstLine();

	string currentln = "";
	string filename;
	string delimiter;

	void append(string toAppend);
};

#endif