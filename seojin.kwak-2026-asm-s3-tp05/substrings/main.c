#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char* check(char s1[], char s2[]){
	
	char* str;
	str = strstr(s1, s2);
	if(str){
		return str;
	}
	else
		return NULL;
}

int main(int argc, char** argv) {
	
	//if(argc == 1)
	//	errx(1, "main: Usage: str1 str2");
	
	char* result = check(argv[1], argv[2]);
	char* first = strchr(argv[1], argv[2][0]);
	if(result){
		printf("%s\n", argv[1]);
		for(; first < result; first++)
			printf("0");
		printf("^");
	}
	else
		printf("Not Found!");
}
