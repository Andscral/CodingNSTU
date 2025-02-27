/*#include <stdio.h>
#include <stdlib.h>

int shellSort(int arr[], int length, int* tryd)
{
    int shag, i, j, temp;
    for (shag = length / 2; shag > 0; shag /= 2)
    {
        for (i = shag; i < length; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= shag && arr[j - shag] > temp; j -= shag)
            {
                arr[j] = arr[j - shag];
                (*tryd)++;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    printf("<Laboratornaya #4>\n");

    int arr1[100], arr2[292], arr3[464];

    for (int i = 0; i < 100; i++)
    {
        arr1[i] = rand();
    }
    for (int i = 0; i < 292; i++)
    {
        arr2[i] = rand();
    }
    for (int i = 0; i < 464; i++)
    {
        arr3[i] = rand();
    }

    printf("\n-Trydoimkost-\n");
    int tryd = 0;
    shellSort(arr1, 100, &tryd);
    printf("%d ", tryd);
    tryd = 0;
    shellSort(arr2, 292, &tryd);
    printf("%d ", tryd);
    tryd = 0;
    shellSort(arr3, 464, &tryd);
    printf("%d ", tryd);

    printf("\n");
    return 0;
}*/

#include <stdio.h>

// Функция сортировки методом предварительного выбора
void selectSort(int arr[], int n, int* cnt1) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Переносим минимальный элемент в начало выходного массива
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        (*cnt1)++;
    }
}

// Функция метода погружения
void bubbleSort(int arr[], int n, int* cnt2) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами элементы, если они стоят в неправильном порядке
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*cnt2)++;
            }
        }
    }
}

int main() 
{
    system("chcp 1251");
    int arr1[1000], arr2[5000], arr3[10000];
    
    for (int i = 0; i < 1000; i++)
    {
        arr1[i] = rand();
    }
    for (int i = 0; i < 5000; i++)
    {
        arr2[i] = rand();
    }
    for (int i = 0; i < 10000; i++)
    {
        arr3[i] = rand();
    }
    int cnt1 = 0;
    int cnt2 = 0;

    selectSort(arr1, 1000, &cnt1);
    bubbleSort(arr1, 1000, &cnt2);
    int rez1 = &cnt1;
    int rez2 = &cnt2;
    printf("%d ", rez1 + rez2);

    cnt1 = 0; cnt2 = 0; 
    selectSort(arr2, 5000, &cnt1);
    bubbleSort(arr2, 5000, &cnt2);
    int rez11 = &cnt1;
    int rez21= &cnt2;
    printf("%d ", &rez11 + rez21);

    cnt1 = 0; cnt2 = 0;
    selectSort(arr3, 10000, &cnt1);
    bubbleSort(arr3, 10000, &cnt2);
    int rez111 = &cnt1;
    int rez211 = &cnt2;
    printf("%d ", rez111 + rez211);

    return 0;
}