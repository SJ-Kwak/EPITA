#include <stdio.h>
#include "power_of_two.h"

int main(){
    printf("power_of_two(0) = %lu\n", power_of_two(0));
    for(int i = 1; i < 64; i++){
        printf("power_of_two(%d) = %lu\n", i, power_of_two(i));
    }
    return 0;
}