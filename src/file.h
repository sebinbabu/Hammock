#ifndef FILE_H
#define FILE_H

char* get_dir(char *p, int n);
int change_dir(const char *p);
int create_dir(const char *p);
int create_file(const char *p);
int read_file(const char *p, char **s);
int write_file(const char *p, const char *s);

#endif