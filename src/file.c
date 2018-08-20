#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>

#include "file.h"

const char filelist[4][20] = {
	".hammock/depth",
	".hammock/queue",
	".hammock/links",
	".hammock/seed"
};

char* get_dir(char *p, int n) {
	return getcwd(p, n);
}

int change_dir(const char *p) {
	return chdir(p);
}

int create_dir(const char *p) {
	struct stat st = {0};
	return stat(p, &st) == -1 && mkdir(p, 0777) != 0;
}

int create_file(const char *p) {
	struct stat st = {0};
	return stat(p, &st) == -1 && creat(p, 0666) == -1;
}

int read_file(const char *p, char **s) {
	char *buffer = NULL;
	struct stat st = {0};
	int ret = 0;

    if(stat(p, &st) != 0) {
    	ret = 1;
    } else if(st.st_size < 1) {
    	buffer = malloc(sizeof(char));
    	*buffer = 0;
    } else {
    	buffer = malloc(st.st_size);
    	if(buffer == NULL) {
    		ret = 1;
    	} else {
			FILE *f = fopen(p, "rb");
			if(f == NULL) {
				ret = 1;
			} else {
				fread(buffer, st.st_size, 1, f);
			}
			fclose(f);
    	}
    }

    *s = buffer;
    return ret;
}

int write_file(const char *p, const char *s) {
	int ret = 0;
	FILE *f = fopen(p, "w+");
	if(f == NULL || fputs(s, f) < 0)
		ret = 1;
	else
		fclose(f);
    return ret;
}

int update_file(const char *p, const char *s) {
	int ret = 0;
	FILE *f = fopen(p, "a");
	if(f == NULL || fputs(s, f) < 0 || fputc('\n', f) == EOF)
		ret = 1;
	else
		fclose(f);
    return ret;
}