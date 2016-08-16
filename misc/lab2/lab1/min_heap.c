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
void check(struct node *ptr);
void inorder(struct node *ptr);
void max_heapify(struct node *ptr);

void create(int data)
{
	struct node *temp, *ptr, *q;
	int i, j, num;
	
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info = data;
	new->lchild = NULL;
	new->rchild = NULL;
	new->parent = NULL;
	
	if (root == NULL) {
		root = new;
		c++;
	}
	else {  
		c++;
		temp = root;
		num = c;
		j = 0;
	
		while (num > 0) {
			a[j++] = num%2;
			num = num/2;
		}
		for (i = j-2; i >= 0; i--) {
			if (a[i] == 1) {
				q = temp;
				temp = temp->rchild;
				if (temp == NULL) {
					q->rchild = new;
					new->parent = q;
					check(new);		
				}
			}
			else if (a[i] == 0) {
				q = temp;
				temp = temp->lchild;
                if (temp == NULL) {
					q->lchild = new;
					new->parent = q;
					check(new);
            	}
			}
		}
	}
	return;
}

void check(struct node *ptr)
{
	int temp;	
	if (ptr == root) 
		return;
		
	if (ptr->parent->info > ptr->info)	{
		temp = ptr->info;
		ptr->info = ptr->parent->info;
		ptr->parent->info = temp;
		check(ptr->parent);
	}	
}

int delete()
{
	struct node *q = NULL, *temp = NULL;
	int i, j, num,item;
	if (root == NULL){
		printf("Empty Heap\n");
		return -1;
	}		
	else {
		item = root->info;	
		//printf("Deleted Value: %d\n", root->info);
		temp = root;
		num = c;
		j = 0;
		while (num > 0) {
			a[j++] = num%2;
			num = num/2;
		}
		
		if (j == 1) {
			free(root);
			root = NULL;
			c = 0;
		}
		else {
			for (i = j-2; i >= 0; i--) {
				q = temp;
				if (a[i] == 1) temp = temp->rchild;
				else temp = temp->lchild;
			}
			if(a[0] ==0){
				root->info = q->lchild->info;
				temp = q->lchild;
				q->lchild = NULL;
				free(temp);
				c--;
			}
			else {
				root->info = q->rchild->info;
				temp = q->rchild;
				q->rchild = NULL;
				free(temp);
				c--;
			}	
			max_heapify(root);		
		}
	}
	return item;		
}

void max_heapify(struct node *ptr)
{
	struct node *large = NULL;
	int temp;
	
	if (ptr->lchild == NULL && ptr->rchild == NULL) 
		return;
		
	if (ptr->lchild->info < ptr->info) 
		large = ptr->lchild;
	else
		large = ptr;
	if (ptr->rchild!=NULL && ptr->rchild->info < large->info)
		large = ptr->rchild;
		
	if (large != ptr) {
		temp = ptr->info;
		ptr->info = large->info;
		large->info = temp;
		max_heapify(large);
	}			
}
 
int main()
{
	int i, h, a = 0;
	create(7);
	create(5);
	create(6);
	create(10);
	create(2);
	create(53);
//	preorder(root);
//	printf("\n");
	inorder(root);
	printf("\n");
	h = c;
	for (i = 0; i < h; i++) {
		a = delete();
		printf("%d	", a);
	}
	printf("\n");
	return 0;
}

void preorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	printf("%d\n", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	inorder(ptr->lchild);
	printf("%d\n", ptr->info);
	inorder(ptr->rchild);
}


