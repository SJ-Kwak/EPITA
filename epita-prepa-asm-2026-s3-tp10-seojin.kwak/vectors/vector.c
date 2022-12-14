#include <err.h>
#include "vector.h"

struct vector *vector_new()
{
    struct vector *vector = malloc(sizeof(struct vector));

    if(vector == NULL){
        errx(1,"Not enough memory!");
    }

    vector -> capacity = 1;
    vector -> size = 0;
    vector -> data = malloc(1 * sizeof(int));

    if(vector -> data == NULL){
        errx(1,"Not enough memory!");
    }
    
    return vector;
}

void vector_free(struct vector *v)
{
    free(v -> data);
    free(v);
}

void double_capacity(struct vector *v)
{
    int *new = realloc(v -> data, (v -> capacity) * 2 * sizeof(int));

    if(new == NULL){
        errx(1,"Not enough memory");
    }

    v -> data = new;
    v -> capacity = v -> capacity * 2;
}

void vector_push(struct vector *v, int x)
{
    if(v -> capacity == v -> size){
        double_capacity(v);
    }

    v -> data[v -> size] = x;
    v -> size++;
}

int vector_pop(struct vector *v, int *x)
{
    if(v -> size == 0){
        return 0;
    }

    *x = v -> data[v -> size - 1];
    v -> size--;
}

int vector_get(struct vector *v, size_t i, int *x)
{
    if(i >= v -> size){
        return 0;
    }
    *x = v -> data[i];
    return 1;
}

void vector_insert(struct vector *v, size_t i, int x)
{
    if(v -> size == v -> capacity){
        double_capacity(v);
    }

    for(size_t j = v -> size; j + 1 >= i + 1; --j){
        v -> data[j + 1] = v -> data[j];
    }

    v -> data[i] = x;
    v -> size++;
}

int vector_remove(struct vector *v, size_t i, int *x)
{
    if(i > v -> size && v -> size > 0){
        return 0;
    }

    if(v -> size == v -> capacity){
        double_capacity(v);
    }

    *x = v -> data[i];
    while(i < v -> size - 1){
        i++;
        v -> data[i] = v -> data[i + 1];
    }

    v -> size--;

    return 1;
}