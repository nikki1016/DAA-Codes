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
int ctr = 0;
//descending order, level rose, height, level order traversal
void preorder(struct node *ptr);
void check(struct node *ptr);
void inorder(struct node *ptr);
void max_heapify(struct node *ptr);
int height(struct node *ptr);
void levelorder(struct node *ptr);

void create(int data)
{
	struct node *temp, *ptr, *q;
	int i, j, num;
	 ctr = 0;
	
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
		new->info = data;
		new->lchild = NULL;
		new->rchild = NULL;
		new->parent = NULL;
	if (root == NULL) {
		printf("Level rose of %d =  %d\n", data, ctr);
		root = new;
		c++;
	}
	else {  
		c++;
		temp = root;
		num = c;
		j = 0;
		//memset(a,0,sizeof(a));
		while (num > 0) {
			a[j++] = num%2;
			num = num/2;
		}
	//	printf("length of %d=%d\n",c,j);

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
		printf("Level of %d  risen by =  %d\n", data, ctr);
	}
		
	return;
}

void check(struct node *ptr)
{
	int temp;	
	if (ptr == root) 
		return;
		
	if (ptr->parent->info < ptr->info)	{
		temp = ptr->info;
		ptr->info = ptr->parent->info;
		ptr->parent->info = temp;
		ctr++;
		check(ptr->parent);
	}
	
}

void delete()
{
	struct node *q = NULL, *temp = NULL;
	int i, j, num;
	if (root == NULL){
		printf("Empty Heap\n");
	}		
	else {
		printf("Deleted Value: %d\n", root->info);
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
		
}

int main()
{
	int i, h;
	
	create(14);
	create(1);
	create(3);
	create(2);
	create(16);
	create(9);
	create(10);
	create(14);
	create(8);
	create(7);
	
	printf("Preorder Traversal: \n");
	preorder(root);
	printf("\n");
	printf("Inorder Traversal: \n");
	inorder(root);
	printf("\n");
	printf("Postorder Traversal: \n");
	postorder(root);
	printf("\n");
	printf("Levelorder Traversal: \n");
	levelorder(root);
	printf("\n");
	
	printf("Height of the Tree: %d\n", height(root));
	/*h = c;
	for (i = 0; i <= h; i++) {
		delete();
		inorder(root);
	}*/
	return 0;
}

void preorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	printf("%d ", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	inorder(ptr->lchild);
	printf("%d ", ptr->info);
	inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d ", ptr->info);
}

void levelorder(struct node *ptr)
{
	struct node *q = NULL, *temp = NULL;
	int i, j, num;
	temp = root;
	num = 1;
	while(num <= c){
		j = 0;
		int b = num;
		while (b > 0) {
			a[j++] = b%2;
			b = b/2;
		}
		if (j == 1) {
			printf("%d ", root->info);
		}
		else {
			temp = root;
			for (i = j-2; i >= 0; i--) {
				q = temp;
				if (a[i] == 1) 
					temp = temp->rchild;
				else 
					temp = temp->lchild;
			}
		//printf("%d\t",temp->info);
		if (a[0] == 0)
			printf("%d ", q->lchild->info);
		else 
			printf("%d ", q->rchild->info);	
		}
		num++;
	}	
}
 
void max_heapify(struct node *ptr)
{
	struct node *large = NULL;
	int temp;
	
	if (ptr->lchild == NULL && ptr->rchild == NULL) 
		return;
		
	if (ptr->lchild->info > ptr->info) 
		large = ptr->lchild;
	else
		large = ptr;
	if (ptr->rchild!=NULL && ptr->rchild->info > large->info)
		large = ptr->rchild;
		
	if (large != ptr) {
		temp = ptr->info;
		ptr->info = large->info;
		large->info = temp;
		max_heapify(large);
	}			
}

int height(struct node *ptr) {
	int h_left, h_right;
	if (ptr == NULL)
		return 0;
	
	h_left = height(ptr->lchild);
	h_right = height(ptr->rchild); 
	
	if (h_left > h_right) 
		return 1+h_left;
	else
		return 1+h_right;
		
} 
