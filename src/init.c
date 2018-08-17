#include <stdio.h>

#include "init.h"
#include "file.h"

const char filelist[][20] = {
	".hammock/depth",
	".hammock/queue",
	".hammock/links",
	".hammock/seed"
};

const int filelist_num = sizeof(filelist)/sizeof(filelist[0]);
const char *app_dir = ".hammock/";


int init(char *s) {
	int ret = 0, i;
	if(s != NULL && change_dir(s) != 0) {
			perror("hammock");
			ret = 1;
	} else {
		char buffer[256], *p;
		if((p = get_dir(buffer, 256)) == NULL) {
			perror("hammock");
			ret = 1;
		} else {
			if(create_dir(".hammock") != 0) {
				perror("hammock");
				ret = 1;
			} else {
				for(i = 0; i < filelist_num; i++) {
					if(create_file(filelist[i]) != 0) {
						perror("hammock");
						ret = 1;
						break;
					}
				}
				if(i >= filelist_num) {
					fprintf(stdout, "Initialized empty Hammock directory in %s\n", p);
				}
			}
		}
	}
	return ret;
}