#include <stdio.h>
#include <string.h>

#define MAX 20

void push (int symbol);
int pop();
void infix_to_postfix();
int priority(char symbol);
int is_empty();

char infix[MAX];
char postfix[MAX];
int stack[MAX];
int top;

int main()
{
	int val;
	top = -1;
	printf("Enter the infix: \n");
	scanf("%s", infix);
	infix_to_postfix();

	printf("Postfix: %s\n", postfix);

	return 0;

}

void infix_to_postfix()
{
	int i , p = 0;
	char next;
	char symbol;
	for (i = 0; i < strlen(infix); i++) {
		symbol = infix[i];

		switch (symbol)
		{
			case '(' :
				push (symbol);
				break;
			case ')' :
				while ( next = pop() != '(') 
					postfix[p++] = next;
				break;
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
				while ( !is_empty() && priority(stack[top]) >= priority(symbol))
					postfix[p++] = pop();
				push (symbol);
				break;
			default:
				postfix[p++] = symbol;
		}
	}
	while (!is_empty())
		postfix[p++] = pop();
	postfix[p] = '\0';

}

int priority(char symbol)
{
	switch (symbol)
	{
		case '(' :
			return 0;
		case '+' :
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
		case '^' :
			return 3;
		default :
			return 0;
	}
}

void push (int symbol)
{
	if (top > MAX) {
		printf("Stack Overflow\n");
	}
	stack[++top] = symbol;
}

int pop()
{
	if (is_empty()) {
		printf("Stack Underflow\n");
	}

	return stack[top--];
}

int is_empty() 
{
	if (top == -1)
		return 1;
	else 
		return 0;
}











