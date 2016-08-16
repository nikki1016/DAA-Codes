#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int circ_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int a);
int dequeue();
int isempty();
int top();

int main()
{
	int num, n;
	char a[20];

	printf("The operations on the Circular Queue are\n 1. enqueue\n 2. dequeue\n 4. isempty \n 5. top\n ");

	for (scanf("%s", a); strcmp(a, "exit") != 0; scanf("%s", a)) {
		if (strcmp(a, "enqueue") == 0) {
			scanf("%d", &num);
			enqueue(num);
		}

		if (strcmp(a, "dequeue") == 0) {
			printf("Removed %d\n" ,dequeue() );
		}

		if (strcmp(a, "isempty") == 0) {
			n = isempty();
			if (n == 1)
				printf("Yes\n");
			else
				printf("No\n");
		}

		if (strcmp(a, "top") == 0) {
			printf("Element at the top : %d\n", top());
		}

		if (strcmp(a, "exit") == 0) {
			exit(1);
		}

	}

	return 0;
}

void enqueue(int num)
{
	if (front == -1)
		front = 0;
	if (rear == MAX-1)
		rear = 0;
	else 
		rear = rear+1;

	circ_arr[rear] = num;

}

int dequeue()
{
	int item;

	if (isempty()) {
		printf("Queue Overflow\n");
		exit(1);
	}

	item = circ_arr[front];

	if (front == rear) {
		front = -1;
		rear = -1;
	}

	if (front == MAX-1)
		front = 0;
	else
		front = front+1;

	return item;

}

int isempty()
{
	if (front == -1)
		return 1;
	else
		return 0;
}

int top()
{
	return circ_arr[front];
}


	



