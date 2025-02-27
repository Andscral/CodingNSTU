//Группа: АВТ-341
//Лабораторная работа №8

//Задача 5(Буслаев Максим)

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void umnoj(char num1[], char num2[]) 
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;
    int* result = (int*)malloc(sizeof(int) * result_len); // динамическое выделение памяти

    for (int i = 0; i < result_len; i++) {  //нулики
        result[i] = 0;
    }

    for (int i = 0; i < len2; i++) {
        int last = 0;               //last для хранения переноса при умножении
        int n2 = num2[len2 - 1 - i] - '0'; //получаем цифры числа num2 в текущей позиции и преобразование её в целое число

        for (int j = 0; j < len1; j++) {
            int n1 = num1[len1 - 1 - j] - '0';
            int p = n1 * n2 + result[i + j] + last;//произведения цифр, учитывая предыдущий перенос
            last = p / 10;  //Сохраняем перенос для следующей итерации
            result[i + j] = p % 10; //и сохраняем последние цифры результата умножения
        }

        result[i + len1] += last;// добавляем остатки к следующей цифре результата умножения
    }

    printf("Result: ");
    int i = result_len - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }

    if (i == -1) {
        printf("0\n");
    }
    else {
        for (; i >= 0; i--) {
            printf("%d", result[i]);
        }
        printf("\n");
    }
}

int main() 
{
    char num1[] = "12";
    char num2[] = "4";

    umnoj(num1, num2);

    return 0;
}*/

//Задача 7(Малышев Кирилл)

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для складывания двух чисел, заданных строками цифр
void sub(char num1[], char num2[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 < len2) {
        printf("Error: First number must be greater or equal in length to the second number.\n");
        return;
    }

    int* result = (int*)malloc(sizeof(int) * len1); // динамическое выделение памяти

    int borrow = 0;
    for (int i = 0; i < len1; i++) {
        int n1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int n2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;

        int diff = n1 - n2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result[i] = diff;
    }

    printf("Result: ");
    int i = len1 - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }

    if (i == -1) {
        printf("0\n");
    }
    else {
        for (; i >= 0; i--) {
            printf("%d", result[i]);
        }
        printf("\n");
    }

    free(result);
}

int main()
{
    char num1[] = "4";
    char num2[] = "2";

    sub(num1, num2);

    return 0;
}*/