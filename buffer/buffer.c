/*
 * This program print a period after 1 sec repeatedly
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	while(1) {
		fprintf(stderr, ".");
		sleep(1);
	}
	return 0;
}