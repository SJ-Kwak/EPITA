#include <stdio.h>
#include "is_perfect_number.h"

int main(){
    for(int i = 1; i <= 100000; i++){
        if(is_perfect_number(i) != 0){
            printf("%d\n", i);
        }
    }
    return 0;
}