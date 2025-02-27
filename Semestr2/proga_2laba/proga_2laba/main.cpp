#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct car {
	char regNum[100];
	char marka[100];
	int km;
};

int size = 0;

void InputKeyboard(struct car *cars)
{
	if (size < 100){
	printf("\nRegistration number: "); scanf("%s", cars[size].regNum);
	printf("\nCar mark: "); scanf("%s", cars[size].marka);
	printf("\nProbeg: "); scanf("%d", &cars[size].km);
	size++;
	}
	else
	{
		printf("Table is full.\n");
	}

}

void saveTable(struct car* cars)
{
	FILE* file = fopen("cars.txt", "w"); //создаем файл и открывает cars.txt (w - write)

	for (int i = 0; i < size; i++) 
	{
		fprintf(file, "%s %s %d\n", cars[i].regNum, cars[i].marka, cars[i].km);
	}

	fclose(file);
	printf("Table saved to file.\n");
}

void LoadTable(struct car* cars)
{
	FILE* file = fopen("cars.txt", "r");

	while (fscanf(file, "%s %s %d\n", cars[size].regNum, cars[size].marka, &cars[size].km) != EOF)
	{
		size++;
	}

	fclose(file);
	printf("Table load from file.\n");
}

void ShowTable(struct car* cars)
{
	printf("\nCars: \n");
	printf("Reg Num     Marka      KM\n");
	for (int i = 0; i < size; i++) 
	{
		printf("%s      %s      %d\n", cars[i].regNum, cars[i].marka, cars[i].km);
	}
}

void SortKM(struct car* cars)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cars[j].km > cars[j + 1].km) {
				struct car temp = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = temp;
			}
		}
	}
	
}

void Search(struct car* cars, char* var)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(cars[i].regNum, var) == 0){
			printf("Car found at index %d\n", i);
			return;
		}
	}
	printf("Car not found\n");
}

void Delete(struct car* cars, int index)
{
	if (index < size)
	{
		for (int i = index; i < size; i++)
		{
			cars[index] = cars[index + 1];
		}
		size--;
		printf("Element deleted.\n");
	}
	else {
		printf("Invalid index\n");
	}
}

void EditTable(struct car* cars, int index)
{
	if (index < size)
	{
		printf("\nNew reg.number: "); scanf("%s", cars[index].regNum);
		printf("New marka: "); scanf("%s", cars[index].marka);
		printf("New KM: "); scanf("%d", &cars[index].km);

		printf("Cars edited.\n");
	}
	else {
		printf("Invalid index\n");
	}
}

int main()
{
	struct car cars[100];
	int choice;
	int index;
	do 
	{
		printf("\nMenu:\n");
		printf("1. Data Entry\n");
		printf("2. Save table to file\n");
		printf("3. Load table from file\n");
		printf("4. Show table\n");
		printf("5. Sort KM\n");
		printf("6. Search in table\n");
		printf("7. Delete element\n");
		printf("8. Edit element\n");
		printf("\n0. Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			InputKeyboard(cars);
			break;
		case 2:
			saveTable(cars);
			break;
		case 3:
			LoadTable(cars);
			break;
		case 4:
			ShowTable(cars);
			break;
		case 5: 
			SortKM(cars);
			break;
		case 6:
			char var;
			printf("Vvedite reg.number auto: ");
			scanf("%s", &var);
			Search(cars, &var);
			break;
		case 7:
			printf("Kakoy index udalit?: ");
			scanf("%d", &index);
			Delete(cars, index);
			break;
		case 8:
			printf("Kakoy index redaktirovat?: ");
			scanf("%d", &index);
			EditTable(cars, index);
			break;
		case 0:
			printf("Exiting program.\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 0);
}