#include <stdio.h>
#include <string.h>

#define MAX 20

int top = -1;
char str[MAX];

void push(char a);
char pop();

int main()
{
	int i, l, ctr = 0;

	printf("Enter the string: ");
	scanf("%s", str);
	l = strlen(str);

	for (i = 0; i < l; i++) {
		push(str[i]);
	}

	for (i = 0; i < l; i++) {
		if (str[i] == pop()) 
			ctr++;
	}

	if (ctr == l) {
		printf("The string %s is palindrome \n", str);
	}
	else 
		printf("The string %s is not a palindrome \n", str);

	return 0;

}

void push(char item)
{
	if (top == MAX-1) {
		printf("Stack Overflow\n");
	}

	str[++top] = item;

}

char pop()
{
	char item;
	item = str[top];
	top = top-1;

	return item;
}

