#define _GNU_SOURCE
#include <malloc.h>
#include <string.h>

void words_free(char** words)
{
    // Frees the strings.
    for (size_t i = 0; words[i]; i++)
        free(words[i]);

    // Frees the string pointers.
    free(words);
}

char** split(char* s)
{
	unsigned long str_length = 0;
    int i = 0;
    int separator_count = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            separator_count++;
        }
        i++;
    }

    char **word_array;

    word_array = malloc((separator_count + 2) * sizeof(char *));  

    int word_len = 0;
    int separator_index = 0;
    int b = 0;                                     //to iterate over "str"
  
    for (int a = 0; a < (separator_count + 2); a++) {
        word_len = 0;
        while (str_length < strlen(s) + 1) {
            str_length++;

            if (s[b] == ' ' || s[b] == '\0') {
                separator_index = b;
                word_array[a] = malloc(word_len * sizeof(char));
                int word_depth = 0;
                for (int c = (separator_index - word_len); c < separator_index; c++) {
                    word_array[a][word_depth] = s[c];
                    word_depth++;
				}
                word_array[a][word_len] = '\0';         //terminate found and stored word with null charachter
                word_len = 0;                           //reset word length counter to 0
                b++;                                    //skip to next charachter
                break;                                  // break to go to next index of word_array
            }
            word_len++;
            b++;
        }
    }
    word_array[separator_count + 2] = NULL;
    return word_array;
}
