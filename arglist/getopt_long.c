/**
 * This program demonstrates the use of getopt
 * to process command-line arguments
 */
 #include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>

 /* The name of the program */
 const char* program_name;

 /* Prints usage information for this program to STREAM
 	(typically stdout or stderr). and exit the program with
 	EXIT_CODE. Does not return */
 void print_usage(FILE* stream, int exit_code) 
 {
 	fprintf(stream, "Usage: %s options [ inputfile ...]\n", program_name);
 	fprintf(stream, 
 		"  -h 	--help\t\t\tDisplay this usage information\n"
 		"  -o   --output filename\tWrite output to file\n"
 		"  -v  	--verbose\t\tPrint verbose messages.\n");
 	exit(exit_code);
 }

 /* Test function */
 void wrie_output(const char *filename) {
 	FILE *f = fopen(filename, "w");

 	print_usage(f, 0);

 	fclose(f);
 }

 /* Main program. ARGC contains number of argument list elements;
 				  ARGV is an array of pointers to them. */
 int main(int argc, char *argv[])
 {
 	int next_option;

 	/* A string lisitng valid short options letters */
 	const char* const short_options = "ho:v";

 	/* An array describing valid long options */
 	const struct option long_options[] = {
 		{"help",	0, NULL, 'h'},
 		{"output",  1, NULL, 'o'},
 		{"verbose", 0, NULL, 'v'},
 		{NULL, 		0, NULL, 0	}	// Required at end of array
 	};

 	/* The name of the file to receive program output, or NULL for standard output */
 	const char* output_filename = NULL;
 	/* Whether to display verbose message */
 	int verbose = 0;

 	/* Remember the name of the program, to incorporate in messages.
 	   The name is stored in argv[0]. */
 	program_name = argv[0];

 	do {
 		next_option = getopt_long(argc, argv, short_options, long_options, NULL);

 		switch (next_option)
 		{
 			case 'h':	/* -h or --help */
	 			/* User has requested usage information. Print it to standard output,
	 			and exit with exit code zero (normal termination). */
 				print_usage(stdout, 0);

 			case 'o':
	 			/* This option takes an argument, the name of the output file */
	 			output_filename = optarg;
	 			wrie_output(output_filename);
	 			break;

	 		case 'v':
	 			verbose = 1;
	 			break;

	 		case '?':	/* The user specified an invalid option */
	 			/* Prints usage information to standard error,
	 			   and exit with exit code 1 (abnormal termination) */
	 			print_usage(stderr, 1);

	 		case -1:	/* Done with options */
	 			break;

	 		default:	/* Something unexpected */
	 			abort();
 		}	
 	} while (next_option != -1);

 	/* Done with options. OPTIND points to first nonoption argument.
 	For demonstration purposes, print them if the verbose option was specified. */
 	if (verbose)
 	{
 		int i;
 		for (i = optind; i < argc; i++) 
 		{
 			printf("Argument: %s\n", argv[i]);
 		}
 	}

 	/*The main program goes here*/
 	printf("To the end of main program\n");
 	return 0;
 }