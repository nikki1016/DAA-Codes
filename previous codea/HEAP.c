#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
int val;
struct node *lchild;
struct node *rchild;
struct node *parent;
};

struct node *root=NULL;
int nodes = 0;
int a[33];
int ctr;
//create,descensing order,delete,levels traversed,heapify,height,inorder,preorder,postorder,level order traversal
void check(struct node *n) {
	int t;
	if(n==root) return;
	if(n->parent->val < n->val) {
	t= n->parent->val;
	n->parent->val = n->val;
	n->val = t;
	ctr++;
	check(n->parent);
	}
}

int getbinary(int temp) {
memset(a,0,sizeof(a));
if(temp == 0) return 0;
int n = temp,i = 0;
while(n!=0){
a[i]=n%2;
n=n/2;
i++;
}
return i;
}
//find the height
int height(struct node *ptr){
	int h_left,h_right;
	if(ptr == NULL) return 0;
	h_left = height(ptr->lchild);
	h_right = height(ptr->rchild);
	if(h_left>=h_right) return 1+ h_left;
	else return 1 + h_right;
}

void createnode(int value) {
	ctr = 0;
struct node *n = (struct node *)malloc(sizeof(struct node));
n->val = value;
n->lchild = NULL;
n->rchild = NULL;
n->parent = NULL;
nodes++;
if(nodes == 1) {
printf("Levels key rose up %d = %d\n",value,ctr); 
root = n;

//printf("Root node created\n");
}
else {
struct node *t = root;
struct node *parent = NULL; 
int l = getbinary(nodes);
int i;
for(i=l-2;i>=0;i--){
	parent = t;
	if(a[i]==0) 
		t =t->lchild;
	else
		t= t->rchild;
		if(t==NULL){
			if(a[i]==0) parent->lchild = n;
			else parent->rchild = n;
			n->parent = parent;
			check(n);
			//printf("Node created %d with parent %d\n",n->val,n->parent->val);
		} 
}

printf("Levels key rose up %d = %d\n",value,ctr); 
}
}
void level_order()
{
	int temp = 1;
	while(temp<=nodes){
	struct node *t = root;
	struct node *parent = NULL; 
	int l = getbinary(temp);
	int i;
	if(l==1) printf("%d\t",root->val);
	else {
		for(i=l-2;i>=0;i--){
		parent = t;
		if(a[i]==0) 
			t =t->lchild;
		else
			t= t->rchild;	
	}
//	printf("%d\n",t->val);
	if(a[0]==0)
	printf("%d\t",parent->lchild->val);
	else 
	printf("%d\t",parent->rchild->val);
	}	
	temp++;
	}	
}

//inorder
void inorder(struct node *n){
if(n == NULL)
return;
inorder(n->lchild);
printf("%d \t",n->val);
inorder(n->rchild);
}
//postorder
void postorder(struct node *n){
if(n == NULL)
return;
postorder(n->lchild);
postorder(n->rchild);
printf("%d \t",n->val);
}
//preorder
void preorder(struct node *n){
if(n == NULL)
return;
printf("%d \t",n->val);
preorder(n->lchild);
preorder(n->rchild);
}
//delete
void maxify(struct node *n)
{
	if(n->lchild==NULL && n->rchild== NULL) return;
	struct node *large = n;
	int temp;
	if(n->lchild->val > n->val) large = n->lchild;
	if((n->rchild!=NULL) && (large->val < n->rchild->val)) large = n->rchild;
	if(large!=n) {
		temp = large->val;
		large->val = n->val;
		n->val = temp;
		maxify(large);
	}
}
//DELETE
void delete() {
	if(root==NULL){
		printf("Empty heap\n");
		return;
	}
	printf("Deleted value %d\n",root->val);
	int l = getbinary(nodes);
	struct node *t= root;
	struct node *parent = NULL;
	int i,temp;
	if(l==1){
		free(root);
		root = NULL;
		nodes = 0;
		return;
	}
	for(i=l-2;i>=0;i--){
		parent = t;
		if(a[i]==0) t =t->lchild;
		else t= t->rchild;
	}
	//if(t==NULL) printf("hi\n");	
	if(a[0]==0) {
			temp = parent->lchild->val;
			parent->lchild->val = root->val;
			root->val = temp;
			t = parent->lchild;
			parent->lchild = NULL;
			maxify(root);
	}
	else {
		temp = parent->rchild->val;
		parent->rchild->val = root->val;
		root->val = temp;
		t = parent->rchild;
		parent->rchild = NULL;
		maxify(root);
	}
	free(t);
	nodes--;
}


int main()
{int i;
createnode(4);
createnode(1);
createnode(3);
createnode(2);
createnode(16);
createnode(9);
createnode(10);
createnode(14);
createnode(8);
createnode(7);
printf("InOrder traversal of the heap created\n");
inorder(root);
printf("Preorder traversal of the heap created\n");
preorder(root);
printf("Postorder traversal of the heap created\n");
postorder(root);
printf("LevelOrder traversal of the heap created\n");
level_order();
printf("\n");
printf("Height of the heap created = %d\n",height(root));
int n = nodes;
for(i=0;i<=n;i++){
delete();
//inorder(root);
printf("\n");	
}
return 0;
}
