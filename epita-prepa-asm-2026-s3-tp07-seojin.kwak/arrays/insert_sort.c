#include <stdlib.h>
#include "helper.h"
#include "insert_sort.h"

// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x){
    
    while(end >= begin && x < *(end - 1)){
        *end = *(end - 1);
        end--;
    }
    *end = x;
}

// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x){
    int *mid = NULL;
    int *high = end;
    while (begin <= high){
        mid = begin + ((high - begin) / 2);
        if (x == *mid){
            break;
        } else if (*mid < x){
            begin = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (*mid < x){
        mid++;
    }
    int *p = end;
    while (p > mid){
        *p = *(p-1);
        p--;
    }
    *mid = x;
}

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end){

    for (int *i = begin + 1; begin < end; begin++){
        array_insert(i, begin, *begin);
    }
}

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end){
    for (int *i = begin + 1; i < end; i++){
        array_insert_bin(begin, i, *i);
    }
}