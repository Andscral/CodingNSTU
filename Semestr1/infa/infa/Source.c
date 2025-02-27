#include <stdio.h>

int main() 
{
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf_s("%d %d %d", &a, &b, &c);
    printf("\nResult: ", a, b, c);


    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 0; j <= 9; j++) 
        {
            for (int k = 0; k <= 9; k++) 
            {
                if (i != j && i != k && j != k)
                {
                    if ((i == a || i == b || i == c) && (j == a || j == b || j == c) && (k == a || k == b || k == c))
                    {
                        int number = i * 100 + j * 10 + k;
                        printf("%d; ", number); // не работает с повторяющимися числами 00 или 11 и т.д.
                    }
                }
                else if ((a == b) || (b == c) || (a == c)) //на посторяющиеся числа
                {
                    int number;
                    if (((a == 0 && b == 0) || (b == 0 && c == 0) || (c == 0 && a == 0)))
                    {
                        int ne_null = a + b + c; // находим не ноль
                        number = ne_null * 100;
                        printf("%d; ", number);
                        goto stop;
                    }
                    else if (a == b == c)
                    {
                        number = a * 100 + b * 10 + c;
                        printf("%d; ", number);
                        goto stop;
                    }
                    
                    for (int m = 0; m < 3; m++)
                    {
                        number = a * 100 + b * 10 + c; 
                        printf("%d; ", number);
                        int dop_val = a;
                        a = b;              // делаем перестановку чисел
                        b = c;
                        c = dop_val;
                    }
                    goto stop;
                }
                
            }
        }
        
    }
    stop: printf("\n\nsee you next time!");
    return 0;
}
