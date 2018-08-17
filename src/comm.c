#include <stdio.h>

#include "comm.h"
#include "init.h"

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
					" clean\tclean the working directory\n"
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
	if(s == NULL) {
		fprintf(stderr, "hammock: invalid option(s)\n");
		fprintf(stderr, "Try 'hammock help' for more information.\n");
		return 1;
	}
	fprintf(stdout, "Welcome to hammock!\n");
	return 0;
}