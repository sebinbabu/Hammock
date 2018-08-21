#include <malloc.h>
#include <curl/curl.h>
#include <string.h>
#include <stdio.h>

#include "remote.h"

typedef struct REMOTEDATA {
	char *data;
	size_t size;
} remotedata;

static void* c_realloc(void *ptr, size_t size) {
  if(ptr != NULL)
    return realloc(ptr, size);
  else
    return malloc(size);
}

static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
  size_t realsize = size * nmemb;
  remotedata *mem = (remotedata*) data;
  mem->data = (char *) c_realloc(mem->data, mem->size + realsize + 1);
  if (mem->data != NULL) {
    memcpy(&(mem->data[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->data[mem->size] = 0;
  }
  return realsize;
}

char* dl_to_buffer(char *url) {
	CURL *curl;
	CURLcode res;
	char errbuf[CURL_ERROR_SIZE];
	remotedata buf = {malloc(sizeof(char) * 300000), 0};
	char *ret = NULL;
	curl = curl_easy_init();

	if(curl) {
		errbuf[0] = 0;
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if(res != CURLE_OK) {
			size_t len = strlen(errbuf);
    		fprintf(stderr, "\nlibcurl: (%d) ", res);
    		if(len)
      			fprintf(stderr, "%s%s", errbuf, ((errbuf[len - 1] != '\n') ? "\n" : ""));
      		else
				fprintf(stderr, "%s\n", curl_easy_strerror(res));
			ret = NULL;
		}
		ret = buf.data;
	}
	return ret;
}