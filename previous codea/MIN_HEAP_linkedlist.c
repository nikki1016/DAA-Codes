#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
int val;
struct node *lchild;
struct node *rchild;
struct node *parent;
int n1;
int n2;
};

struct node *root=NULL;
int nodes = 0;
int a[33];

void check(struct node *n) {
	int t;
	if(n==root) return;
	if(n->parent->val > n->val) {
	t= n->parent->val;
	n->parent->val = n->val;
	n->val = t;
	t= n->parent->n1;
	n->parent->n1 = n->n1;
	n->n1 = t;
	t= n->parent->n2;
	n->parent->n2 = n->n2;
	n->n2 = t;
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

void createnode(int value,int node1,int node2) {
struct node *n = (struct node *)malloc(sizeof(struct node));
n->val = value;
n->lchild = NULL;
n->rchild = NULL;
n->parent = NULL;
n->n1 = node1;
n->n2 = node2;
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
	struct node *small = n;
	int temp;
	if(n->lchild->val < n->val) small = n->lchild;
	if((n->rchild!=NULL) && (small->val > n->rchild->val)) small = n->rchild;
	if(small!=n) {
		temp = small->val;
		small->val = n->val;
		n->val = temp;
		temp = small->n1;
		small->n1 = n->n1;
		n->n1 = n1;
		temp = small->n2;
		small->n2 = n->n2;
		n->n2 = n2;
		maxify(small);
	}
}

struct node *del() {
	if(root==NULL){
		printf("Empty heap\n");
		return -1;
	}
	int item = root->val;
	printf("Deleted value %d\n",root->val);
	int l = getbinary();
	struct node *t= root;
	struct node *parent = NULL;
	int i,temp;
	if(l==1){
	//	free(root);
		root = NULL;
		nodes = 0;
		return t;
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
			temp = parent->lchild->n1;
			parent->lchild->n1 = root->n1;
			root->n1 = temp;
			temp = parent->lchild->n2;
			parent->lchild->n2 = root->n2;
			root->n2 = temp;
			
			t = parent->lchild;
			parent->lchild = NULL;
			maxify(root);
	}
	else {
		temp = parent->rchild->val;
		parent->rchild->val = root->val;
		root->val = temp;
		temp = parent->rchild->n1;
		parent->rchild->n1 = root->n1;
		root->n1 = temp;
		temp = parent->rchild->n2;
		parent->rchild->n2 = root->n2;
		root->n2 = temp;
		t = parent->rchild;
		parent->rchild = NULL;
		maxify(root);
	}
	//free(t);
	nodes--;
	return t;
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
int a[n];
for(i=0;i<n;i++){
a[i]= del();
printf("\n");	
}
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}
