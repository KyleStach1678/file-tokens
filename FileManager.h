
/*****************************************************************************
* 								FileManager.h
* 								=============
*
* AUTHORS: Kyle Stachowicz, Samuel Resendez, Sam Chung
* CREATED: 01-07-2015
*******************************************************************************/


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

	///////////////////
	// Constructors////
	///////////////////

	FileManager(string filename, string delim = " ");
	~FileManager();
	
	/****************************************/

	///////////////////
	//Token Methods////
	///////////////////

	string nextToken();
	string previousToken();
	string currentToken();

	void appendToken(string token);
	void appendTokens(vector<string> tokens);
	void setCurrentTokenPosition(int pos);
	void setDelimiter(string delimiter);

	/****************************************/

	///////////////////
	//Line Methods/////
	///////////////////

	//Lines are 1-indexed(i.e. The first line is at index 1);
	 int getCurrentLineIndex();
	 int countLines();


	//Sets your cursor at the beginning of the line
	string getLineAtIndex(int index);
	string getPreviousLine();
	string nextLine();
	string currentLine();

	 
	
	void setMode(int mode);
	void appendLine(string line);
	void write(string stringToWrite);
	void writeln(string lineToWrite);
	void newLine();
	void erase();
	void setLineIndex(int index);


	bool hasMoreLines();
	bool beginningOfLine();
	bool endOfLine();
	bool endOfFile();
	


	

private:

	
	int tokensOnLine;
	int currentMode;
	int currentLineIndex = 1;

	fstream file;

	Tokenizer tokenizer;

	string getFirstLine();
	void append(string toAppend);


	string currentln = "";
	string filename;
	string delimiter;

	
};

#endif