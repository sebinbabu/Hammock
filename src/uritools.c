
#include <stdlib.h>
#include <string.h>
#include "uritools.h"

static inline int natoi(const char *str, size_t len)
{
	int i, r = 0;
	for (i = 0; i < len; i++) {
		r *= 10;
		r += str[i] - '0';
	}

	return r;
}

static inline int is_relative(const char *uri)
{
	return (*uri == '/') ? 1 : 0;
}

static inline char *parse_scheme(char *str)
{
	char *s;

	s = strchr(str, ':');
	if (s == NULL || s == str) {
		return NULL;
	}

	if (s[1] == '\0' || s[1] != '/' || s[2] == '\0' || s[2] != '/') {
		return NULL;
	}

	*s = '\0';

	return s + 3;
}

static inline char *find_and_terminate(char *str, char find)
{
	str = strchr(str, find);
	if (NULL == str) {
		return NULL;
	}

	*str = '\0';
	return str + 1;
}

static inline char *find_fragment(char *str)
{
	return find_and_terminate(str, '#');
}

static inline char *find_query(char *str)
{
	return find_and_terminate(str, '?');
}

static inline char *find_path(char *str)
{
	return find_and_terminate(str, '/');
}

int uri_parse(uri *u, char *s)
{
	if (NULL == u || NULL == s) {
		return -1;
	}

	memset(u, 0, sizeof (uri));

	u->fragment = find_fragment(s);
	u->query = find_query(s);

	if (!is_relative(s)) {
		u->scheme = s;
		s = parse_scheme(s);
		if (s == NULL) {
			return -1;
		}

		if (*s == '\0') {
			return -1;
		}
		u->host = s;
		u->path = find_path(s);
		s = strchr(u->host, '@');
		if (NULL != s) {
			if (s == u->host) {
				return -1;
			}

			u->username = u->host;
			u->host = s + 1;
			*s = '\0';

			s = strchr(u->username, ':');
			if (s == NULL) {
				return -1;
			}

			u->password = s + 1;
			*s = '\0';
		}

		if (*u->host == '\0') {
			return -1;
		}

		s = strchr(u->host, ':');
		if (s != NULL && (u->path == NULL || s < u->path)) {
			*(s++) = '\0';
			if (*s == '\0') {
				return -1;
			}

			if (u->path) {
				u->port = natoi(s, u->path - s - 1);
			} else {
				u->port = atoi(s);
			}
		}

		if (*u->host == '\0') {
			return -1;
		}
	} else {
		u->path = find_path(s);
	}

	return 0;
}

int uri_path_split(char *buf, char **resume)
{
	int i = 0;
	char *path = *resume;

	if (path == NULL || *path == '\0')
		return -1;

	while (*path == '/')
		path++;

	while(*path != '/' && *path != '\0')
		buf[i++] = *path++;
	buf[i] = '\0';

	*resume = path;
	return i;
}

void uri_free(uri *u) {
	free(u->uri_str);
}
