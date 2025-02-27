#include <stdio.h>
#include <math.h>
#include <string.h>

//2. Написать функцию проверки, является ли заданное число простым. 
//С ее помощью написать функцию поиска простых чисел в диапазоне 1000-2000, 
//две любые части которого - также простые (например, 1997, 1-997,19-97,199-7).

int prostnum(int num) {
	for (int i = 2; i < num - 1; i++) {
		if (num % i == 0) {
			return 0;
			break;
		}
	}
	return 1;
}

int cnt_prost()
{
	int arr[1000];
	for (int i = 0; i < 1000; i++) {
		arr[i] = i + 1000;
	}
	int cnt = 0;
	for (int i = 0; i < 1000; i++) {
		if (prostnum(arr[i]) == 1)
		{
			//1997 - 1.997 - 1 - 997 - 9.97 - 9 - 97 - 9.7 - 9 - 7
			int num1 = arr[i] / 1000; // 1997 - 1,997 - 1
			if (prostnum(num1) == 1) {
				int num1r = arr[i] % 1000; // 1997 - 1.997 - 997
				int num2 = num1r / 100; // 997 - 9.97 - 9
				if (prostnum(num2) == 1) {
					int num2r = num1r % 100; // 997 - 9.97 - 97
					int num3 = num2r / 100; // 97 - 9.7 - 9
					if (prostnum(num3) == 1) {
						int num3r = num2r % 100; // 97 - 9.7 - 7
						if (prostnum(num3) == 1) cnt++;
					}
				}
			}
		}
	}
	return cnt++;
}

//4. Любая целочисленная денежная сумма n>7 может быть выдана без сдачи “трешками” и “пятерками”. 
// Программа находит эти числа для заданного n.

void money(int number)
{
	int m3 = 0; 
	int m5 = 0;
	while (number % 3 != 0 && number % 5 != 0) { 
		number -= 3;
		m3++;
	}
	if (number % 3 == 0)
		m3 = number / 3;
	if (number % 5 == 0)
		m5 = number / 5;
	printf("threes = % d\nfives = %d", m3, m5);
}

//7. Найти все двухзначные (трехзначные) числа, 
// которые совпадают с последними цифрами своих квадратов, например, 25^2=625, 76^2=5676.

void search_sovpad()
{
	printf("\nKvadrati: \n");
	for (int i = 10; i <= 99; i++)
	{
		int kvadrat = i * i;
		if (i == (kvadrat%100))
		{
			printf("%d %d\n", i, kvadrat);
		}
	}
	for (int i = 100; i <= 999; i++)
	{
		int kvadrat = i * i;
		if (i == (kvadrat % 1000))
		{
			printf("%d %d\n", i, kvadrat);
		}
	}
}

//9. Найти все числа в заданном диапазоне(допустим 10-1000), которые делятся на любую из своих цифр.

void delit_num()
{
	printf("delyatsia na vse svoi chifri: \n");
	int num2[2];
	int num3[3];
	for (int i = 10; i < 100; i++) {
		num2[0] = i / 10;
		num2[1] = i % 10;
		if (num2[1] != 0) {
			if (i % num2[0] == 0 && i % num2[1] == 0)
			{
				printf("%d ", i);
			}
		}
	}
	for (int i = 100; i < 1000; i++) { //187 - 1.87 - 1 - 187 - 18.7 - 7 - 18 - 1.8 - 8
		num3[0] = i / 100;
		num3[1] = i % 10;
		int f = i / 10;
		num3[2] = f % 10;
		
		if (num3[1] != 0 && num3[2] != 0) {
			if ((i % num3[0] == 0) && (i % num3[1] == 0) && (i % num3[2] == 0))
			{
				printf("%d ", i);
			}
		}
	}
}

//10. Найти числа в диапазоне 100-10000, 
// для которых куб суммы цифр равен значению самого числа (например, 512 - 5+1+2=8).

int sum_num(int num)
{
	int len = 0;
	int n = num;
	while (n)
	{
		n /= 10;
		len++;
	}

	int sum = 0;
	for (int i = 0; i < len; i++)	// 9845 - 984.5 - 5 - 98.4 - 4 - 9.8 - 8 - 9 
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

void kub_num()
{
	for (int i = 100; i < 10000; i++)		//512 - 5+1+2=kub512 - printf
	{
		int summ = sum_num(i);		//512 - 8
		if (i == pow(summ, 3))	//8 == 512
		{
			printf("%d %d\n", i, sum_num(i));
		}
	}
}

//13. Посчитать количество слов в строке.

void slova_str()
{
	char str[1000];
	printf("Write stroty syka: ");
	gets(str);

	int i = 0;
	int words = 1;
	while (str[i] != '\0') {
		if (str[i] == ' ' || str[i] == '\n') 
		{
			words++;
		}
		i++;
	}
	printf("kov-vo slov v stroke: %d", words);
}

//14. Найти в строке слово минимальной длины и возвратить индекс его начала.

void min_slovo()
{
	char arr[1000];
	printf("Write stroka blyat: ");
	gets(arr);

	int num1 = 0, min_num = 0;
	int i = 0, index = 0;
	while (arr[i] != 0) {
		if (arr[i] == ' ') {
			if (num1 < min_num || min_num == 0) 
			{
				min_num = num1;
				index = i;
			}
			num1 = -1;
		}
		num1++;
		i++;
	}
	printf("min. number -> %d\n", min_num); //idi nahui tupoi kodik
	printf("min. index number -> %d", index);
}

//17. "Перевернуть" в строке все слова. (Например: "Жили были дед и баба" - "илиЖ илиб дед и абаб"). 

void reverse_word()
{
	char str[1000];
	printf("Write words: ");
	gets(str);
	int length = strlen(str);
	int start = 0, end, i;

	for (i = 0; i <= length; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			end = i - 1;
			while (start < end)
			{
				char temp = str[start];
				str[start] = str[end];
				str[end] = temp;
				start++;
				end--;
			}
			start = i + 1;
		}
	}
	printf("reverse words: %s\n", str);
}

//23. В строке, содержащей абзац текста, найти концы предложений, 
// обозначенный символом "точка". В следующих за ними словах первую строчную букву 
// заменить на прописную. Между словами количество пробелов может быть любым.

void 

//Основная функция для вывода
int main()
{
	//2
	/*printf("kol-vo prost numbers (1000-2000): %d", cnt_prost());
	printf("\n\n"); 

	//4
	int number;
	printf("Your number: ");
	scanf_s("%d", &number);
	printf("\nResult: \n");
	money(number);
	printf("\n");

	//7
	search_sovpad();
	printf("\n");

	//9
	delit_num();
	printf("\n");

	//10
	kub_num();
	printf("\n");

	//13
	slova_str();
	printf("\n");

	//14
	min_slovo();
	printf("\n");

	//17
	reverse_word();
	printf("\n");*/

	//23

	return 0;
}