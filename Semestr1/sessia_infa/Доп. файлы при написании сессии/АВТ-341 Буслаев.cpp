//9. Найти все числа в заданном диапазоне, которые делятся на любую из своих цифр.
#include <stdio.h>

void delit_num(int start, int end, int otvet[])
{
	int minus = 0, j = 0;
	for (int i = start; i < end; i++)
	{
		// проверяем цифры на условие
		int x = i;

		while (x > 0)
		{
			// проверяем каждую цифру числа с конца
			int num = x % 10;
			x /= 10;

			// проверяем, что цифра не была равна 0
			if (num != 0)
			{
				// если число не делиться нацело, то выходим из цикла
				if (i % num != 0)
				{
					minus = 1;
					break;
				}
			}
			// а так же если цифра равна 0, всё так же выходим из цикла
			if (num == 0)
			{
				minus = 1;
				break;
			}
		}
		//если же по условию всё проходит, то добавляем в ответ такое число
		if (minus == 0)
		{
			otvet[j] = i;
			j++;
		}
		minus = 0;
	}
}

int main()
{
	int otvet[1000];

	// указыкаем интересующий диапазон
	delit_num(10, 1000, otvet);
	printf("Otvet: ");
	for (int i = 0; i < 1000 && otvet[i] > 0; i++)
	{
		printf("%d  ", otvet[i]);
	}
}