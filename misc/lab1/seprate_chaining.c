#include <stdio.h>
#include <stdlib.h>

#define MAX 11

struct record {
	int num;
	struct record *next;
};

void insert(struct record *table[], int key);
int search(struct record *table[], int key);
void delete(struct record *table[], int key);
void display(struct record *table[]);
int hash(int key);

int main()
{
	int ch, key, i;
	struct record *table[MAX];
	
	for (i = 0; i < MAX; i++) {
		table[i] = NULL;
	}
		while (1) {
		printf(" 1. Insert\n 2. Search\n 3. Delete\n 4. Display\n 5. Exit\n");
		printf("Enter your Choice : ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				printf("Enter the record: ");
				scanf("%d", &key);
				insert(table, key);
				break;
			case 2: 
				printf("Enter the key to be searched: " );
				scanf("%d", &key);
				i = search(table, key);
				if (i == -1)
					printf("Key not found\n");
				else
					printf("Key found at location: %d\n", i);
				break;
			case 3:
				printf("Enter the record to be deleted: ");
				scanf("%d", &key);
				delete(table, key);
				break;
			case 4:
				display(table);
			 	break;
			case 5:
				exit(1);
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}
		
	}
	
	return 0;
}

void insert(struct record *table[], int key)
{
	int h;
	struct record *new = NULL;
	h = hash(key);
	
	if (search(table, key) != -1) {
		printf("Duplicate key\n");
		return ;
	}
	
	new = malloc(sizeof(struct record));
	new->num = key;
	new->next = table[h];
	table[h] = new;
}

int search(struct record*table[], int key)
{
	int h;
	h = hash(key);
	
	struct record *ptr;
	ptr = table[h];
	
	while (ptr != NULL) {
		if (ptr->num == key)
			return h;
		ptr = ptr->next;
	}
	return -1;
}

void delete (struct record *table[], int key)
{
	struct record *ptr, *temp;
	int h;
	h = search(table, key);
	
	if (h == -1) {
		printf("Key to be deleted not found\n");
		return;
	}
	
	if (table[h]->num == key) {
		temp = table[h];
		table[h] = table[h]->next;
		free(temp);
		return;
	}
	
	else {
		ptr = table[h];
		while (ptr->next != NULL) {
			if (ptr->num == key) {
				temp = ptr;
				ptr = ptr->next;
				free(temp);
				return;
			}
			ptr = ptr->next;
		}
	}
	//printf("Key not found\n");
	
}

void display(struct record *table[])
{
	int i;
	struct record *ptr;
	
	for (i = 0; i < MAX; i++) {
		printf("\n [%d] : ", i);
		ptr = table[i];
		while (ptr != NULL) {
			printf("%d\t", ptr->num);
			ptr = ptr->next;
		}	
	}
	printf("\n");
}

int hash(int key) {
	return (key%MAX);
}
