#include <iostream>
#include "FileManager.h"

int main() {
	FileManager fr("test.txt", ",");
	fr.setMode(MODE_WRITE);
	fr.appendTokens({ "5", "18", "afsd", "sdfa" });
	fr.newLine();
	fr.setMode(MODE_READ);
	while (!fr.endOfFile()) {
		fr.nextLine();
		while (!fr.endOfLine()) {
			std::cout << fr.nextToken() << std::endl;
		}
	}
}