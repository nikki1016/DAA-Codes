#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
	int info;
};
//create,insert,height,delete,min_heap,max_haep,check1(min),check,levels traversed,level order
struct node *root = NULL;
static int size = 1;
int a[64];
int lvl_up = 0;
void level_order(struct node *ptr)
{
	struct node *temp,*q;
	int i, j, num;
	temp = root;
	num = 2;
	while(num < size)
	{
		if(num == 2)
		{
			printf("%d\n",temp->info);
		}
		else {
			temp = root;
			j = 0;
			for(i = 0; i < 64; i++)
			a[i] = 0;
			int b = num -1;
			while (b > 0) {
				a[j++] = b%2;
				b = b/2;
			}
			for (i = j-2; i >= 0; i--) 
			{
				if (a[i] == 1) 
				{
					q = temp;
					temp = temp->rchild;
				}
				else if (a[i] == 0) 
				{
					q = temp;
				 	temp = temp->lchild;
            	    
				}	
			}
			if(a[0] == 0)
			{
				printf("%d\n",q->lchild->info);
			}
			else {
				printf("%d\n",q->rchild->info);
			}
		}
		num++;
	}
}
int height(struct node *r)
{
	int h_l,h_r;
	if(r == NULL)
	{
		return 0;
	}
	h_l = height(r->lchild);
	h_r = height(r->rchild);
	if(h_l >= h_r)
	{
		return 1+h_l;
	}
	else {
		return h_r+1;
	}
}
void create(int k)
{
		lvl_up = 0;
    	struct node *ptr = (struct node *)malloc(sizeof(struct node));
		ptr->info = k;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->parent = NULL;
		root = ptr;
		printf("Level of %d risen by %d\n",k,lvl_up);
		size++;
}
void check(struct node *ptr)
{
	
	int large;
	if(ptr == root)
	{
		return ;
	}
	else if(ptr->parent->info < ptr->info)
	{
		large = ptr->parent->info;
		ptr->parent->info = ptr->info;
		ptr->info = large;
		lvl_up++;
		check(ptr->parent);
	}
}
void check1(struct node *ptr)
{
	int small;
	if(ptr == root)
	{
		return ;
	}
	else if(ptr->parent->info > ptr->info)
	{
		small = ptr->parent->info;
		ptr->parent->info = ptr->info;
		ptr->info = small;
		check1(ptr->parent);
	}
}

void insert(int data)
{
	struct node *n,*temp,*q;
	lvl_up = 0;
	n = (struct node *)malloc(sizeof(struct node));
	int i, j, num;
	temp = root;
	num = size;
	j = 1;
	for(i = 0; i < 64; i++)
		a[i] = 0;
	while (num > 0) {
		a[j++] = num%2;
		num = num/2;
	}
		for (i = j-2; i > 0; i--) 
		{
			if (a[i] == 1) 
			{
				q = temp;
				temp = temp->rchild;
				if (temp == NULL) 
				{
					n->info = data;
					n->rchild = NULL;
					n->lchild = NULL;
					q->rchild = n;
					n->parent = q;
				
				}
			}
			else if (a[i] == 0) 
			{
				q = temp;
			 	temp = temp->lchild;
                if (temp == NULL) 
				{
                    n->info = data;
                    n->rchild = NULL;
                    n->lchild = NULL;
					q->lchild = n;
					n->parent = q;
				}
			}
		}
		size++;
		check(n);		
		printf("Level of %d risen by %d\n",data,lvl_up);
}
void min_heapify(struct node *ptr)
{	int temp;
	struct node *min = ptr;
	if(ptr->rchild ==  NULL && ptr->lchild == NULL)
	{
		return;
	}
	if(ptr->lchild->info < min->info) 
		min = ptr->lchild;
	if(ptr->rchild!= NULL && ptr->rchild->info < min->info) 
		min = ptr->rchild;
	if(min!=ptr){
		temp = ptr->info;
		ptr->info = min->info;
		min->info = temp;
		min_heapify(min);
	}
}
void max_heapify(struct node *ptr)
{	int temp;
	struct node *max = ptr;
	if(ptr->rchild ==  NULL && ptr->lchild == NULL)
	{
		return;
	}
	if(ptr->lchild->info > max->info) 
		max = ptr->lchild;
	if(ptr->rchild!= NULL && ptr->rchild->info > max->info) 
		max = ptr->rchild;
	if(max!=ptr){
		temp = ptr->info;
		ptr->info = max->info;
		max->info = temp;
		max_heapify(max);
	}
}

int delete()
{
	int x = size-1,k = 1,i,item;
	struct node *temp = NULL,*p = NULL;
	temp = root;

	if(root == NULL)
	{
		printf("Empty Heap!!\n");
		return -1;
	}
	else{
	
		item = root->info;
		if(x==1){
			free(root);
			root = NULL;
			size = 1;
		}
		while(x > 0)
		{
			a[k++] = x%2;
			x = x/2;	
		}
		for(i = k-2; i > 0; i--)
		{
			if(a[i] == 1)
			{
				p = temp;
				temp = temp->rchild;
			}
			else if(a[i] == 0)
			{
				p = temp;
				temp = temp->lchild;
			}
			if(i == 1)
			{
				if(a[i] == 1)
				{
					root->info = p->rchild->info;
					temp = p->rchild;
					p->rchild = NULL;
					free(temp);
					size--;
				}
				else if(a[i] == 0)
				{
					root->info = p->lchild->info;
					temp = p->lchild;
					p->lchild = NULL;
					free(temp);
					size--;
				}
			}
			max_heapify(root);
		}
	}
	return item;
}
void postorder(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d\n",ptr->info);
}
void inorder(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	inorder(ptr->lchild);
	printf("%d\n",ptr->info);
	inorder(ptr->rchild);
}
void preorder(struct node *ptr)
{

	if (ptr == NULL)
		return;

	printf("%d\n", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

int main()
{
	int h, a, i;
	create(4);
	insert(1);
	insert(3);
	insert(2);
	insert(16);
	insert(9);
	insert(10);
	insert(14);
	insert(8);
	insert(7);
	printf("\n");
	printf("\n");
	printf("Preorder is\n");
	preorder(root);
	printf("Inorder is\n");
	inorder(root);
	printf("Levelorder is\n");
	level_order(root);
	printf("Postorder is\n");
	postorder(root);
	printf("Height is %d\n",height(root));
	//h = size;
	//for (i = 0;i < h-1; i++) {
	//	a = delete();
	//	printf("%d\n", a);
	//}
	//preorder(root);
	return 0;
}


