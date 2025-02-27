/*//9. ����� ��� ����� � �������� ���������, ������� ������� �� ����� �� ����� ����.
#include <stdio.h>

void delit_num(int start, int end, int otvet[])
{
	int minus = 0, j = 0;
	for (int i = start; i < end; i++)
	{
		// ��������� ����� �� �������
		int x = i;

		while (x > 0)
		{
			// ��������� ������ ����� ����� � �����
			int num = x % 10;
			x /= 10;

			// ���������, ��� ����� �� ���� ����� 0
			if (num != 0)
			{
				// ���� ����� �� �������� ������, �� ������� �� �����
				if (i % num != 0)
				{
					minus = 1;
					break;
				}
			}
			// � ��� �� ���� ����� ����� 0, �� ��� �� ������� �� �����
			if (num == 0)
			{
				minus = 1;
				break;
			}
		}
		//���� �� �� ������� �� ��������, �� ��������� � ����� ����� �����
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

	// ��������� ������������ ��������
	delit_num(10, 1000, otvet);
	printf("Otvet: ");
	for (int i = 0; i < 1000 && otvet[i] > 0; i++)
	{
		printf("%d  ", otvet[i]);
	}
}*/

/*int F12(char[])
{
	for (int i = 0; c[i] != 0; i++)
	{
		if (c[i] == '') continue;
		for (int j = i + 1; c[j] == c[i]; j++);
		for (; c[j] != 0; j++)
		{
			for (int k = 0; i + k < j && c[i + k] == c[j + k]; k++);
			if (k >= 4) return i;
		}
	}
	return -1;
}

int F12(char c[])
{
	for (int i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '') continue;
		for (int j = i + 1; c[j] == c[i]; j++);
		for (; c[j] != 0; j++)
		{
			for (int k = 0; i + k < j && c[i + k] == c[j - k]; k++);
			if (k > 0 && (i + k >= j || c[i + k] != c[j - k])) k--;
			if (k >= 2) return i;
		}
	}
	return -1;
}*/

void prog(char c[]) {
	for (int i = 0; c[i] != 0; i++)
	{
		if (c[i] != ' ' && c[i] == c[i + 1])
		{
			putchar('*');
			while (c[i] == c[i + 1]) i++;
		}
		else putchar(c[i]);
	}
}

void proc(char c[]) {
	for (int i = 0; c[i] != 0; i++) {
		if (c[i] != ' ' && c[i] == c[i + 1]) {
			int j, k;
			for (j = i + 1, k = 1; c[j] == c[j + 1]; k++, j++);
			if (k >= 10) {
				putchar(k / 10 + '0');
			}
			putchar(k % 10 + '0');
			putchar(c[j]);
			for (; c[j] != 0; j++) {
				putchar(c[j]);
			}
		}
		else {
			putchar(c[i]);
		}
	}
}