#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
};

struct node *top = NULL;

void push(int a);
int pop();
int isEmpty();
int top1();
void display();

int main()
{
	char a[20];
	int num, n;

	for ( scanf("%s", a); strcmp(a, "exit") != 0; scanf("%s", a)) {
			if (strcmp(a, "push") == 0) {
				scanf("%d", &num);
				push(num);
			}

			if (strcmp(a, "pop") == 0) {
				printf("removed %d\n", pop());
			}

			if (strcmp(a, "top") == 0) {
				printf("top element : %d\n", top1());
			}

			if (strcmp(a, "isEmpty") == 0) {
				n = isEmpty();
				if (n == 1)
					printf("Yes\n");
				else
					printf("No\n");
			}

			if (strcmp(a, "display") == 0)
				display();
	}

	return 0;
}

void push(int num)
{
	struct node *new = NULL;
	new = (struct node*)malloc(sizeof(struct node));

	new->val = num;
	new->next = top;

	top = new;
}

int pop()
{
	int item;

	struct node *temp = NULL;
	temp = top;

	item = temp->val;
	top = top->next;

	free(temp);

	return item;
}

int isEmpty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

int top1()
{
	return top->val;
}

void display()
{
	struct node *ptr;
	ptr = top;

	if (isEmpty())
		printf("Stack is Empty\n");

	while (ptr != NULL) {
		printf("%d\n", ptr->val);
		ptr = ptr->next;
	}

}





