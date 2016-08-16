#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *insert(struct node *ptr, int key);
struct node *remove(struct node *ptr, int key);
struct node *search(struct node *ptr, int key);
struct node *min(struct node *ptr);
struct node *max(struct node *ptr);
int height(struct node *ptr);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);

int main()
{
	int key, ch, h;
	struct node *root = NULL;
	struct node *ptr = NULL;
	
	while (1) {
		printf(" 1. Insert\n 2. Search\n 3. Delete\n 4. Minimum Element\n 5. Maximum Element\n 6. Preorder\n 7. Inorder\n 8. Postorder\n 9. Height\n 10.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				printf("Enter the value to be inserted: ");
				scanf("%d", &key);
				root = insert(root, key);
				break;
			case 2:
				printf("Enter the key to be searched: ");
				scanf("%d", &key);
				ptr = search(root, key);
				if (ptr == NULL) {
					printf("Key not found\n");
				}
				else 
				printf("Key Present\n");
				break;
			case 3:
				printf("Enter the key to be deleted: ");
				scanf("%d", &key);
				root = remove(root, key);
				break;
			case 4:
				ptr = min(root);
				printf("Minimum Element is: %d\n", ptr->info);
				break;
			case 5:
				ptr = max(root);
				printf("Maximum Element is: %d\n", ptr->info);
				break;
			case 6:
				preorder(root);
				break;
			case 7:
				inorder(root);
				break;
			case 8:
				postorder(root);
				break;
			case 9:
				h =height(root);
				printf("Height of the tree is: %d\n", h);
				break;
			case 10:
				exit(1);	
			deafult:
				printf("Wrong Choice\n");
				break;
		}
	}
	
	return 0;	
}

struct node *insert(struct node *ptr, int key)
{
	
	if (ptr == NULL) {
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->info = key;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if (key < ptr->info)
		ptr->lchild = insert(ptr->lchild, key);
	else if (key > ptr->info)
		ptr->rchild = insert(ptr->rchild, key);
	else
		printf("Duplicate key\n");
	
	return ptr;
}

struct node *remove(struct node *ptr, int key)
{
	struct node *temp, *suc;
	
	if (ptr == NULL) {
		printf("Key not found\n");
		return ptr;
	}
	else
	{
		if (ptr->lchild != NULL && ptr->rchild != NULL) {
			suc = ptr->rchild;
			while (suc->lchild != NULL)
				suc = suc->lchild;
			ptr->info = suc->info;
			ptr->rchild = remove(ptr->rchild, suc->info);
		}
		else
		{
			temp = ptr;
			if (ptr->lchild != NULL)
			ptr = ptr->lchild;
			else if (ptr->rchild != NULL)
			ptr = ptr->rchild;
			else
			ptr = NULL;
			
			free(temp);
		}
	}
	
	return ptr;
}

struct node *search(struct node *ptr, int key)
{
	while (ptr != NULL) {
		if (key < ptr->info)
		ptr = ptr->lchild;
		else if (key > ptr->info)
		ptr = ptr->rchild;
		else 
		return ptr; 	
	}
	
	return NULL;
}

struct node *min(struct node *ptr)
{
	if (ptr != NULL) {
		while (ptr->lchild != NULL)
		ptr = ptr->lchild;
	}
	
	return ptr;
}

struct node *max(struct node *ptr)
{
	if (ptr != NULL) {
		while (ptr->rchild != NULL)
		ptr = ptr->rchild;
	}
	
	return ptr;
}

int height(struct node *ptr)
{
	int hleft, hright;
	if (ptr == NULL)
	return 0;
	
	hleft = height(ptr->lchild);
	hright= height(ptr->rchild);
	
	if (hleft > hright)
		return 1+hleft;
	else
		return 1+hright;
}

void preorder(struct node *ptr)
{
	if (ptr == NULL)
		return;
	printf("%d \n", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
	if (ptr == NULL)
		return;
	inorder(ptr->lchild);
	printf("%d \n", ptr->info);
	inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
	if (ptr == NULL)
		return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d \n", ptr->info);
}


