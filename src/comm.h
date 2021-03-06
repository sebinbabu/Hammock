#ifndef COMM_H
#define COMM_H

typedef struct COMMANDS {
	char com[7];
	int (*execute) (char *s);
} commands;

int help(char *s);
int init(char *s);
int crawl(char *s);
int add(char *s);
int depth(char *s);
int seeds(char *s);

extern const commands comm[];
extern const int c_num;

#endif