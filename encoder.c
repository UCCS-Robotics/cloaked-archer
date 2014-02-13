#ifndef HAMMING_ENCODER__
#define HAMMING_ENCODER__

#include <stdio.h>
#include <string.h>

#define DEFAULT_SIZE 13

/**
 * Function to encode the given input string
 * using Hamming codes
 */
char * encode(char *);

/**
 * @see Definition of encode
 */
char * encode(char * _input) {
	// Allocate encoded string and initialize first index
	char * encoded_str = malloc(DEFAULT_SIZE);
	encoded_str[0] = '0';
	encoded_str[DEFAULT_SIZE] = 0;

	// Populate original input in appropriate spots
	unsigned int x;
	unsigned int cnt = 0;
	for (x = 1; x < DEFAULT_SIZE; x++) {
		// Determine power of 2
		int temp = x + 1;
		while (((temp & 1) == 0) && temp > 1) {
			temp >>= 1;
		}
		// Place value appropriately
		if (temp != 1) {
			encoded_str[x] = _input[cnt++];
		} else {
			encoded_str[x] = '0';
		}
	}

	return encoded_str;
}

#endif
