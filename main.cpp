#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

#include <Text.hpp>
#include <Errors.hpp>

using namespace std::string_literals;


void quit() {
	throw exit_program();
}

void help(Terminal& t,char* name) {
	/*
	printf(NORMAL);
	printf("Usage:\n");
	printf("\t%s fetch <packagename>\n", name);
	printf("\t%s help\n", name);
	*/
	t.print(Color::Reset)
	.print("Usage"s,endline)
	//.print(tab,name,"fetch <packagename>",endline)
	.print(tab,name," help"s,endline);
}
/*
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
*/

int main(int argc, char** argv) {
	Terminal t;
	try{
		/*
		printf(GREEN);
		printf("Lightning Creations Unified Package Manager\n");
		printf(NORMAL);
		printf("by InfernoDeity and Rdrpenguin\n");
		printf("Version 1.0\n");
		*/
		
		/*
		curl_global_init(CURL_GLOBAL_ALL);
		*/
		if(argc == 1) {
			/*
			printf(RED);
			printf("ERROR! Not enough arguments!\n");
			*/
			t.print(foreground<Color::RED>,"ERROR! Not enough arguments!"s,endline);
			help(t,argv[0]);
			t.print("Press any key to exit>"s,endline).wait();
			return 0;
		}
		
		/*
		if(strcmp("fetch", argv[1]) == 0) {
			if(argc == 2) {
				printf(RED);
				printf("ERROR! Not enough arguments!\n");
				helpFetch(argv[0]);
				return 0;
			}
			printf("Fetching %s...\n", argv[2]);
			startDownload(argv[2], (char*)"./download");
		} else*/ if(strcmp("help", argv[1]) == 0) {
			help(t,argv[0]);
		}
	}catch(exit_program e){
		return e.getCode();
	}
	
	return 0;
}
