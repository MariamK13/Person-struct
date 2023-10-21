#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   int day;
   int month;
   int year;
} Date;

typedef struct{

	char name[20];
	char surname[20];
	int age;
	Date* date;

} Person;

void init(Person* arr, int size)
{
	for (int i = 0; i < size; ++i){
		arr[i].date = (Date*)malloc(sizeof(Date));
		puts("enter name: ");
		fgets(arr[i].name, 20, stdin);
		arr[i].name[strcspn(arr[i].name, "\n")] = '\0'; 
		puts("enter surname: ");
		fgets(arr[i].surname, 20, stdin);
		arr[i].surname[strcspn(arr[i].surname, "\n")] = '\0'; 
		puts("enter the birth date: ");
		scanf("%d", arr[i].date->day);
		scanf("%d", arr[i].date->month);
		scanf("%d", arr[i].date->year);
		int c = 0;
		while ((c = getchar()) != '\n' && c != EOF);
	}
}

int main()
{
	int size = 0;
	printf("How many people are there? ");
	scanf("%d", &size);
	int c = 0; 
	while ((c = getchar()) != '\n' && c !=  EOF);
	Person* arr = (Person*)calloc(sizeof(Person), size);
	printf("here are all the people\n");
	for (int i = 0; i < size; ++i) {
		printf("%s %s %d %d %d\n", arr[i].name, arr[i].surname, arr[i].date->day, arr[i].date->month, arr[i].date->year);

	}
	for (int i = 0; i < size; ++i) {
		free(arr[i].date);
	}
		
	free(arr);
}
