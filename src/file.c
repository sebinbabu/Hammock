#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "file.h"


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