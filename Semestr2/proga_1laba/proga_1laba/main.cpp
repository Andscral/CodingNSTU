//12. Найти в строке последовательности, 
// состоящие из одного повторяющегося символа и заменить его на число символов 
// и один символ (например "aaaaaa" - "5a").

#include <stdio.h>
#include <string.h>

void F12(char* str) 
{
    int cnt = 1;
    char string = *str;
    char* next = str + 1;

    while (*next)                              //идем по строке с первого символа
    {
        if (*next == string) cnt++;
        else {
            printf("%d%c", cnt, string);
            cnt = 1;
            string = *next;
        }
        next++;
    }
    printf("%d%c\n", cnt, string);
}

int main() 
{
    char str[] = "aaaaabbbbcccddddeee";
    printf("normal string: %s\n", str);
    printf("result: ");
    F12(str);

    return 0;
}