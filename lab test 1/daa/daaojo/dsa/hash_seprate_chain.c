#include <stdio.h>
#include <stdlib.h>

#define MAX 11

struct record
{
	int info;
	struct record *next;
};

void insert(int num, struct record *table[]);
int search(int key, struct record *table[]);
void del(int key, struct record *table[]);
void display(struct record *table[]);

int main()
{
	int i, h, choice, num, key, j;
	struct record *table[MAX];

	for (i = 0; i < MAX; i++) 
		table[i] = NULL;

	
	while (1) {
		printf("\n 1. Insert a record\n 2. Search a record\n 3. Delete a record\n 4. Display records\n 5. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter the record ");
				scanf("%d", &num);
				insert(num, table);
				break;
			case 2:
				printf("Entter the key to be searched: ");
				scanf("%d", &key);
				j = search(key, table);
				if (j == -1)
					printf("Record Not found\n");
				else
					printf("Record found at chain: %d\n", j);
				break;
			case 3:
				printf("Enter the key to be deleted: ");
				scanf("%d", &key);
				del(key, table);
				break;
			case 4:
				display(table);
				break;
			case 5:
				exit(1);
			deafult:
				printf("Wrong Chocice\n");
				break;
		}
	}

	return 0;
}

void insert(int num, struct record *table[])
{
	int i, h;

	h = hash(num);
	
	struct record *new;
	new = (struct record *)malloc(sizeof(struct record));
	new->info = num;
	new->next = table[h];
	table[h] = new;
}

int search(int key, struct record *table[])
{
	
	struct record *ptr;
	int h;

	h = hash(key);

	ptr = table[h];

	while (ptr != NULL) {
		if (ptr->info == key)
			return h;
		ptr = ptr->next;
	}

	return -1;
}

void del(int key, struct record *table[])
{
	int h;
	struct record *temp;
	struct record *ptr;

	h = hash(key);

	if (table[h] == NULL) {
		printf("Record not found\n");
		return ;
	}

	if (table[h]->info == key) {
		temp = table[h];
		table[h] = table[h]->next;
		free(temp);
		return;
	}

	ptr = table[h];

	while (ptr->next != NULL) {
		if (ptr->next->info == key) {
			temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
			return;
		}
		
		ptr = ptr->next;
	}
	printf("Key not found\n");
}

int hash(int num)
{
	return (num%MAX);
}

void display(struct record *table[])
{
	int i;
	struct record *ptr;

	for (i = 0; i < MAX; i++) {

		printf(" [%d] : ", i);
		if (table[i] != NULL) {
			ptr = table[i];
			while (ptr != NULL) {
				printf("%d ", ptr->info);
				ptr = ptr->next;
			}
		}
		printf("\n");
	}
}









