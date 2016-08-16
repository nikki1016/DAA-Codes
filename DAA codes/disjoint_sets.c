#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *rep;
};

struct node *a[50]= {NULL};
void make_set(int x);
int find_set(int item);
void union_set(int x, int y);
void display(int num);

int main()
{
	int num, num1, num2, c;
	while (1) {
		printf("1. Make Set\n 2. Find Set\n 3. Union of Sets\n 4. Display\n 5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		switch(c) {
			case 1:
				scanf("%d", &num);
				make_set(num);
				break;
			case 2:
				scanf("%d", &num1);
				num2 = find_set(num1);
				printf("%d found\n", num2);
				break;
			case 3:
				scanf("%d%d", &num1, &num2);
				union_set(num1, num2);
				break;
			case 4:
				scanf("%d", &num);
				display(num);
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}
	}

	return 0;			


}

void make_set(int x) {
	struct node * n = NULL;
	n = (struct node *)malloc(sizeof(struct node));
	n->data = x;
	n->next = NULL;
	n->rep = n;
	a[x] = n;
}

int find_set(int item)
{
	struct node *ptr = a[item];
	if (a[item] == NULL)
		return -1;
	else 
		return (ptr->rep->data);
}

void union_set(int x, int y)
{
	struct node *p = a[x];
	struct node *b = NULL;
	struct node *q = a[y];
	if (p == NULL || q == NULL)
		return;
	if (p->rep == q->rep)
		return;
	else {  p = p->rep;
		q = q->rep;
		b = q;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
		q = q->next;
		while (q!= NULL) {
			q->rep = b;
			q = q->next;
		}		
//		q->next = p;
	}
	return;
}

void display(int num) {
	struct node *ptr = a[num];
	if(ptr == NULL) return;
	ptr = ptr->rep;
	while (ptr != NULL) {
		printf("%d  ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	return ;
}








