#ifndef FILE_H
#define FILE_H


enum files {
	DEPTH,
	QUEUE,
	LINKS,
	SEED
};

extern const char filelist[4][20];

char* get_dir(char *p, int n);
int change_dir(const char *p);
int create_dir(const char *p);
int create_file(const char *p);
int read_file(const char *p, char **s);
int write_file(const char *p, const char *s);
int update_file(const char *p, const char *s);

#endif