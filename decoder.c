#ifndef HAMMING_DECODER_DEF__
#define HAMMING_DECODER_DEF__

#include <stdio.h>
#include <string.h>

#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 13
#endif

/**
 * This function will decode a Hamming encoded
 * set of data
 */
char * decode(char *);

/**
 * @see Declaration of decode()
 */
char * decode(char * _string) {
	// Allocate encoded string and initialize first index
	char * decoded_str = malloc(DEFAULT_SIZE);
	memcpy(decoded_str, _string, DEFAULT_SIZE);
	decoded_str[DEFAULT_SIZE] = 0;
	
	// Indexing values
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int cnt;
	unsigned int parity;
	unsigned int correction;
	
	// Recalculate the parities
	cnt = 0;
	correction = 0;
	for (x = 1; x < DEFAULT_SIZE; x = 1 << ++cnt) {
		// Calculate parity
		y = --x;
		parity = 0;
		while (y < DEFAULT_SIZE) {
			// Calculate parity for regarded set
			z = y;
			for (; y < z + (x + 1); y++) {
				if (decoded_str[y] == '1') {
					parity++;
				}
			}
			
			// Skip the next set
			y += (x + 1);
		}
		
		// Check the parity bit
		if (parity % 2 != 0) {
			correction += (x + 1) ;
		}
	}
	
	// Flip the correction bit
	if (correction-- > 0) {
		char flip = decoded_str[correction];
		if (flip == '0') {
			flip = '1';
		} else {
			flip = '0';
		}
		decoded_str[correction] = flip;
	}
	
	// Reset the decoded bit
	char * original_str = malloc(9);
	cnt = 0;
	for (x = 1; x < DEFAULT_SIZE; x++) {
		// Determine power of 2
		int temp = x + 1;
		while (((temp & 1) == 0) && temp > 1) {
			temp >>= 1;
		}
		
		// Place original value appropriately
		if (temp != 1) {
			original_str[cnt++] = decoded_str[x];
		} 
	}
	
	
	
	return original_str;
}

#endif
