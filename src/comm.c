#include <stdio.h>
#include <malloc.h>

#include "comm.h"
#include "init.h"
#include "file.h"
#include "tools.h"

const commands comm[] = {
	{"help", help},
	{"init", init},
	{"crawl", crawl},
	{"add", add},
	{"depth", depth},
	{"seeds", seeds}
};

const int c_num = sizeof(comm)/sizeof(commands);

int help(char *s) {
	if(s != NULL) {
		fprintf(stderr, "hammock: invalid option(s)\n"\
						"Try 'hammock help' for more information.\n");
		return 1;
	}
	fprintf(stdout, "\nUsage:\n"\
					" hammock [option] <argument>\n\n"\
					"Crawl and download pages from the web.\n\n"
					"Options:\n"\
					" add\tadd a URL to the crawl queue\n"\
					" depth\tset the crawl depth\n"\
					" help\tdisplay this help\n"\
					" init\tinitialize the working directory for use\n"\
					" crawl\tstart crawling the queue\n"\
					" seeds\tdisplay the list of seed links\n"\
	);
	return 0;
}

int add(char *s) {
	int ret = 0;
	if(s == NULL || check_url(s) != 0) {
		ret = -1;
	} else {
		char *p = NULL;

		if(read_file(filelist[DEPTH], &p) != 0) {
			perror("hammock");
			ret = 1;
		} else {
			if(update_file(filelist[QUEUE], p) != 0 ||
				update_file(filelist[QUEUE], s) != 0 ||
				update_file(filelist[SEED], s) != 0) {
				perror("hammock");
				ret = 1;
			}
			free(p);
		}
	}
	return ret;
}

int depth(char *s) {
	int ret = 0;
	if(s != NULL) {
		int n = parse_int(s);
		if(n > 99 || n == -1) {
			ret = -1;
		} else {
			if(write_file(filelist[DEPTH], s) != 0) {
				perror("hammock");
				ret = 1;
			}
		}
	}
	if(ret == 0) {
		char *p = NULL;
		if(read_file(filelist[DEPTH], &p) != 0) {
			perror("hammock");
			ret = 1;
		} else {
			fprintf(stdout, "crawl depth: %s\n", p);
			free(p);
		}
	}
	return ret;
}

int seeds(char *s) {
	int ret = 0;
	if(s != NULL) {
		ret = -1;
	} else {
		char *p = NULL;

		if(read_file(filelist[SEED], &p) != 0) {
			perror("hammock");
			ret = 1;
		} else {
			fprintf(stdout, "crawl seeds:\n%s", p);
		}
	}
	return ret;
}
