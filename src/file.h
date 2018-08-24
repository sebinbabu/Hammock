#ifndef FILE_H
#define FILE_H


enum files {
	DEPTH,
	QUEUE,
	LINKS,
	SEED
};

extern const char filelist[4][20];

extern char* get_dir(char *p, int n);
extern int change_dir(const char *p);
extern int create_dir(const char *p);
extern int create_file(const char *p);
extern int remove_file(const char *p);
extern int read_file(const char *p, char **s);
extern int write_file(const char *p, const char *s);
extern int update_file(const char *p, const char *s);

#endif