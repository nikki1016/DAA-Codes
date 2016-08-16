#include <stdio.h>
#include <string.h>

#define MAX 20

int que_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int a);
int dequeue();
int size();
int isempty();
int top();

int main()
{
	int num, n;
	char a[20];

	printf("The operations on the Queue are enqueue, dequeue, size, top, isempty\n");

	for (scanf("%s", a); strcmp(a, "exit") != 0; scanf("%s", a)) {
		if (strcmp(a, "enqueue") == 0) {
			scanf("%d", &num);
			enqueue(num);
		}

		if (strcmp(a, "dequeue") == 0) {
			printf("Removed %d\n" ,dequeue() );
		}

		if (strcmp(a, "size") == 0) {
			printf("Size : %d\n", size());
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

	}

	return 0;
}

void enqueue(int a) 
{
	if (front == -1) 
		front = 0;

	que_arr[++rear] = a;
}

int dequeue()
{
	return que_arr[front++];
}

int size()
{
	return rear-front+1;
}

int top()
{
	return que_arr[front];
}

int isempty()
{
	if (front == -1 || front == rear+1)
		return 1;
	else 
		return 0;
}



