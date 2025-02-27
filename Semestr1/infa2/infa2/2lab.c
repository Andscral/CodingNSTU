#include <stdio.h>
#include <math.h>
double fact(int n)
{
	if (n > 1) return n * fact(n - 1);
	else return 1;
}

double sh(double x, int n)
{			
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int stepen = 2 * i - 1;
		double formula = pow(x, stepen) / fact(stepen);
		sum += formula;
	}
	return sum; 
}

double arctg(double x, int n)
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int stepen = 2 * i - 1;
		int stepen_minusa = i - 1;
		double formula = (pow(-1, stepen_minusa) * pow(x, stepen)) / (stepen);
		sum += formula;
	}
	return sum;
}

int main()
{
	system("chcp 1251");
	double x;
	int n, var, andscral;
	printf("\nПривет! Это программа для вычисления функций Arctg(x) и Sh(x). Выбери одно из двух :)\n");
	printf("1) Arctg(x) \n2) Sh(x) \nТвой выбор: ");
	scanf_s("%d", &var); 
	if (var == 1)
	{
		printf("\nВведи значение 'x', для функции Arctg(x) -> ");
		scanf_s("%lf", &x);
		printf("А теперь ряд из скольки выражений ты хочешь найти сумму -> ");
		scanf_s("%d", &n);
		printf("\nМой, ой, то есть твой ответ: = %lf\n", arctg(x, n));
	}
	
	else if (var == 2)
	{
		printf("\nВведи значение 'x', для функции Sh(x) -> ");
		scanf_s("%lf", &x);
		printf("А теперь ряд из скольки выражений ты хочешь найти сумму -> ");
		scanf_s("%d", &n);
		printf("\nТвой ответик: = %lf\n", sh(x, n));
	}

	else
		printf("\nТЫ ЧО?! МАХАТЬСЯ ХОЧЕШЬ?!\n");

	printf("\n__________\n@andscral\n");

	return 0;
}