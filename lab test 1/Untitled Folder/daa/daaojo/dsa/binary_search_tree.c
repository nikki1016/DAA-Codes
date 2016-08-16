#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node *lchild;
	struct node *rchild;
	int info;
};

struct node *search (struct node *ptr, int skey);
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int dkey);
struct node *min(struct node *ptr);
struct node *max(struct node *ptr);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
int height(struct node *ptr);

/*struct node *construct(int data) {

	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info = data;
	
	new->lchild = NULL;
	new->rchild = NULL;

	return new;
}*/

int main()
{
	struct node *root = NULL;
	struct node *ptr;

	int ch, k;

	while (1) {
		printf("\n1. Search\n 2. Insert\n 3. delete\n 4. Preoder Traversal\n 5. Inorder Traversal\n 6. Postorder Traversal\n");
		printf(" 7. Height of the Tree\n 8. Find Mininmum and Maximum\n 9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				printf("Enter the key to be searched: ");
				scanf("%d", &k);
				ptr = search(root, k);

				if (ptr == NULL)
					printf("Key not present\n");
				else 
					printf("Key present\n");
				
				break;
			case 2:
				printf("Enter the key to be inserted: ");
				scanf("%d", &k);
				root = insert (root, k);
				break;
			case 3:
				printf("Enter the kry to be deleted: ");
				scanf("%d", &k);
				root = del(root, k);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				postorder(root);
				break;
			case 7:
				printf("Height of the tree %d\n :", height(root));
				break;
			case 8:
				ptr = min(root);
				if (ptr != NULL) 
					printf("Minmum key found at : %d\n", ptr->info);
				
				ptr = max(root);
				if (ptr != NULL)
					printf("Maximum key found at : %d\n", ptr->info);
				break;
			case 9:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}

	return 0;
}

struct node *search(struct node *root, int skey) 
{
	struct node *ptr;
	ptr = root;

	while (ptr != NULL) {
		if (skey < ptr->info) {
			ptr = ptr->lchild;
		}
		else if (skey > ptr->info) 
			ptr = ptr ->rchild;
		else 
			return ptr;
	}

	return NULL;
}

struct node *insert(struct node *root, int ikey)
{
	struct node *ptr, *par;
	ptr = root;
	par = NULL;

	while (ptr != NULL) {
		par = ptr;

		if (ikey < ptr->info) 
			ptr = ptr->lchild;

		else if (ikey > ptr->info) 
			ptr = ptr->rchild;
		else {
			printf("Duplicate key\n");
			return root;
		}
	}

	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info = ikey;
	new->lchild = NULL;
	new->rchild = NULL;

	if (par == NULL)
		root = new;

	else if (ikey < par->info)
		par->lchild = new;
	else
		par->rchild = new;

	return root;

}

struct node *del(struct node *root, int dkey)
{
	struct node *ptr, *temp, *succ;

	ptr = root;

	if (ptr == NULL)
		printf("key not found\n");

	if (dkey < ptr->info) 
	       ptr->lchild = del(ptr->lchild, dkey);

	if (dkey > ptr->info)
		ptr->rchild = del(ptr->rchild, dkey);
	
	else {
		if (ptr->lchild != NULL && ptr->rchild != NULL) {
			succ = ptr->rchild;
			while (succ->lchild != NULL) 
				succ = succ->lchild;

			ptr->info = succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}

			else{
				temp = ptr;
				if (ptr->lchild = NULL)
					ptr = ptr->lchild;
				else if (ptr->rchild = NULL)
					ptr = ptr->rchild;
				else 
					ptr = NULL;
				free (temp);
			}
		}
	return ptr;
}

struct node *min(struct node *root)
{
	struct node *ptr;
	ptr = root;

	if (ptr != NULL ) {
		while (ptr->lchild != NULL) 
			ptr = ptr->lchild;
	}

	return ptr;
}


struct node *max(struct node *root) 
{
	struct node *ptr;
	ptr = root;

	if (ptr != NULL) {
		while (ptr->rchild != NULL)
			ptr = ptr->rchild;
	}

	return ptr;
}

int height(struct node *root)
{
	struct node *ptr;
	ptr = root;

	int l_height, r_height;

	if (ptr == NULL)
		return 0;

	l_height = height(ptr->lchild);
	r_height = height(ptr->rchild);

	if (l_height > r_height)
		return l_height + 1;
	else 
		return r_height + 1;

}

void preorder(struct node *root)
{
	struct node *ptr;
	ptr = root;

	if (ptr == NULL)
		return ;

	printf("%d\n", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node *root)
{
	struct node *ptr;
	ptr = root;

	if (ptr == NULL)
		return;

	inorder(ptr->lchild);
	printf("%d\n", ptr->info);
	inorder(ptr->rchild);

}

void postorder(struct node *root)
{
	struct node *ptr;
	ptr = root;

	if (ptr == NULL)
		return;

	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d\n", ptr->info);
}

