#include <stdio.h>
// ya -> 28, 45, 16, 37, 58; 
// kirill -> 22, 13, 33, 40, 57;


//45(����������!!!!)
/*int sort_max(int A[])
{
	int j, k, i;
	int A[] = { 2, 5, 7, 0, 5, 3, 9, 10 };		// ������ �������� ������
	int n = 8;
	int max = 0;
	int B[8] = {0};								// ������ 2-� ������ ��� ������ ��������������� ����� �� ������� �
	printf("A: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);					// �� ������� ������� ������ �, ����� ���� ���� ����� ���������
	}
	for (j = 0; j < n; j++)
	{
		if (A[j] > max)
		{								// ���� ����. ����. �� �������
			max = A[j];
		}
	}

	for (j = 0; j < n; j++)
	{
		for (k = 0, i = 1; i < n; i++)
		{
			if (A[i] < A[k])
			{								// ��� ����
				k = i;						//(4,2,8) (2, 0, 0)|| (4, 9, 8) (2, 4, 0) || (9, 9, 8) (2, 4, 8)
			}
			B[j] = A[k];
		}
		A[k] = max + 1;
	}

	printf("\n\nB: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}*/

//16 (����������!!!!) * ����� ������������, ������������ � ������
/*int number_massive(int a)
{
	int i, a;
	//printf("Number: ");			// ����� ������ �����
	//scanf_s("%d", &a);
	int n = a;					// ��������� ��� ����� � ��������� ����������
	int len = 0;
	do
	{
		len++;				// ������� ������� ���������� � ��� �����
		a = a / 10;
	} while (a);

	int A[100] = { 0 };			// ������ ������ ��� ������ �����
	for (i = 0; n != 0; i++)
	{
		A[i] = n % 10;				// ���������� ����� � ������(�� ����� ������������ ��������)
		n = n / 10;
	}
	printf("Massive: ");
	for (i = len; i > 0; i--)		// ������������� �����, ����� ��� ���������� ���������
	{
		printf("%d ", A[i-1]); // ������� �������� ������� A � ���������� �������
	}
	return 0;
}*/

//13(����������!!!!) * ����� ����� ��������� ������������� �����
/*int sum_numbers(int a)
{
	int k, s;
	s = 0;

	while (a != 0)
	{
		k = a % 10;
		s = s + k;
		a = a / 10;
	}
	return s;
}*/

//37(����������!!!!) * ����. ������. ����� + ������ ������� ����.
/*int max_povt_id(int A[])
{
	int A[10] = {4, 2, 1, 1, 9, 1, 7, 5, 1, 9};				// �������� ����������� ������
	int n = 10;												// ����� �������
	int s = 0;												// ���������� ��� ����� � ��������
	int b = 0;

	for (int i = 0; i < n-1 ; i++)
	{
		int m = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] == A[j])								// �������� �� ������������� �������
			{
				m++;										// ���� ������� �����������, �� +1 � �������
			}
		}
		if (m > s)
		{
			s = m;							//���������� ��������� ���������� � ����������
			b = i;
		}
	}
	printf("Max povt: %d", s+1);				// ������� ����� ������ ���� �� �����
	printf("\nIndex max povt: %d", b);

	return 0;
}*/

//58(����������!!!!) * ������� �����. ����� / �� ��������� -> ����� ������� �����. �������
/*int otric(int A[])
{
	int i, s, k;
	int A[9] = {1, 2, -3, 4, 5, -1, -7, 0, -9};
	for (i=0,s=0,k=0; i<9; i++)
	{
		if (A[i]<0) k=1;
	}
	else
	 {
		if (k==1) s++;
		k=0;
	 }
	 printf("s: %d ", s);

	return 0;
}*/

//22(����������!!!!) * �����. �����
/*int prost_num(?) {
	int v = 1000; // �������� ��� ������ ������� �����
	int A[1000]; // ������ ��� �������� ������� �����
	int i, a, n, s;

	for (i = 0, a = 2; a < v; a++) {
		for (s = 0, n = 2; n < a; n++) {
			if (a % n == 0) {
				s = 1;
				break;
			}
		}
		if (s == 0) {
			A[i++] = a;
		}
	}
	A[i] = 0; //  ��������� ������� �������

	// ����� ������� �����
	for (int j = 0; A[j] != 0; j++) {
		printf("%d ", A[j]);
	}
	return 0;
}*/

