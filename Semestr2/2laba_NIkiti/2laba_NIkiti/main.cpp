#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
	char familia[20];
	char grupa[20];
	char facultet[20];
	int zachet_book;
};

int size = 0;

void InputKeyboard(struct student* students)
{
	if (size < 20) {
		printf("\nFamilia: "); scanf("%s", students[size].familia);
		printf("\nFacultet: "); scanf("%s", students[size].facultet);
		printf("\Grupa: "); scanf("%s", students[size].grupa);
		printf("\nNum zachet: "); scanf("%d", &students[size].zachet_book);
		size++;
	}
	else
	{
		printf("Table is full.\n");
	}

}

void saveTable(struct student* students)
{
	FILE* file = fopen("students.txt", "w"); //создаем файл и открывает students.txt (w - write)

	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s %s %s %d\n", students[i].familia, students[i].facultet, students[i].grupa, students[i].zachet_book);
	}

	fclose(file);
	printf("Table saved to file.\n");
}

void LoadTable(struct student* students)
{
	FILE* file = fopen("students.txt", "r");

	while (fscanf(file, "%s %s %s %d\n", students[size].familia, students[size].facultet, students[size].grupa, &students[size].zachet_book) != EOF)
	{
		size++;
	}

	fclose(file);
	printf("Table load from file.\n");
}

void ShowTable(struct student* students)
{
	printf("\nStudents: \n");
	printf("Familia     Facultet	Grupa	NumBook\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s	  %s	  %s	 %d\n", students[i].familia, students[i].facultet, students[i].grupa, students[i].zachet_book);
	}
}

void Sort(struct student* students)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (students[j].zachet_book > students[j + 1].zachet_book) {
				struct student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
	printf("table sort correct!");

}

void Search(struct student* students, char* var)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(students[i].familia, var) == 0) {
			printf("student found at index %d\n", i);
			return;
		}
	}
	printf("student not found\n");
}

void Delete(struct student* students, int index)
{
	if (index < size)
	{
		for (int i = index; i < size; i++)
		{
			students[index] = students[index + 1];
		}
		size--;
		printf("Element deleted.\n");
	}
	else {
		printf("Invalid index\n");
	}
}

void EditTable(struct student* students, int index)
{
	if (index < size)
	{
		printf("\nNew familia: "); scanf("%s", students[index].familia);
		printf("New facultet: "); scanf("%s", students[index].facultet);
		printf("New grupa: "); scanf("%s", students[index].grupa);
		printf("New Number Zachet book: "); scanf("%d", &students[index].zachet_book);

		printf("student edited.\n");
	}
	else {
		printf("Invalid index\n");
	}
}

int main()
{
	struct student students[100];
	int choice;
	int index;
	do
	{
		printf("\nMenu:\n");
		printf("1. Data Entry\n");
		printf("2. Save table to file\n");
		printf("3. Load table from file\n");
		printf("4. Show table\n");
		printf("5. Sort NumZach\n");
		printf("6. Search in table\n");
		printf("7. Delete element\n");
		printf("8. Edit element\n");
		printf("\n0. Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			InputKeyboard(students);
			break;
		case 2:
			saveTable(students);
			break;
		case 3:
			LoadTable(students);
			break;
		case 4:
			ShowTable(students);
			break;
		case 5:
			Sort(students);
			break;
		case 6:
			char var;
			printf("Vvedite familiu student: ");
			scanf("%s", &var);
			Search(students, &var);
			break;
		case 7:
			printf("Kakoy index udalit?: ");
			scanf("%d", &index);
			Delete(students, index);
			break;
		case 8:
			printf("Kakoy index redaktirovat?: ");
			scanf("%d", &index);
			EditTable(students, index);
			break;
		case 0:
			printf("Exiting program.\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 0);
}