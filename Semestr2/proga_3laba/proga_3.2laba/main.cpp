//2. Функция получает строку текста и возвращает динамический массив указателей на слова. 
//Каждое слово копируется в отдельный массив в динамической памяти.

/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** F2(char* input, int* numWords) 
{
    char** words = NULL;
    *numWords = 0;

    char* str = strtok(input, " ");
    while (str != NULL) 
    {
        (*numWords)++;
        words = (char**)realloc(words, (*numWords) * sizeof(char*)); 
        words[(*numWords) - 1] = (char*)malloc(strlen(str) + 1);
        strcpy(words[(*numWords) - 1], str);
        str = strtok(NULL, " ");
    }
    return words;
}

int main() 
{
    char input[] = { "i go home and 1-iy skill and 3-iy" };
    printf("Normal string: %s\n\n", input);

    int numWords;
    char** words = F2(input, &numWords);
    printf("F2:\n");
    for (int i = 0; i < numWords; i++) 
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}*/

//4. Функция находит в строке фрагменты, симметричные относительно центрального символа, 
// длиной 7 и более символов (например, "abcdcba") и 
// возвращает динамический массив указателей на копии таких фрагментов.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** Symetria(char* str, int* cntfrag) {
    int n = strlen(str);

    char** fragments = (char**)malloc(sizeof(char*));
    int count = 0;
    *cntfrag = 0;

    for (int i = 3; i < n - 3; i++) {
        int len = 7;
        while (i - len / 2 >= 0 && i + len / 2 < n && str[i - len / 2] == str[i + len / 2]) {
            (*cntfrag)++;
            char* fragment = (char*)malloc(len + 1);
            strncpy(fragment, str + i - len / 2, len);
            fragment[len] = '\0';

            fragments = (char**)realloc(fragments, (count + 1) * sizeof(char*));
            fragments[count] = fragment;
            count++;

            len += 2;
        }
    }

    return fragments;
}

int main() {
    int cntfrag;
    char str[] = "adaabcdcbaabbaafghuhgfa";
    char** result = Symetria(str, &cntfrag);

    printf("Symmetric Fragments:\n");
    for (int i = 0; i < cntfrag; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);

    return 0;
}