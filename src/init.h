#ifndef INIT_H
#define INIT_H

int init(char *s);
enum files {
	DEPTH,
	QUEUE,
	LINKS,
	SEED
};
extern const char filelist[][20];

#endif