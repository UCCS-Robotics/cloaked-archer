#ifndef DATA_INPUT_UTIL_DEF__
#define DATA_INPUT_UTIL_DEF__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Default input chunk, one megabyte
#define FILE_CHUNK 1024

/**
 * Function to read text from an input file
 */
char * readf(char *);

/**
 * @see Declaration of readf()
 */
char * readf(char * _path) {
	// Open a FILE object for this file path
	FILE * _file;
	_file = fopen(_path, "r");
	if (_file == 0) {
		printf("[ERROR]\tCould not open file %s.\n", _path);
		return NULL;
	}

	// Read the data from the file into memory
	char * buffer;
	size_t offset;
	if ((buffer = malloc(FILE_CHUNK)) != NULL) {
		while ((offset = fread(buffer, 1, FILE_CHUNK, _file)) > 0);
	}

	// Close the file
	fclose(_file);

	// Return the buffered data
	return buffer;
}

#endif
