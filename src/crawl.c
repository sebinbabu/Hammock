#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "crawl.h"
#include "file.h"
#include "tools.h"
#include "queue.h"

int load_queue(queue *q) {
	int ret = 0;
	char *urls;
	if(read_file(filelist[QUEUE], &urls) != 0) {
		ret = 1;
	} else {
		int depth, len;
		char *rest, *dep = strtok_r(urls, "\n", &rest), *str = strtok_r(NULL, "\n", &rest), *url;
    	while (dep != NULL) {
    		depth = parse_int(dep);
    		len = strlen(str);
    		url = malloc(sizeof(char) * (len + 1));
    		strcpy(url, str);

    		q_insert(q, create_node(url, depth, NULL));

    		dep = strtok_r(NULL, "\n", &rest); 
    		str = strtok_r(NULL, "\n", &rest);
    	}
    	free(urls);
	}
	return ret;
} 

int crawl(char *s) {
	int ret = 0;
	queue q;
	if(load_queue(&q) != 0) {
		ret = 1;
	} else {
    	fprintf(stdout, "Processing queue\n");
		while(q_empty(&q) == 0) {
			print_urls(q_peek(&q)->s);
			q_delete(&q);
		}
		q_free(&q);
	}
	return ret;
}