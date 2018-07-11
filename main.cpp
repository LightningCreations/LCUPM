#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <curl/curl.h>

#define NORMAL "\e[0m"
#define GREEN "\e[1;38;2;0;255;0m"
#define RED "\e[1;38;2;255;0;0m"

void quit() {
	exit(0);
}

void help(char* name) {
	printf(NORMAL);
	printf("Usage:\n");
	printf("\t%s fetch <packagename>\n", name);
	printf("\t%s help\n", name);
}

void helpFetch(char* name) {
	printf(NORMAL);
	printf("Usage (fetch):\n");
	printf("\t%s fetch <packagename>\n", name);
}

size_t writeFile(void* ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

void startDownload(char* url, char* resultName) {
	CURL *curl;
	FILE *fp;
	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
		fp = fopen(resultName, "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFile);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(fp);
	}
}

int main(int argc, char** argv) {
	printf(GREEN);
	printf("Lightning Creations Unified Package Manager\n");
	printf(NORMAL);
	printf("by InfernoDeity and Rdrpenguin\n");
	printf("Version 1.0\n");

	curl_global_init(CURL_GLOBAL_ALL);

	if(argc == 1) {
		printf(RED);
		printf("ERROR! Not enough arguments!\n");
		help(argv[0]);
		quit();
	}

	if(strcmp("fetch", argv[1]) == 0) {
		if(argc == 2) {
			printf(RED);
			printf("ERROR! Not enough arguments!\n");
			helpFetch(argv[0]);
			quit();
		}
		printf("Fetching %s...\n", argv[2]);
		startDownload(argv[2], (char*)"./download");
	} else if(strcmp("help", argv[1]) == 0) {
		help(argv[0]);
	}

	quit();
}
