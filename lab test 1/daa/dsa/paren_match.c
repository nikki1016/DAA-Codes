#include <stdio.h>
#include <string.h>

#define MAX 20

int top = -1;
char stack_arr[MAX];

int ctr = 0;

void push(char a);
char pop();

int main()
{
	char a[MAX];

	printf("Enter any parenthesis conataining string: \n");
	scanf("%s", a);

	int i, k;
	i = k = 0;

	while (a[i] != '\0') {
		push(a[i]);
		i++;
	}

	char q;
	while (i--) {
		q = pop();
		if (q == '(') 
		k++;
	else if (q == ')')
		k--;
	}

	if (k == 0) 
		printf("Parenthesis matched\n");
	else 
		printf("Parenthesis not matched\n");

	return 0;
}

void push(char c) 
{
	stack_arr[++top] = c;
}

char pop() 
{
	char item;
	item = stack_arr[top];
	top--;

	return item;
}








