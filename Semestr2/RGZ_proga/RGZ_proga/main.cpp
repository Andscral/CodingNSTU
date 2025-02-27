//1. ������ �������� - ������, � ������� ������ ������ �*� ���������� ����� ��������� ������, 
// ���������� ��������� ����������. ������� ������� �� ����� ���������� �����.

#include <stdio.h>
#include <stdarg.h>     

void F(const char* string, ...) 
{
    va_list args;       //��� ��� ������ ���������� ����������.
    va_start(args, string); //�������������� ������ ���������� ����������.

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '*') {
            const char* str = va_arg(args, const char*); //�������� ������ � ���������� ���������.
            printf("%s", (const char*)str);
        }
        else {
            printf("%c", string[i]);
        }
    }
    va_end(args); //��������� ������ � ������� ���������� ����������.
}

int main() 
{
    F("I am s.\n", "Maks");
    F("* * *\n", "I", "want", "sleep");

    return 0;
}

//1. ���������� ����� ����� �� ����� � �� �������� � ����� ���������� � ��������� ����.
//C:/Users/Admin/����/����� 2 �����/RGZ_proga/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int sravn(const void* a, const void* b) 
{
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;

    // �������� ������ ����� ������, ���� �� ������������
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    return strcmp(str1, str2);
}

int main() 
{
    FILE* input, *output;
    char buffer[MAX_LEN];//��� �����
    char* strings[MAX_LEN];//��� ����������
    int num_strings = 0;

    input = fopen("C:/Users/Admin/����/����� 2 �����/RGZ_proga/input.txt", "r");
    if (input == NULL) {
        perror("Error opening file"); //Error opening file: No such file or directory
        return 1;
    }
    // ������� ������ �� ����� � ��������� ��������� �� ���
    while (fgets(buffer, MAX_LEN, input) != NULL) {
        strings[num_strings] = _strdup(buffer);
        num_strings++;
    }
    // ������� �������� ����
    fclose(input);

    // ���������� ������� ����������
    qsort(strings, num_strings, sizeof(char*), sravn);

    // ������� ���� ��� ������ ��������������� �����
    output = fopen("C:/Users/Admin/����/����� 2 �����/RGZ_proga/output.txt", "w");
    if (output == NULL) {
        perror("Error opening file");
        return 1;
    }
    // �������� ��������������� ������ � ����� ����
    for (int i = 0; i < num_strings; i++) {
        fprintf(output, "%s\n", strings[i]);
        free(strings[i]);
    }
    // ������� ���� ��� ������
    fclose(output);

    return 0;
}