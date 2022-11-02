#include "is_perfect_number.h"
#include "divisor_sum.h"

int is_perfect_number(unsigned long n){
    unsigned long sum = divisor_sum(n);
    if (sum == n){
        return n;
    } else{
        return 0;
    }
}