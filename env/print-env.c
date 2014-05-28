/**
 * This program prints the environment variables
 * in Linux
 **/
 #include <stdio.h>
 #include <stdlib.h>

 /* The ENVIRON variable contains the environment */
 extern char** environ;

 int main() {
 	char** var;
 	for (var = environ; *var != NULL; ++var) {
 		printf("%s\n", *var);
 	}

 	printf("HOME : %s\n", getenv("HOME"));
 	/* Get a specific environment */
 }