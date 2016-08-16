#include <stdio.h>
#include <stdlib.h>

#define MAX 17

enum type_of_record {EMPTY , DELETED , OCCUPIED};

struct record {
	int num;
	enum type_of_record status;
};

void insert(struct record table[], int key);
int search(struct record table[], int key);
void delete(struct record table[], int key);
void display(struct record table[]);
int hash(int key);

int main() 
{
	int i, ch, key;
	struct record table[MAX];
	for (i = 0; i < MAX; i++) {
		table[i].status = EMPTY;
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

void insert(struct record table[], int key)
{
	int h, loc, i;
	h = hash(key);
	loc = h;
	
	if (search(table, key) != -1) {
		printf("Duplicate Key\n");
		return;
	}
	
	for (i = 0; i != MAX-1; i++) {
		if (table[loc].status == EMPTY || table[loc].status == DELETED) {
			table[loc].num = key;
			table[loc].status = OCCUPIED;
			printf("Record inserted\n");
			return;
		}
		else {
			loc = hash(h+i);
		}
	}
	printf("Record can't be inserted: Table Overflow\n"); 
}

int search(struct record table[], int key)
{
	int h, loc, i;
	h = hash(key);
	loc = h;
	
	for (i = 0; i != MAX-1; i++) {
		if (table[loc].num == key) {
			return loc;
		}
		else if (table[loc].status == DELETED || table[loc].status == EMPTY)
			return -1;	
		loc = hash(h+i);
	}
	return -1; 
}

void delete (struct record table[], int key)
{
	int loc = search(table, key);
	
	if (loc == -1) {
		printf("Key to be deleted not found\n");
	}
	else {
		table[loc].status = DELETED;
	}
}

void display(struct record table[])
{
	int i;
	
	for (i = 0; i < MAX; i++) {
		printf(" [%d] : ", i);
		if (table[i].status == OCCUPIED) {
			printf("OCCUPIED: %d\n", table[i].num);
		}
		else if (table[i].status == DELETED) {
			printf("DELETED\n");
		}
		else if (table[i].status == EMPTY) {
			printf("EMPTY\n");
		}
	}
}

int hash(int key) {
	return (key%MAX);
}
