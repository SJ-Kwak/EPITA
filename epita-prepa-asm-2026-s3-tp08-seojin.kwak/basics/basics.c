#define _GNU_SOURCE
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

unsigned long* array_fibo(size_t n)
{
    unsigned long* p = malloc(n * sizeof(unsigned long));
    for(size_t i = 0; i < n; i++){
        if(i <= 1)
            *(p+i) = i;
        else
            *(p+i) = *(p+(i-1)) + *(p+(i-2));
    }
    return p;
}

char* str_toupper(const char* s)
{
    size_t size = strlen(s);
    char* str = malloc((size+1) * sizeof(char));
    for(size_t i = 0; i < size; i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            *(str+i) = toupper(*(s+i));
        else
            *(str+i) = *(s+i);
    }
    return str;
}

unsigned char* array_pal_1(unsigned char* a, size_t len)
{
    unsigned char* arr = realloc(a, (len*2) * sizeof(unsigned char));
    for(size_t i = 0; i < len; i++){
        *(arr + i) = *(a + i);
    }
    size_t j = len - 1;
    for(size_t i = len; i < len*2; i++){
        *(arr + i) = *(a + j);
        j--;
    }
    return arr;
}

void array_pal_2(unsigned char** a, size_t len)
{
    
}

size_t array_min(unsigned char* a, size_t len, unsigned char threshold, unsigned char** result)
{
    size_t length = 0;
    for(size_t i = 0; i < len; i++){
        if(*(a+i) < threshold){
            **(result + i) = *(a + i);
            length = strlen(result);
        }
    }
    if(length == 0){
        *result = NULL;
        return 0;
    }
    return length;
}

void str_checksum(char** s)
{
    
}