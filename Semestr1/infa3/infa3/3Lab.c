#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palit(char* str, int start, int end) 
{
    while (start < end)
    {
        if ((str[start]) != (str[end])) 
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void reverse_remove(char* str) 
{
    int length = strlen(str);
    int start = 0, end, i;

    for (i = 0; i <= length; i++) 
    {
        if (str[i] == ' ' || str[i] == '\0') 
        {
            end = i - 1;
            while (start < end) 
            {
                char temp = str[start]; 
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }

    printf("reverse: %s\n", str);

    start = 0;
    for (i = 0; i <= length; i++) 
    {
        if (str[i] == ' ' || str[i] == '\0') 
        {
            end = i - 1;
            if (palit(str, start, end)) 
            {
                memmove(&str[start], &str[i + 1], length - i);
                length -= (i - start + 1);
                i = start;
            }
            else 
            {
                start = i + 1;
            }
        }
    }

    printf("not palit: %s\n", str);
}

int main() 
{
    char str[] = "can you joj rotating fuouf hijhc";
    printf("Normal string: %s", str);
    printf("\n");

    reverse_remove(str);

    return 0;
}

/*#include <stdio.h>
#include <string.h>

int main() {
    system("chcp 1251");

    char input[] = "Эта строка содержит два одинаковых фрагмента: 'двинак' и 'двинак'. Удалим их и продолжим поиск.";
    char output[1000] = "";
    int a = strlen(input);
    int i, j;

    while (a > 0) {
        int found = 0;
        for (i = 0; i < a - 5; i++) {
            for (j = i + 1; j < a - 5; j++) {
                if (input[i] != ' ' && input[j] != ' ' && strncmp(&input[i], &input[j], 6) == 0) {
                    strncat(output, &input[i], 6);
                    memmove(&input[j], &input[j + 6], strlen(&input[j + 6]) + 1);
                    memmove(&input[i], &input[i + 6], strlen(&input[i + 6]) + 1);
                    a = strlen(input);
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (!found) {
            strncat(output, &input[0], 1);
            memmove(&input[0], &input[1], strlen(&input[1]) + 1);
            a = strlen(input);
        }
    }

    strcat(output, input);
    printf("%s\n", output);

    return 0;
}*/