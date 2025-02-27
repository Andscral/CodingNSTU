#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int cnt_razriad;
} Data;

void Elements(Data* arr, int* size, int val) 
{
    arr[*size].value = val;

    int cnt = 0;
    for (int i = 0; i < 8*sizeof(int); i++) if ((val >> i) & 1) cnt++;
    arr[*size].cnt_razriad = cnt;
    (*size)++;
}

void sort_numRazriad(Data* arr, int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].cnt_razriad > arr[j + 1].cnt_razriad) {
                Data temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void trace(Data* arr, int size) 
{
    printf("trace: \n");
    for (int i = 0; i < size; i++) printf("%d. Value: %d, cnt.razriad: %d\n", i + 1, arr[i].value, arr[i].cnt_razriad);
}

int main() 
{

    //вывод 1
    Data arr1[100];
    int size1 = 0;
    Elements(arr1, &size1, 15);//1
    Elements(arr1, &size1, 7);//2
    Elements(arr1, &size1, 10);//3
    Elements(arr1, &size1, 3);//4
    Elements(arr1, &size1, 20);//5
    Elements(arr1, &size1, 8);//6
    Elements(arr1, &size1, 5);//7
    Elements(arr1, &size1, 1);//8
    Elements(arr1, &size1, 23);//9
    Elements(arr1, &size1, 4);//10
    Elements(arr1, &size1, 9);//11
    Elements(arr1, &size1, 6);//12
    Elements(arr1, &size1, 19);//13
    Elements(arr1, &size1, 7);//14
    Elements(arr1, &size1, 31);//15
    Elements(arr1, &size1, 29);//16

    sort_numRazriad(arr1, size1);
    printf("10th value: %d (cnt: %d)\n", arr1[9].value, arr1[9].cnt_razriad);
    printf("16th value: %d (cnt: %d)\n", arr1[15].value, arr1[15].cnt_razriad);

    trace(arr1, size1);

    printf("\n\n");

    //вывод 2

    Data arr2[100];
    int size2 = 0;
    Elements(arr2, &size2, 39);//1
    Elements(arr2, &size2, 41);//2
    Elements(arr2, &size2, 7);//3
    Elements(arr2, &size2, 12);//4
    Elements(arr2, &size2, 22);//5
    Elements(arr2, &size2, 81);//6
    Elements(arr2, &size2, 53);//7
    Elements(arr2, &size2, 15);//8
    Elements(arr2, &size2, 34);//9
    Elements(arr2, &size2, 13);//10
    Elements(arr2, &size2, 1);//11
    Elements(arr2, &size2, 110);//12
    Elements(arr2, &size2, 89);//13
    Elements(arr2, &size2, 8);//14
    Elements(arr2, &size2, 60);//15
    Elements(arr2, &size2, 3);//16

    sort_numRazriad(arr2, size2);
    printf("10th value: %d (cnt: %d)\n", arr2[9].value, arr2[9].cnt_razriad);
    printf("16th value: %d (cnt: %d)\n", arr2[15].value, arr2[15].cnt_razriad);

    trace(arr2, size2);

    return 0;
}
