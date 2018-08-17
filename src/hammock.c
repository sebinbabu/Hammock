#include <stdio.h>

#include "args.h"

int main(int argc, char **argv) {
	int status;
	status = process_args(argv, argc);
	if(status == -1) {
		fprintf(stderr, "hammock: invalid option(s)\n"\
						"Try 'hammock help' for more information.\n");
	}
	return 0;
}