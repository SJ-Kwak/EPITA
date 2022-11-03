#include <stdio.h>

long is_partition(unsigned char a[], size_t len, unsigned char pivot);

static void array_print(unsigned char* a, unsigned long len)
{
    printf("{ ");

    for (unsigned long i = 0; i < len; i++)
        printf("%hhu ", a[i]);

    printf("}\n");
}

static void test(unsigned char a[], unsigned long len, unsigned char pivot)
{
    // Prints the array.
    printf("a = ");
    array_print(a, len);

    // Gets the result of the function to test.
    long pivot_index = is_partition(a, len, pivot);

    // Prints the result.
    printf("is_partition(a, %lu, %hhu) -> %zi\n\n", len, pivot, pivot_index);
}

int main()
{
    unsigned char a0[] = { 1, 10, 8, 15, 18, 19, 77 };
    unsigned char a1[] = { 1, 2, 3, 4, 5, 6, 4, 6 };
    unsigned char a2[] = { 1, 2, 3, 4, 5, 3, 4, 5 };
    unsigned char a3[] = { 3, 1, 2, 3, 10, 5, 3, 7, 5 };
    unsigned char a4[] = { 1, 2, 3, 4, 5 };
    unsigned char a5[] = { 5, 4, 3, 2, 1 };
    unsigned char a6[] = { 3, 1, 2, 3, 3, 3, 3, 4, 5 };

    test(a0, sizeof(a0), 15);
    test(a0, sizeof(a0), 16);
    test(a0, sizeof(a0), 77);
    test(a0, sizeof(a0), 10);
    test(a1, sizeof(a1), 6);
    test(a2, sizeof(a2), 3);
    test(a3, sizeof(a3), 3);
    test(a4, sizeof(a4), 1);
    test(a4, sizeof(a4), 5);
    test(a4, sizeof(a4), 3);
    test(a5, sizeof(a5), 5);
    test(a5, sizeof(a5), 1);
    test(a5, sizeof(a5), 3);
    test(a6, sizeof(a6), 3);

    return 0;
}