//33(���!!!!) * ���� ��� ����� ����. ����������� � �������
/*int max_povt(int A[]) {
	system("chcp 1251");											// ���������� �����������
	int A[] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5 };			// ������ ������
	int n = 13;														// ������ �������

	int s = 0, b = 0;												// ������ ����������

	for (int i = 0; i < n - 1; i++) {
		if (A[i] == A[i + 1]) {										// ������� ������� � ��� ������������� �����
			int k;
			for (k = 2; i + k < n && A[i] == A[i + k]; k++);		// ��� ������� ����
			if (k > s) {
				s = k;					// ������ �������������							// ���������� ����������
				b = i;					// ������ �������
			}
		}
	}

	printf("���������� ������������������ ������������� ���������: ");				// ������ ����� �������
	for (int i = b; i < b + s; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}*/

//40(����������!!!!) * ����� ������������� ��������
/*int sum_up_znach(int A[]) {
	system("chcp 1251");
	int n = 5;
	int A[] = { 1, 2, 3, 4, -1 };		// ����� ������(n)

	int s = 0, i;

	for (i = 0; i < n && A[i] > 0; i++) {
		s = s + A[i];							// ����� ������������� ��������
	}

	printf("����� ������������� ��������: %d", s);

	return 0;
}*/

//57(����������) * ���������� ����� � ������� ������ ���� ������ ���������(����� ������� ��� � ���� ��������)
/*int i1_menihe_i2(int A[]) {
	system("chcp 1251");
	int A[] = { 1, 2, 3, 2, 4, 5, 1, 6, 7 };		// ������ ������

	int i, s = 0, k = 0;							// ������ ��������� � �������

	for (i = 1; i < 10; i++) {
		if (A[i - 1] < A[i]) {						// ���������, ����� ���������� ����� ���� ������ ���������
			k++;									// ���� ������, �� +1 � ��������
		}
		else {
			if (k > s) {							// ���������� ������������ ����� ������������������ � ���������� s
				s = k;
			}
			k = 0;									// �������� �������
		}
	}

	printf("�������� s: %d\n", s+1); //s+1					// ����� ����������

	return 0;
}*/

//28(�� ��������) ��������� ����� � �������
/*int kratnoe(int A[])
{

	int s = 0;
	int A[] = { 1, 4, -6, 8, 9, 1, -4, 6 };
	int n = 8;
	int v = A[0] + 1;

	do
	{
		v--;
		for (int i = 0; i < n ;i++)
		{
			if (A[i] % v != 0)
			{
				s = 1;
				break;
			}
			s = 0;
		}
	} while(s == 1);

	printf("Result: %d", s);

	return 0;
}*/

void sort_max(int A[], int lenght);
void max_povt_id(int A[], int lenght, int* s, int* b);
int sum_numbers(int a);
void mono_ryad(int A[], int length, int* s);
int max_del(int A[], int length);
int sum_poloj_num(int A[], int length);
int sum_poloj_otrez(int A[], int length);


