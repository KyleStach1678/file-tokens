#include <iostream>
#include "FileManager.h"

int main() {
	FileManager fr("test.txt", ",");
	fr.setMode(MODE_READ);
	fr.setLineIndex(2);
	cout << fr.nextLine() << endl;

	}
	