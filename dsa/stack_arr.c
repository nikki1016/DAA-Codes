#include <stdio.h>
#include <string.h>

#define MAX 20

int stack_arr[MAX];
int top = -1;

void push(int a);
int pop();
void is_empty();
int size();
int top1();

int main()
{
	char a[20];
	int num;

	for ( scanf("%s", a); strcmp(a, "exit") != 0; scanf("%s", a)) {
		if (strcmp(a, "push") == 0) {
			scanf("%d", &num);
			push(num);
		}

		if (strcmp(a, "pop") == 0) {
			printf("removed %d\n", pop());
		}

		if (strcmp(a, "size") == 0) {
			printf("size of stack : %d\n", size());
		}

		if (strcmp(a, "top") == 0) {
			printf("top element : %d\n", top1());
		}

		if (strcmp(a, "isEmpty") == 0) {
			is_empty();
		}
	}

}

void push(int a) 
{
	top++;
	stack_arr[top] = a;
}

int pop()
{
	int item;
	item = stack_arr[top];
	top--;

	return item;
}

int size()
{
	return top+1;
}

void is_empty()
{
	if (top == -1) 
		printf("yes\n");
	else
		printf("no\n");
}

int top1()
{
	return stack_arr[top];
}
			



