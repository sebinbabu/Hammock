#ifndef URI_TOOLS_H
#define URI_TOOLS_H

typedef struct URL {
	char *scheme;
	char *username;
	char *password;
	char *host;
	int port;
	char *path;
	char *query;
	char *fragment;
	char *url_str;
} url;

extern int url_parse(url *u, char *url_str);
extern int url_path_split(char *buf, char **resume);
extern void url_free(url *u);

#endif
