#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int ctr = 0;

void insert();
int del();
int size();
int is_empty();
int top();

int main()
{
	int choice, num, n;

	while (1) {
		printf(" 1. Insert\n 2. Delete\n 3. Size\n 4. is_empty 5. top\n 6. Exit\n ");
		printf("Enter your choice\n");
		scanf("%d", &choice);

		switch (choice) 
		{
			case 1: 
				ctr++;
				scanf("%d", &num);
				insert(num);
				break;

			case 2:
				ctr--;
				printf("Removed %d\n", del());
				break;

			case 3:
				printf("Size : %d\n", size());
				break;

			case 4:
				n = is_empty();

				if (n == 1)
					printf("Yes\n");
				else
					printf("No\n");
				break;

			case 5:
				printf("Element at the top: %d\n", top());
				break;
			case 6:
				exit(1);

			default:
				printf("Wrong Choice\n");
		}

	}

}

	void insert(int num)
	{
		struct node *new = NULL;
		new = (struct node*)malloc(sizeof(struct node));

		new->val = num;
		new->next = NULL;

		if (front == NULL) 
			front = new;
		else
			rear->next = new;

		rear = new;
	}

	int del()
	{
		struct node *temp;
		int item;

		if (is_empty())
			printf("Queue Underflow\n");

		temp = front;
		item = temp->val;

		front = front->next;
		free(temp);

		return item;
	}

	int size()
	{
		return ctr;
	}	

	int is_empty()
	{
		if (front == NULL)
			return 1;
		else
			return 0;
	}

	int top()
	{
		return front->val;
	}







