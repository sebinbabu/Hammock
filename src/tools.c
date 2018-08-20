#include <curl/curl.h>

#include "tools.h"
#include "re.h"
#include "htmlparser.h"

const char* url_re = "^https?://[^/\\n]+{/[^\\\\/%\\n]+}*{/?\\?[^&\\n]+{&[^&\\n]+}*}?/?$";


static size_t write_callback(void *buffer, size_t size, size_t nmemb, void *hsp) {
  size_t realsize = size * nmemb, p;
  for(p = 0; p < realsize; p++) {
    html_parser_char_parse(hsp, ((char *)buffer)[p]);
    if(html_parser_cmp_tag(hsp, "a", 1))
      if(html_parser_cmp_attr(hsp, "href", 4))
        if(html_parser_is_in(hsp, HTML_VALUE_ENDED)) {
          html_parser_val(hsp)[html_parser_val_length(hsp)] = '\0';
          fprintf(stdout, "%s\n", html_parser_val(hsp));
        }
  }
  return realsize;
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
	return re_match(url_re, s) == -1;
}

int print_urls(char *s) {
	char tag[1], attr[4], val[128];
	CURL *curl;
	HTMLSTREAMPARSER *hsp;
  
	curl = curl_easy_init();

	hsp = html_parser_init();

	html_parser_set_tag_to_lower(hsp, 1);
	html_parser_set_attr_to_lower(hsp, 1);
	html_parser_set_tag_buffer(hsp, tag, sizeof(tag));
	html_parser_set_attr_buffer(hsp, attr, sizeof(attr));
	html_parser_set_val_buffer(hsp, val, sizeof(val)-1);

	curl_easy_setopt(curl, CURLOPT_URL, s);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, hsp);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	html_parser_cleanup(hsp);

	return EXIT_SUCCESS;
}
