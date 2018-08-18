#include <string.h>

#include "args.h"
#include "comm.h"

int process_args(char **v, int c) {
	int i, j, n = c_num, status = -1;
	for(i = 1; i < c; i += 2) {
		for(j = 0; j < n; j++) {
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