#include <stdio.h>
#include <malloc.h>

#include "comm.h"
#include "init.h"
#include "file.h"
#include "tools.h"

const commands comm[] = {
	{"help", help},
	{"init", init},
	{"start", start},
	{"add", add},
	{"depth", depth}
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
					" start\tstart crawling the queue\n"\
	);
	return 0;
}

int start(char *s) {
	if(s != NULL) {
		fprintf(stderr, "hammock: invalid option(s)\n");
		fprintf(stderr, "Try 'hammock help' for more information.\n");
		return 1;
	}
	fprintf(stdout, "Welcome to hammock!\n");
	return 0;
}

int add(char *s) {
	if(s == NULL) {
		fprintf(stderr, "hammock: invalid option(s)\n");
		fprintf(stderr, "Try 'hammock help' for more information.\n");
		return 1;
	}
	fprintf(stdout, "Welcome to hammock!\n");
	return 0;
}

int depth(char *s) {
	const char *depthfile = ".hammock/depth";
	int ret = 0;
	if(s != NULL) {
		int n = parse_int(s);
		if(n > 99 || n == -1) {
			ret = -1;
		} else {
			if(write_file(depthfile, s) != 0) {
				perror("hammock");
				ret = 1;
			}
		}
	}

	char *p = NULL;
	if(read_file(depthfile, &p) != 0) {
		perror("hammock");
		ret = 1;
	} else {
		fprintf(stdout, "crawl depth: %s\n", p);
		free(p);
	}
	return ret;
}