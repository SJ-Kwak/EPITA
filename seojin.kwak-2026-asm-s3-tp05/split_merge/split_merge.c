#include <stddef.h>
#include "split_merge.h"
#include <string.h>
#include <stdio.h>

void split(char s[], char words[][MAX_CHAR])
{
	size_t len = strlen(s);
	size_t j = 0, k = 0;
    	for(size_t i = 0; i <= len; i++){
		if(s[i] == ' ' || s[i] == '\0'){
			words[j][k] = '\0';
			j++;	// for next word
			k = 0;	// for next word, init index to 0
		}
		else {
			words[j][k] = s[i];
			k++;
		}
	}
}

void merge(char s[], size_t argc, char** argv)
{
	size_t len = strlen(s);
	size_t j = 2, k = 0;
	while(j != argc){
		for(size_t i = 0; i < len; i++){
			if(argv[j][i] == ' '){
				j++;
				k = 0;
			}
			else {
				s[i] = argv[j][k];
				k++;
			}
		}
	}
}