void main()
{
	system("chcp 1251");
	int vibor_user;
	while(1)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("����, ����� ������� �� ������ ����������� :)??\n");
		printf("p.s. ��� �� �������������� ������� ��������� ������� <0> \n\n");
		printf("<1> - ���������� �� �����������(#45)\n<2> - C���� ���� ��������� ������������� �����(#13)	"
			"\n<3> - ����� ������������ ������������ � ������(#16)\n<4> - ���-�� ������������� ����� � ������ ������ ����� �����(#37) \
\n<5> - ���� ������������� ��������(#58)\n<6> - ������� �����(#22)\n<7> - ����� ������������� ����� �� ������� �������������� �����(#40) \
\n<8> - ���������� ������������������ ������������� ���������(#33)\n<9> - ������������ ���������� ������������ ��������� ������(#57) \
\n<10> - ���������� ����� �������� ��������� �������");

		printf("\n���� �����: ");
		scanf_s("%d", &vibor_user);

		if (vibor_user == 1)
		{
			int i, length, A[100];
			printf("\n<���������� �� �����������>");
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++) {
				scanf_s("%d", &A[i]);
			}
			sort_max(A, length);
			printf("\n��� ��, �����������! :) -> ");

			for (i = 0; i < length; i++) {
				printf("%d ", A[i]);
			}
			printf("\n");
		}

		else if (vibor_user == 2)
		{
			int number;
			printf("\n<C���� ���� ��������� ������������� �����>");
			printf("\n������ ����� �����, ������� ������ -> ");
			scanf_s("%d", &number);
			printf("\n�������: %d", sum_numbers(number));
			printf("\n");
		}

		//?
		else if (vibor_user == 3)
		{
			int i, number;
			printf("\n<����� ������������ ������������ � ������>");
			printf("\n����� ����� �����: ");
			scanf_s("%d", &number);
			int n = number;
			int len = 0;
			do
			{
				len++;							// ������� ������� ���������� � ��� �����
				number = number / 10;
			} while (number);
			int A[100] = { 0 };
			for (i = 0; n != 0; i++)
			{
				A[i] = n % 10;					// ���������� ����� � ������(�� ����� ������������ ��������)
				n = n / 10;
			}
			printf("\n��� ���� �����, �� ��� � �������: ");
			for (i = len; i > 0; i--)		// ������������� �����, ����� ��� ���������� ���������
			{
				printf("'%d' ", A[i - 1]); // ������� �������� ������� A � ���������� �������
			}
			printf("\n");
		}

		else if (vibor_user == 4)
		{
			int i, length, A[100], s, b;
			printf("\n<���-�� ������������� ����� � ������ ������ ����� �����>");
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++)
			{
				scanf_s("%d", &A[i]);
			}
			max_povt_id(A, length, &s, &b);
			printf("\n����������� ���-�� ������������� ������: %d", s + 1);
			printf("\n������ ����. ����. �����: %d", b);
			printf("\n");
		}

		else if (vibor_user == 5)									//������� ������� ������������� �������� � �������
		{
			int i, length, A[100], s;
			printf("\n<���� ������������� �������� ����� �������������� �������>");
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++)
			{
				scanf_s("%d", &A[i]);
			}
			printf("\n���, ���, ���, � ��� ��-���� ��� �������: %d", sum_poloj_otrez(A, length));
			printf("\n");
		}

		//?
		else if (vibor_user == 6)									//������� ������� ������������� �������� � �������
		{
			int i, length, A[10000], a, n, s;;
			printf("\n<������� �����>");
			printf("\n�������� �� ������ ����� �� �� ������ ������� ������: ");
			scanf_s("%d", &length);

			for (i = 0, a = 2; a <= length; a++)
			{
				for (s = 0, n = 2; n < a; n++) {
					if (a % n == 0) s = 1; break;
				}
				if (s == 0) A[i++] = a;
			}
			A[i] = 0;
			printf("\n��� �������: ");
			for (int j = 0; A[j] != 0; j++) {
				printf("%d ", A[j]);
			}
			printf("\n");
		} 

		else if (vibor_user == 7)
		{
			printf("\n<����� ������������� ����� �� ������� �������������� �����>");
			int length, i, s, A[100];
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++) {
				scanf_s("%d", &A[i]);
			}
			printf("\n����������, �������: %d", sum_poloj_num(A, length));
			printf("\n");
		}

		//?
		else if (vibor_user == 8)
		{
			printf("\n<���������� ������������������ ������������� ���������>");
			int length, i, s, b, A[100];
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++) {
				scanf_s("%d", &A[i]);
			}
			s = 0, b = 0;																	// ������ ����������
			for (int i = 0; i < length - 1; i++) {
				if (A[i] == A[i + 1]) {													// ������� ������� � ����� � ��� ������������� �����
					int k;
					for (k = 2; i + k < length && A[i] == A[i + k]; k++);
					if (k > s) s = k; b = i;
				}
			}
			printf("\n���������� ������������������ ������������� ���������: ");					// ������ ����� �������
			for (int i = b; i < b + s; i++) {
				printf("%d ", A[i]);
			}
			printf("\n");
		}	 

		else if (vibor_user == 9)
		{
			int i, s, length, A[100];
			printf("\n<������������ ���������� ������������ ��������� ������>");
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++) {
				scanf_s("%d", &A[i]);
			}
			mono_ryad(A, length, &s);
			printf("\n��� �����: %d", s + 1); //s+1					
			printf("\n");
		}

		else if (vibor_user == 10)
		{
			printf("\n<���������� ����� �������� ��������� �������>");
			int i, s, length, A[100], v;
			printf("\n����� �������: ");
			scanf_s("%d", &length);
			printf("������� �������: ");

			for (i = 0; i < length; i++) {
				scanf_s("%d", &A[i]);
			}
			int result = max_del(A, length);
			printf("\n��� ��, �� ��� ��� ��� ����� �����, ���������� ��������: %d", result);
			printf("\n");
		}

		else if (vibor_user == 0)
		{
			printf("\n�������, ��� ��������������� ����������. ������� �� ������� ��� ���������� ���������� :)");
			printf("\n__________________________\n@andscral & @kirill222888|\n");
			return 0;
		}

		else
		{
			printf("\n�� ����� ������������ ������!!\n");
		}
	}

}

