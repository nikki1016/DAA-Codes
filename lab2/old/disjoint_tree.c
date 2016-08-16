#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *parent;
};

struct node *p[30]={NULL};

void makeset(int x){
	if(p[x]!=NULL){
		printf("Duplicate key\n");
		return;
	}
	struct node *n = (struct  node *)malloc(sizeof(struct node));
	n->key = x;
	//	n->next = NULL;
	n->parent = n;
	p[x]= n;
}

int findset(int x){
	if(p[x]== NULL){
		return -1;
	}
	struct node *n = p[x];
	while(n->parent!=n) {
		n = n->parent;
	}
	return n->key;
}
void union1(int x,int y) {
	struct node *x1 = p[x];
	struct node *y1 = p[y];
	if(p[x]==NULL || p[y]==NULL){
		printf("One of the set is Empty\n");
		return;
	}
	while(x1->parent!=x1)
		x1 = x1->parent;
	while(y1->parent!=y1)
		y1 = y1->parent;
	if(x1 == y1){
		printf("Same set\n");
	}
	else {
		y1->parent = x1;
	}
}
void display(int x){
	struct node *a = p[x];
	if(p[x]==NULL) {
		printf("Not a member of any set\n");
		return;
	}
	int k = findset(x);
	int i,j;
	struct node *b = NULL;
	for(i=0;i<30;i++){
		if(p[i]!=NULL){
			b = p[i];
			j = b->key;
			if(findset(j)==k)
				printf("%d\t",j);
		}	
	}
	printf("\n");
}

int main()
{
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
}

