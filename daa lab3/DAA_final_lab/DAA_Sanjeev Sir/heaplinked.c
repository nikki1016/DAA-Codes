#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
	int info;
};

struct node *root = NULL;
int c = 0;
int a[64];

void preorder(struct node *ptr);

void create(int data)
{
	struct node *temp, *ptr, *q;
	int i, j, num;

	if (c == 0) {
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->info = data;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->parent = NULL;
		root = ptr;
		c = 1;
		printf("Root node created!\n");
	}
	else {  
		c++;
		temp = root;
		num = c;
		j = 0;
		memset(a,0,sizeof(a));
		while (num > 0) {
			a[j++] = num%2;
			num = num/2;
		}

		for (i = j-2; i >= 0; i--) {
			if (a[i] == 1) {
				q = temp;
				temp = temp->rchild;
				if (temp == NULL) {
					struct node *new;
					new = (struct node *)malloc(sizeof(struct node));
					new->info = data;
					new->rchild = NULL;
					new->lchild = NULL;
					q->rchild = new;
					new->parent = q;
					printf("node created %d with parent %d\n",new->info,new->parent->info);
				}
			}
			else if (a[i] == 0) {
				q = temp;
				temp = temp->lchild;
                if (temp == NULL) {
                    struct node *new;
                    new = (struct node *)malloc(sizeof(struct node));
                    new->info = data;
                    new->rchild = NULL;
                    new->lchild = NULL;
					q->lchild = new;
					new->parent = q;
					printf("node created %d with parent %d\n",new->info,new->parent->info);

                }
			}
		}
		
	}

	return;
 
}

/*void max_heapify(struct node *root)
{
	int large;

	if ( ptr->lchild->info > ptr->info) { 
		large = 1;
	}
	else
		large = ptr->index;

	if (ptr->rchild->info > ptr->info) {
		if (ptr->rchild->info > ptr->lchild->info)
			large = 0;
		else
			large = 1;
	}

	if (large != ptr->index) {
		if (large == 1){
			temp = ptr->info;
			ptr->info = ptr->lchild->info;
			ptr->lchild->info = temp;
			max_heapify(ptr->lchild);
		}
		else if (large == 0) {
			temp = ptr->info;
			ptr->info = ptr->rchild->info;
			ptr->rchild->info = temp;
			max_heapify(ptr->rchild);
		}

	}
}*/


int main()
{
	create(7);
	create(5);
	create(6);
	create(10);
	create(2);
	preorder(root);
	printf("\n");
	return 0;
}

void preorder(struct node *ptr)
{
//	struct node *ptr = root;

	if (ptr == NULL)
		return;

	printf("%d\n", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}
