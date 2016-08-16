#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
	struct node *rep;
};

struct node *p[30]={NULL};

void makeset(int x){
	if(p[x]!=NULL){
		printf("Duplicate key\n");
		return;
	}
	struct node *n = (struct  node *)malloc(sizeof(struct node));
	n->key = x;
	n->next = NULL;
	n->rep = n;
	p[x]= n;
}
int findset(int x){
	if(p[x]== NULL){
		return -1;
	}
	struct node *p1 = p[x];
	p1 = p1->rep;
	return p1->key;
}
void union1(int x,int y){
	struct node *x1 = p[x];
	struct node *y1 = p[y];
	if(p[x]==NULL || p[y]==NULL){
		printf("One of the set is Empty\n");
		return;
	}
	if(x1->rep==y1->rep){
		printf("Same set\n");
	}
	else {
		struct node *l1 = x1->rep;
		while(l1->next!=NULL){
			l1 = l1->next;
		}
		l1->next = y1->rep;
		l1 = y1->rep;
		while(l1!=NULL){
			l1->rep = x1->rep;
			l1 = l1->next;
		}
	}
}
void display(int x){
	struct node *p1 = p[x];
	if(p1==NULL) {
		printf("Empty Set\n");
		return;
	}
	p1 = p1->rep;
	while(p1!=NULL){
		printf("%d\t",p1->key);
		p1 = p1->next;
	}
	printf("\n");
}

int main(){
	int a,k,j;
	while(1){
		printf("Enter Choice\n1)Create a Set\n2)Union of two set\n3)Find set of an element\n4)Display the Set\n5)exit\n");
		scanf("%d",&a);
		if(a==5) break;
		switch(a){
			case 1 : scanf("%d",&k);
				 makeset(k);
				 break;
			case 2 : scanf("%d%d",&k,&j);
				 union1(k,j);
				 break;
			case 3 : scanf("%d",&k);
				 int i = findset(k);
				 if(i == -1) printf("Not found\n");
				 else printf("finding %d's set's name %d\n",k,i);
				 break;
			case 4 : scanf("%d",&k);
				 display(k);

		}
	}
	/*
	   makeset(5);
	   makeset(6);
	   union1(5,6);
	   display(5);
	   int a = findset(5);
	   printf("finding 5's repre %d\n",a);*/
	return 0;
}

