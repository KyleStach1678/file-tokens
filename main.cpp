#include <iostream>
#include "FileManager.h"

int main(int argc, char* argv[]) {
	FileManager fr(argv[1], " ");
	fr.setMode(MODE_WRITE);
	fr.writeln("HELLO CLASS, IM THE PROFESSOR");
	fr.setMode(MODE_READ);
	cout << fr.getLineAtIndex(1) << endl;
	fr.setMode(MODE_WRITE);
	fr.write("Hello Land!");
	fr.setMode(MODE_READ);
	cout << fr.getLineAtIndex(1) << endl;
	fr.setMode(MODE_WRITE);
	fr.erase();
}