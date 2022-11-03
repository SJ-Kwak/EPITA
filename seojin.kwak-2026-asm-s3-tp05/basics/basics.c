#include <stddef.h>
#include <string.h>
#include <stdlib.h>

size_t str_chr(char s[], char c)
{
	size_t idx = strlen(s);
	size_t null_idx = 0;
    	for(size_t i = 0; i < idx; i++){
		if(s[i] == ' ')
                        null_idx = i;
		if(s[i] == c){
			if(s[i] != s[idx])
				idx = i;
			else
				continue;
		}
	}
	if(idx == strlen(s))
		return null_idx;
	else
		return idx;
}

void str_cat(char s1[], char s2[])
{
	strcat(s1, s2);
}

int str_cmp(char s1[], char s2[])
{	
	return strcmp(s1, s2);
	/*
	size_t s_1 = sizeof(s1) / sizeof(char);
	size_t s_2 = sizeof(s2) / sizeof(char);
	size_t size = (s_1 <= s_2) ? s_2 : s_1;
	int result = 0;
    	for(size_t i = 0; i < size; i++){
		if(s1[i] != s2[i])
			result = s1[i] - s2[i];
	}
	return result;*/
}

unsigned int str_toui(char s[])
{
    	return atoi(s);
}

void rm_chr(char c, char s[])
{
	size_t len = strlen(s);
    	for(size_t i = 0; i < len; i++){
		if(s[i] == c){
			for(size_t j = i; j < len; j++){
				s[j] = s[j+1];
			}
			len--;
			i--;
		}
	}
}
