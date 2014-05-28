/**
 * This program demonstrates the use of argc and argv
 **/

 #include <stdio.h>

 int main(int argc, char const *argv[])
 {
 	printf("The name of this program is '%s'.\n", argv[0]);
 	printf("This program was invoked with %d arguments.\n", argc - 1);

 	/* If there were command-line arguments */
 	if (argc > 1)
 	{
 		int i;
 		printf("The arguments are:\n");
 		for (i = 0; i < argc; ++i)
 		{
 			printf("  %s\n", argv[i]);
 		}
 	}
 	return 0;
 }