#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "split_merge.h"

void exit_help()
{
    char help[] =
        "Usage:\n"
        "--split string\n"
        "--merge string1 string2 ...";

    errx(EXIT_FAILURE, "%s", help);
}

void test_split(int argc, char** argv)
{
    if (argc != 3)
        exit_help();

    char words[MAX_WORD][MAX_CHAR];

    split(argv[2], words);

    for (size_t i = 0; words[i][0]; i++)
        printf("word %02zu: %s\n", i, words[i]);
}

void test_merge(int argc, char** argv)
{
    if (argc < 2)
        exit_help();

    char str[MAX_WORD * MAX_CHAR];

    merge(str, argc, argv);

    printf("%s\n", str);
}

int main(int argc, char** argv)
{
    if (argc == 1)
        exit_help();

    if (strcmp(argv[1], "--split") == 0)
        test_split(argc, argv);
    else if (strcmp(argv[1], "--merge") == 0)
        test_merge(argc, argv);
    else
        exit_help();

    return EXIT_SUCCESS;
}

