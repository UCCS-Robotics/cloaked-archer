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
	
	// Indexing values
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int cnt;
	unsigned int parity;

	// Populate original input in appropriate spots
	cnt = 0;
	for (x = 1; x < DEFAULT_SIZE; x++) {
		// Determine power of 2
		int temp = x + 1;
		while (((temp & 1) == 0) && temp > 1) {
			temp >>= 1;
		}
		
		// Place original value appropriately
		if (temp != 1) {
			encoded_str[x] = _input[cnt++];
		} else {
			encoded_str[x] = '0';
		}
	}
	
	// Now stuff the hamming code with parity bits
	cnt = 0;
	for (x = 1; x < DEFAULT_SIZE; x = 1 << ++cnt) {
		// Calculate parity
		y = --x;
		parity = 0;
		while (y < DEFAULT_SIZE) {
			// Calculate parity for regarded set
			z = y;
			for (; y < z + (x + 1); y++) {
				if (encoded_str[y] == '1') {
					parity++;
				}
			}
			
			// Skip the next set
			z = y;
			for (; y < z + (x + 1); y++);
		}
		
		// Stuff the parity bit
		if (parity % 2 == 0) {
			encoded_str[x] = '0';
		} else {
			encoded_str[x] = '1';
		}
	}

	return encoded_str;
}

#endif
