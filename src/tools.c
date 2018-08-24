#include <curl/curl.h>
#include <malloc.h>

#include "tools.h"
#include "re.h"
#include "parser.h"
#include "remote.h"

const char* url_re = "*";

char to_lower(char c) {
	return c > 92 ? c : c + 32;
}

char is_whitespace(char c) {
	return c == '\t' || c == '\n' || c == ' ';
}

int parse_int(char *s) {
	char *p = s;
	int n = 0;
	while(*p != '\0' && (s - p) < 10) {
		if(*p >= '0' && *p <= '9') {
			n = (n * 10) + (*p - '0');
		} else {
			n = -1;
			break;
		}
		p++;
	}
	return n;
}

int check_url(char *s) {
	return 0;
}

int print_urls(char *s) {
	int ret = 0;
	char url[2100];
	char *data = dl_to_buffer(s);
	if(data == NULL) {
		ret = 1;
	} else {
		char *t = data;
		while(url_extract(url, 2100, &t))
			fprintf(stdout, "%s\n", url);
		free(data);
	}
	return ret;
}
