#include "input.c"
#include "encoder.c"
#include "decoder.c"

/**
 * Entry point for CS4220 Project 1
 */
int main(int argc, char * argv[]) {
	// Sanitize input
	if (argc < 2) {
		printf("[ERROR]\tUsage: main.o [input file]");
		return -1;
	}

	// Get the data and encode / decode it
	char * file_path = argv[1];
	char * original_data = readf(file_path);
	char * encoded_data = encode(original_data);
	char * decoded_data;

	// Print out the results
	printf("\n[RESULTS]\n");
	printf("\tOriginal: \t%s\n", original_data);
	printf("\tEncoded data: \t%s\n", encoded_data);

	// Flag for user-changed encoded data
	char ans;
	printf("\tChange the encoded data piped to decoder? [y|n] ");
	scanf("%c", &ans);
	getchar();

	// Logic to determine if changes are needed
	char * word = malloc(13);
	if (ans == 'Y' || ans == 'y') {
		printf("\tNew encoded value: ");
		fgets(word, 12, stdin);
		word[12] = 0;
		encoded_data = word;
	}

	// Now get the decoded data
	decoded_data = decode(encoded_data);
	printf("\tDecoded data: \t%s\n", decoded_data);

	// Free up allocated memory
	free(original_data);
	free(encoded_data);
	free(word);

	return 0;
}
