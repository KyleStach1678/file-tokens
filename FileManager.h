#ifndef TOKENFILEREADER_H
#define TOKENFILEREADER_H

#include <fstream>
#include <vector>
#include <list>
#include "Tokenizer.h"

using namespace std;

const int MODE_WRITE = 0;
const int MODE_READ = 1;

class FileManager {
	typedef vector<string> Line;
public:
	FileManager(string filename, string delim = " ");
	~FileManager();
	string nextToken();
	int nextTokenAsInt();
	string nextLine();

	void setMode(int mode);

	void appendLine(string line);
	void appendToken(string token);
	void appendTokens(vector<string> tokens);
	void newLine();

	bool endOfLine();
	bool endOfFile();

	void erase();
	void flush();
private:
	fstream file;
	Tokenizer tokenizer;
	string delimiter;
	void append(string toAppend);
	int tokensOnLine;
	int currentMode;
	string filename;
};

#endif