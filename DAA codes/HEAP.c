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

void check(struct node *n) {
	int t;
	if(n==root) return;
	if(n->parent->val < n->val) {
	t= n->parent->val;
	n->parent->val = n->val;
	n->val = t;
	check(n->parent);
	}
}

int getbinary() {
memset(a,0,sizeof(a));
if(nodes == 0) return 0;
int n = nodes,i = 0;
while(n!=0){
a[i]=n%2;
n=n/2;
i++;
}
return i;
}

void createnode(int value) {
struct node *n = (struct node *)malloc(sizeof(struct node));
n->val = value;
n->lchild = NULL;
n->rchild = NULL;
n->parent = NULL;
nodes++;
if(nodes == 1) {
root = n;
//printf("Root node created\n");
}
else {
struct node *t = root;
struct node *parent = NULL; 
int l = getbinary();
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
}
}


void inorder(struct node *n){
if(n == NULL)
return;
inorder(n->lchild);
printf("%d \t",n->val);
inorder(n->rchild);
}
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

void delete() {
	if(root==NULL){
		printf("Empty heap\n");
		return;
	}
	printf("Deleted value %d\n",root->val);
	int l = getbinary();
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
//	if(t==NULL) printf("hi\n");	
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
createnode(5);
createnode(7);
createnode(9);
createnode(10);
createnode(17);
createnode(19);
createnode(2);
inorder(root);
printf("\n");
int n = nodes;
for(i=0;i<=n;i++){
delete();
//inorder(root);
printf("\n");	
}
return 0;
}
