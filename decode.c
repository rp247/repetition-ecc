#include "io.h"
//#include "encode.h"

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

/*
 *
 * to do:
 *   read in input from a stream (stdio or a file)
 *   parse arguments (how many n repetitions, etc.)
 *   save the encoded file
 *   MAGIC numero
 *   (make the encoder and decoder cross compatible)
 *
 */

static void usage(char *argv) {
	fprintf(stderr,
			        "SYNOPSIS\n"
		       		"  A Repetition ECC decoder.\n"
		       		"  Decodes a file using the repetition ecc code.\n"
		       		"\n"
		       		"USAGE\n"         
				"  ./%s [-h] [-i infile] [-o outfile]\n"         
				"\n"         
				"OPTIONS\n"
		       		"  -h             Program usage and help.\n"
		       		"  -s             Print encoding statistics.\n"         
				"  -i infile      Input file to encode.\n"         
				"  -o outfile     Output of encoded data.\n",
		argv);
}

int main(int argc, char **argv) {

	int c;
	char *optlist = "hsi:o:";
	
	int infile = STDIN_FILENO;	// change macro later
	int outfile = STDOUT_FILENO;	// change macro later

	/* parse arguments */
	while ((c = getopt(argc, argv, optlist)) != -1) {
		switch (c) {
			case 'h': 
				usage(argv[0]); 
				return 0;

			case 'i':
				infile = open(optarg, O_RDONLY);
				if (infile == -1) {
					fprinf(stderr, "Error: Cannot open input file.\n");
					return -1;
				}
				break;

			case 'o':
				outfile = open(optarg, O_RDWR); // add mode later?
				if (infile == -1) {
					fprintf(stderr, "Error: Cannot open output file.\n");
					return -1;
				}
				break;

			default:
				usage(argv[0]); return -1;
		}
	}


	/* to do:
	 * read from a file into a buffer
	 * process the buffer 
	 * parse the buffer and write it to a file as processing
	 * wr2file
	 */


	return 0;
}

