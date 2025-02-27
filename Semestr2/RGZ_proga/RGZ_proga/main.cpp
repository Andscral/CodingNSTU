//1. Первый параметр - строка, в которой каждый символ «*» обозначает место включения строки, 
// являющейся очередным параметром. Функция выводит на экран полученный текст.

#include <stdio.h>
#include <stdarg.h>     

void F(const char* string, ...) 
{
    va_list args;       //тип для списка переменных аргументов.
    va_start(args, string); //инициализирует список переменных аргументов.

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '*') {
            const char* str = va_arg(args, const char*); //получает доступ к очередному аргументу.
            printf("%s", (const char*)str);
        }
        else {
            printf("%c", string[i]);
        }
    }
    va_end(args); //завершает работу с списком переменных аргументов.
}

int main() 
{
    F("I am s.\n", "Maks");
    F("* * *\n", "I", "want", "sleep");

    return 0;
}

//1. Сортировка строк файла по длине и по алфавиту и вывод результата в отдельный файл.
//C:/Users/Admin/НЭТИ/прога 2 семак/RGZ_proga/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int sravn(const void* a, const void* b) 
{
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;

    // Обрезаем символ новой строки, если он присутствует
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    return strcmp(str1, str2);
}

int main() 
{
    FILE* input, *output;
    char buffer[MAX_LEN];//для строк
    char* strings[MAX_LEN];//для указателей
    int num_strings = 0;

    input = fopen("C:/Users/Admin/НЭТИ/прога 2 семак/RGZ_proga/input.txt", "r");
    if (input == NULL) {
        perror("Error opening file"); //Error opening file: No such file or directory
        return 1;
    }
    // Считать строки из файла и сохранить указатели на них
    while (fgets(buffer, MAX_LEN, input) != NULL) {
        strings[num_strings] = _strdup(buffer);
        num_strings++;
    }
    // Закрыть исходный файл
    fclose(input);

    // Сортировка массива указателей
    qsort(strings, num_strings, sizeof(char*), sravn);

    // Открыть файл для записи отсортированных строк
    output = fopen("C:/Users/Admin/НЭТИ/прога 2 семак/RGZ_proga/output.txt", "w");
    if (output == NULL) {
        perror("Error opening file");
        return 1;
    }
    // Записать отсортированные строки в новый файл
    for (int i = 0; i < num_strings; i++) {
        fprintf(output, "%s\n", strings[i]);
        free(strings[i]);
    }
    // Закрыть файл для записи
    fclose(output);

    return 0;
}