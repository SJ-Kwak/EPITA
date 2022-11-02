#include <stdio.h>
#include "fibo.h"

int main(){
    for(int i = 0; i <= 10; i++){
        printf("fibo(%d) = %lu\n", i, fibo(i));
    }
    printf("...\n");
    for(int i = 81; i <= 90; i++){
        printf("fibo(%d) = %lu\n", i, fibo(i));
    }
    return 0;
}