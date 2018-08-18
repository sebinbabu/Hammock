#include "tools.h"
#include "re.h"

const char* url_re = "^https?://[^/\\n]+{/[^\\\\/%\\n]+}*{/?\\?[^&\\n]+{&[^&\\n]+}*}?/?$";
const char* mul_url_re = "^https?://[^/\\n]+{/[^\\\\/%\\n]+}*{/?\\?[^&\\n]+{&[^&\\n]+}*}?/?$";

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
	return re_match(url_re, s) == -1;
}