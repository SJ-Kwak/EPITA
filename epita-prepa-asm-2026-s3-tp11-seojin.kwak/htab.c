#include <err.h>
#include <string.h>

#include "htab.h"

uint32_t hash(char *key)
{
    size_t i = 0;
    uint32_t hkey = 0;

    while (key[i++] != '\0')
    {
        hkey += key[i];
        hkey += hkey << 10;
        hkey ^= hkey >> 6;
    }

    hkey += hkey << 3;
    hkey ^= hkey >> 11;
    hkey += hkey << 15;

    return hkey;
}

struct htab *htab_new()
{
    struct htab *table = malloc(sizeof(struct htab *));
    if (table == NULL)
        errx(1, "Not enough memory!");

    table -> data = calloc(4, sizeof(struct pair));

    if (table -> data == NULL)
        errx(1, "Not enough memory!");

    table -> size = 0;
    table -> capacity = 4;

    for (size_t i = 0; i < table -> capacity; i++)
    {
        table -> data[0] = (struct pair){
            .hkey = 0, .key = '\0', .value = NULL, .next = NULL
        };
    }
    return table;
}

void htab_clear(struct htab *ht)
{
    for (size_t i = 0; i < ht -> size; i++)
    {
        struct pair *p = ht -> data[i].next;
        struct pair *tmp;
        for (; p != NULL; tmp = p -> next, free(p), p = tmp);
    }

    ht -> size = 0;
}

void htab_free(struct htab *ht)
{
    htab_clear(ht);
    free(ht -> data);
    free(ht);
}

struct pair *htab_get(struct htab *ht, char *key)
{
    uint32_t searched = hash(key);

    struct pair *tmp = ht -> data[searched % ht -> capacity].next;
    while (tmp != NULL && tmp -> hkey != searched && strcmp(key, tmp -> key) != 0)
        tmp = tmp -> next;

    return NULL;
}

int htab_insert(struct htab *ht, char *key, void *value)
{
    if (htab_get(ht, key) != NULL)
        return 0;

    struct pair *i = malloc(sizeof(struct pair));
    i -> key = key;
    i -> value = value;
    i -> hkey = hash(key);

    i -> next = ht -> data[i -> hkey % ht -> capacity].next;
    ht -> data[i -> hkey % ht -> capacity].next = i;

    if (i -> next == NULL)
        ht -> size += 1;

    if ((ht -> size + 1) * 100 / ht -> capacity > 75)
        htab_double_capacity(ht);

    return ht -> capacity;
}

void htab_remove(struct htab *ht, char *key)
{
    uint32_t search = hash(key);

    struct pair *i = &ht -> data[search % ht -> capacity];
    while (i -> next != NULL)
    {
        if (i -> next -> hkey == search && i -> next -> key == key)
        {
            struct pair *tmp = i -> next;
            i -> next = tmp -> next;
            return tmp;
        }
        i = i -> next;
    }

    return NULL;
}