void sort_max(int A[], int length)
{
	int j, k, i;
	int max = 0;
	int B[100] = { 0 };
	for (j = 0; j < length; j++)
	{
		if (A[j] > max)
		{								// ���� ����. ����. �� �������
			max = A[j];
		}
	}

	for (j = 0; j < length; j++)
	{
		for (k = 0, i = 1; i < length; i++)
		{
			if (A[i] < A[k])
			{								// ��� ���� 
				k = i;						//(4,2,8) (2, 0, 0)|| (4, 9, 8) (2, 4, 0) || (9, 9, 8) (2, 4, 8)
			}
			B[j] = A[k];
		}
		A[k] = max + 1;
	}
	for (j = 0; j < length; j++)
	{
		A[j] = B[j];
	}
}
int sum_numbers(int a)
{
	int k, s;
	s = 0;

	while (a != 0)
	{
		k = a % 10;
		s = s + k;
		a = a / 10;
	}
	return s;
}
void max_povt_id(int A[], int length, int* s, int* b)
{
	*s = 0;
	*b = 0;
	for (int i = 0; i < length - 1; i++)
	{
		int m = 0;
		for (int j = i + 1; j < length; j++)
		{
			if (A[i] == A[j])								// �������� �� ������������� �������
			{
				m++;										// ���� ������� �����������, �� +1 � �������
			}
		}
		if (m > *s)
		{
			*s = m;							//���������� ��������� ���������� � ����������
			*b = i;
		}
	}
}
void mono_ryad(int A[], int length, int* s)
{
	*s = 0;
	for (int i = 1, k = 0; i < length; i++) {
		if (A[i] < A[i+1]) {						// ���������, ����� ���������� ����� ���� ������ ���������
			k++;									// ���� ������, �� +1 � ��������
		}
		else {
			if (k > *s) {							// ���������� ������������ ����� ������������������ � ���������� s
				*s = k;
			}
			k = 0;									// �������� �������
		}
	}
}
int max_del(int A[], int length)
{
	int v, i, s;
	v = A[0] + 1;
	do {
		v--;
		for (i = 0, s = 0;i < length;i++) {
			if (A[i] % v != 0) { s = 1; break; }
		}
	} while (s == 1);
	return v;
}
int sum_poloj_num(int A[], int length)
{
	int i, s;
	s = 0;
	for (i = 0; i < length && A[i] > 0; i++) {
		s = s + A[i];							// ����� �������� 
	}
	return s;
}
int sum_poloj_otrez(int A[], int length)
{
	int s = 0;
	for (int i = 0, k = 0; i < length; i++)
	{
		if (A[i] < 0) k = 1;
		else
		{
			if (k == 1) s++; k = 0;
		}
	}
	return s;
}
