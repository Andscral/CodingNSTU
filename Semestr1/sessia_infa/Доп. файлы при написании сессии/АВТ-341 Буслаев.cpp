//9. ����� ��� ����� � �������� ���������, ������� ������� �� ����� �� ����� ����.
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
}