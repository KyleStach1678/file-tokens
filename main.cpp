#include <iostream>
#include "FileManager.h"

int main() {
	FileManager fr("test.txt", ",");
	fr.setMode(MODE_READ);
	cout << fr.getLineAtIndex(3)<< endl;
	cout <<fr.getLineAtIndex(1) << endl;
	}