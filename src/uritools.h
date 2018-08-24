#ifndef URI_TOOLS_H
#define URI_TOOLS_H

typedef struct URI {
	char *scheme;
	char *username;
	char *password;
	char *host;
	int port;
	char *path;
	char *query;
	char *fragment;
	char *uri_str;
} uri;

extern int uri_parse(uri *u, char *uri_str);
extern int uri_path_split(char *buf, char **resume);
extern void uri_free(uri *u);

#endif
