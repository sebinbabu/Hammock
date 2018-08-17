#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct COMMANDS {
	char com[7];
	int (*execute) (char *s);
} commands;

int help(char *s);
int init(char *s);
int start(char *s);
int add(char *s);
int depth(char *s);

#endif