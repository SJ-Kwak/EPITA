#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "basics.h"

void exit_help()
{
    char help[] =
        "Usage:\n"
        "--chr char string\n"
        "--cat string1 string2\n"
        "--cmp string1 string2\n"
        "--toui string\n"
        "--rmchr char string";

    errx(EXIT_FAILURE, "%s", help);
}

void test_chr(int argc, char** argv)
{
    if (argc != 4 || strlen(argv[2]) != 1)
        exit_help();

    printf("%zu\n", str_chr(argv[3], argv[2][0]));
}

void test_cat(int argc, char** argv)
{
    if (argc != 4)
        exit_help();

    size_t len1 = strlen(argv[2]);
    size_t len2 = strlen(argv[3]);

    char* str1 = malloc(len1 + len2 + 1);
    strcpy(str1, argv[2]);

    str_cat(str1, argv[3]);
    printf("%s\n", str1);

    free(str1);
}

void test_cmp(int argc, char** argv)
{
    if (argc != 4)
        exit_help();

    int result = str_cmp(argv[2], argv[3]);

    char cmp;
    if (result < 0)
        cmp = '<';
    else if (result == 0)
        cmp = '=';
    else
        cmp = '>';

    printf("\"%s\" %c \"%s\"\n", argv[2], cmp, argv[3]);
}

void test_atoui(int argc, char** argv)
{
    if (argc != 3)
        exit_help();

    printf("%u\n", str_toui(argv[2]));
}

void test_rmchr(int argc, char** argv)
{
    if (argc != 4 || strlen(argv[2]) != 1)
        exit_help();

    char* str = malloc(strlen(argv[3]));
    strcpy(str, argv[3]);

    rm_chr(argv[2][0], str);
    printf("%s\n", str);

    free(str);
}

int main(int argc, char** argv)
{
    if (argc == 1)
        exit_help();

    if (strcmp(argv[1], "--chr") == 0)
        test_chr(argc, argv);
    else if (strcmp(argv[1], "--cat") == 0)
        test_cat(argc, argv);
    else if (strcmp(argv[1], "--cmp") == 0)
        test_cmp(argc, argv);
    else if (strcmp(argv[1], "--toui") == 0)
        test_atoui(argc, argv);
    else if (strcmp(argv[1], "--rmchr") == 0)
        test_rmchr(argc, argv);
    else
        exit_help();

    return EXIT_SUCCESS;
}
