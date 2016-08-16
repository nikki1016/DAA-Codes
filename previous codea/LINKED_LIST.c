#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next; 
};
struct node *root;
int ctr = 0;

void *create(int h){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->info = h;
	n->next = NULL;
	if(ctr==0){
		root = n;
		ctr++;
	}
	else {
		struct node *t = root;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next = n;
		ctr++;
	}
}

void display(){
	struct node *t = root;
		while(t->next!=NULL){
			printf("%d->",t->info);
			t = t->next;
		}
		printf("%d\n",t->info);
}
int main()
{
	create(1);
	create(2);	
	create(3);
	create(4);
	display();	
}
