#include <stdio.h>
#include "digit_count.h"

int main(){
    unsigned long n = 1;
    printf("digit_count(0) = %lu\n", digit_count(0));
    for(int i = 1; i <= 64; i++){
        printf("digit_count(%lu) = %lu\n", n, digit_count(n));
        n *= 2;
    }
    return 0;
}