#include <stdio.h>
#include "isqrt.h"

int main(){
    int n = 0;
    printf("isqrt(0) = %lu\n", isqrt(0));
    for(int i = 1; i <= 25; i++){
        n = 8 * i;
        printf("isqrt(%d) = %lu\n", n, isqrt(n));
    }
    return 0;
}