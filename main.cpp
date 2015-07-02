#include <iostream>
#include "FileManager.h"

int main() {
	FileManager fr("test.txt", " ");
	fr.setMode(MODE_READ);
	fr.getLineAtIndex(3);
}