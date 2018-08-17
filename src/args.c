#include <string.h>

#include "args.h"
#include "commands.h"

extern commands comm[];

int process_args(char **v, int c) {
	int i, j, status = -1;
	for(i = 1; i < c; i++) {
		for(j = HELP; j < DEPTH; j++) {
			if(strcmp(v[i], comm[j].com) == 0) {
				status = comm[j].execute(i + 1 < c ? v[i + 1] : NULL);
				if(status != 0)
					return status;
				break;
			}

		}
	}
	return status;
}