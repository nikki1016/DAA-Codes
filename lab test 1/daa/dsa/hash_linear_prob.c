#include <stdio.h>
#include <stdlib.h>

#define MAX 17

enum type_of_record {EMPTY, DELETED, OCCUPIED};

struct record
{
	int info;
	enum type_of_record status;
};

void insert(int num, struct record table[]);
int search(int key, struct record table[]);
void del(int key, struct record table[]);
void display(struct record table[]);

int main()
{
	int i, h, choice, num, key, j;
	struct record table[MAX];

	
	while (1) {
		printf("\n 1. Insert a record\n 2. Search a record\n 3. Delete a record\n 4. Display records\n 5. Exit\n\n");
		printf("Enter our choice: ");
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
					printf("Record found at index: %d\n", j);
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

void insert(int num, struct record table[])
{
	int i, h, loc;

	h = hash(num);
	loc = h;

	for (i = 1; i != MAX-1; i++) {
		if (table[i].status == EMPTY || table[i].status == DELETED) {
			table[loc].info = num;
			table[loc].status = OCCUPIED;
			printf("Record inserted\n");
			return;
		}
		loc = (h+i)%MAX;
	}

	printf("Record cant be inserted, Table Overflow\n");
}

int search(int key, struct record table[])
{
	int h, i, loc;

	h = hash(key);

	loc = h;

	for (i = 1; i != MAX-1; i++) {
		if (table[loc].status == EMPTY) {
			return -1;
		}
		if (table[loc].info == key){
			return loc;
		}
		loc = (h+i)%MAX;
	}

	return -1;
}

void del(int key, struct record table[])
{
	int loc;
	loc = search(key, table);

	if (loc == -1)
		printf("Key not found\n");

	else {
		table[loc].status = DELETED;
		printf("Record Deleted\n");
	}
}

int hash(int num)
{
	return (num%MAX);
}

void display(struct record table[])
{
	int i;

	for (i = 0; i < MAX; i++) {
		printf(" [%d] : ", i);
		if (table[i].status == OCCUPIED) {
			printf("Occupied  %d  \n", table[i].info);
		}
		else if(table[i].status == DELETED)
			printf("Deleted\n");
		else
			printf("Empty\n");
	}
}









