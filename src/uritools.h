#ifndef URI_TOOLS_H
#define URI_TOOLS_H

typedef struct URI {
	char *scheme;
	char *username;
	char *password;
	char *host;
	char *port;
	char *path;
	char *query;
	char *fragment;
	char *uri_str;
} uri;

extern int uri_parse(uri *u, char *uri_str);
extern int uri_path_split(char *buf, char **resume);
extern void uri_free(uri *u);
extern char* uri_reconstruct(uri *u);
extern int uri_check(char *s);
#endif
